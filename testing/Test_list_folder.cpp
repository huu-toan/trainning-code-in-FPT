#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <dirent.h>
#endif

std::vector<std::string> get_files_in_directory(const std::string& directory) {
    std::vector<std::string> files;
#ifdef _WIN32
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((directory + "/*").c_str(), &findFileData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                std::string filename = findFileData.cFileName;
                size_t lastDot = filename.find_last_of(".");
                if (lastDot != std::string::npos) {
                    files.push_back(filename.substr(0, lastDot));
                } else {
                    files.push_back(filename);
                }
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }
#else
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                std::string filename = ent->d_name;
                size_t lastDot = filename.find_last_of(".");
                if (lastDot != std::string::npos) {
                    files.push_back(filename.substr(0, lastDot));
                } else {
                    files.push_back(filename);
                }
            }
        }
        closedir(dir);
    }
#endif
    return files;
}

int main() {
    std::string directory = "C:/Users/vanpe/Desktop/music";
    std::vector<std::string> files = get_files_in_directory(directory);
    for (const auto& file : files) {
        std::cout << file << std::endl;
    }
    return 0;
}
