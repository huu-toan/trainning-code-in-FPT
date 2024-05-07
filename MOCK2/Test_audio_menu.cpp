#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <dirent.h>
#include <sys/stat.h>
#endif

// Khai báo tiên lượng cho hàm getFilesInDirectory
std::vector<std::string> getFilesInDirectory(const std::string& directory);

// Định nghĩa class Playlist và các chức năng của nó
class Playlist {
private:
    std::string name;
    std::vector<std::string> songs;

public:
    Playlist(const std::string& playlistName) : name(playlistName) {}

    void addSong(const std::string& songName) {
        songs.push_back(songName);
    }

    void displaySongs() const {
        std::cout << "\nPlaylist: " << name << std::endl;
        for (const auto& song : songs) {
            std::cout << song << std::endl;
        }
    }

    const std::string& getName() const {
        return name;
    }
};

// Định nghĩa class MediaManager và các chức năng của nó
class MediaManager {
private:
    std::string filePath;
    std::vector<Playlist> playlists;

public:
    void createPlaylist(const std::string& playlistName) {
        playlists.emplace_back(playlistName);
#ifdef _WIN32
        std::string directory = ".\\" + playlistName;
        if (_mkdir(directory.c_str()) == 0) {
            std::cout << "Playlist '" << playlistName << "' created successfully." << std::endl;
        } else {
            std::cerr << "Error creating playlist '" << playlistName << "'." << std::endl;
        }
#else
        std::string directory = "./" + playlistName;
        if (mkdir(directory.c_str(), 0777) == 0) {
            std::cout << "Playlist '" << playlistName << "' created successfully." << std::endl;
        } else {
            std::cerr << "Error creating playlist '" << playlistName << "'." << std::endl;
        }
#endif
    }

    void displayPlaylists() const {
        std::cout << "\nAvailable Playlists:" << std::endl;
        for (const auto& playlist : playlists) {
            std::cout << playlist.getName() << std::endl;
        }
    }

    void displayPlaylistSongs(const std::string& playlistName) const {
        for (const auto& playlist : playlists) {
            if (playlist.getName() == playlistName) {
                std::string directory = "./" + playlistName;
                std::vector<std::string> files = getFilesInDirectory(directory);
                if (!files.empty()) {
                    std::cout << "\nSongs in Playlist '" << playlistName << "':" << std::endl;
                    for (const auto& file : files) {
                        std::cout << file << std::endl;
                    }
                } else {
                    std::cout << "No songs found in Playlist '" << playlistName << "'." << std::endl;
                }
                return;
            }
        }
        std::cout << "Playlist not found!" << std::endl;
    }

    void addSongToPlaylist(const std::string& playlistName, const std::string& songName) {
        for (auto& playlist : playlists) {
            if (playlist.getName() == playlistName) {
                playlist.addSong(songName);
                return;
            }
        }
        std::cout << "Playlist not found!" << std::endl;
    }
};

// Hàm hiển thị danh sách file trong thư mục
std::vector<std::string> getFilesInDirectory(const std::string& directory) {
    std::vector<std::string> files;
#ifdef _WIN32
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((directory + "/*").c_str(), &findFileData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                files.push_back(findFileData.cFileName);
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
                files.push_back(ent->d_name);
            }
        }
        closedir(dir);
    }
#endif
    return files;
}

int main() {
    MediaManager manager;

    // Thêm các playlist mẫu
    manager.createPlaylist("Favorites");
    manager.createPlaylist("Rock");
    manager.createPlaylist("Pop");

    int option;
    do {
        std::cout << "\n\n *****MAIN MENU *****";
        std::cout << "\n 1: Display available playlists";
        std::cout << "\n 2: Display songs in a playlist";
        std::cout << "\n 3: Add song to a playlist";
        std::cout << "\n 4: EXIT";
        std::cout << "\n\n Enter your option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                manager.displayPlaylists();
                break;
            case 2: {
                std::string playlistName;
                std::cout << "\nEnter playlist name: ";
                std::cin >> playlistName;
                manager.displayPlaylistSongs(playlistName);
                break;
            }
            case 3: {
                std::string playlistName, songName;
                std::cout << "\nEnter playlist name: ";
                std::cin >> playlistName;
                std::cout << "Enter song name: ";
                std::cin >> songName;
                manager.addSongToPlaylist(playlistName, songName);
                break;
            }
            case 4:
                std::cout << "\nExiting program." << std::endl;
                break;
            default:
                std::cout << "\nInvalid option. Please try again." << std::endl;
        }
    } while (option != 4);

    return 0;
}
