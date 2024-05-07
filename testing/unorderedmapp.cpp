#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Class Node trong linked-list
template <typename K,typename V>
class Node {
public:
    K key;
    V value;
    Node* next;
    Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
};

// Class Unordered map sử dụng separate chaining
template <typename K,typename V>
class umap {
private:
    vector<Node<K,V>*> bucketArray; // Mảng con trỏ, mỗi phần tử là con trỏ tới nút đầu tiên của linked list

    // Hàm hash để tính toán key
    size_t hash(int key) {
        return static_cast<size_t>(key) % bucketArray.size();
    }

public:
    
    // Khởi tạo umap với số lượng bucket cho trước
    umap(size_t numBuckets) : bucketArray(numBuckets, nullptr) {}

    // Hàm thêm một cặp key-value vào umap
    void insert(const K& key, const V& value) {
    size_t index = hash(key);
    
    Node<K,V>* current = bucketArray[index]; // Tạo một con trỏ trỏ tới index hiện tại
    
    while (1) {
        // Kiểm tra xem bucket tại chỉ số index có rỗng hay không
        if (bucketArray[index] == nullptr) {
            // Nếu rỗng, thêm nút mới vào đầu danh sách liên kết
            bucketArray[index] = new Node<K,V>(key, value);
            return;
        } 
        else { // Nếu index không rỗng
            // Kiểm tra xem key có trong linked-list chưa
            if (bucketArray[index]->key == key) {
                Node<K,V>* newNode = new Node<K,V>(key, value);
                newNode->next = bucketArray[index];
                bucketArray[index] = newNode; // Nếu có thì thêm vào đầu danh sách
                return;
            }
            else { // Nếu chưa thì di chuyển đến vị trí tiếp theo trống
                size_t nextIndex = (index + 1) % bucketArray.size();
                while (nextIndex != index && bucketArray[nextIndex] != nullptr) {
                    nextIndex = (nextIndex + 1) % bucketArray.size();
                }

                if (bucketArray[nextIndex] == nullptr) {
                    index = nextIndex;
                    current = bucketArray[index];
                }
                else {
                    // BucketArray đã đầy, thực hiện tái băm và chèn phần tử vào bucket mới
                    resizeAndRehash();
                    // Cập nhật lại index và current sau khi tái băm
                    index = hash(key);
                    current = bucketArray[index];
                    }
                }
            }
        }
    }
    
    void resizeAndRehash() {
    // Tăng kích thước của bucketArray lên gấp đôi
    size_t newSize = bucketArray.size() * 2;
    vector<Node<K,V>*> newBucketArray(newSize, nullptr);

    // Đặt lại các phần tử vào vị trí mới dựa trên hàm hash mới
    for (size_t i = 0; i < bucketArray.size(); ++i) {
        Node<K,V>* current = bucketArray[i];
        while (current != nullptr) {
            size_t newIndex = current->key % newSize;
            Node<K,V>* next = current->next;
            current->next = newBucketArray[newIndex];
            newBucketArray[newIndex] = current;
            current = next;
        }
    }

    // Cập nhật bucketArray mới
    bucketArray = newBucketArray;
    }

        
    // Hàm tìm giá trị tương ứng với key trong umap
    V find(const K& key) {
    size_t index = hash(key);
    Node<K,V>* current = bucketArray[index];

    // Duyệt qua các Node trong bucket
    while (current != nullptr) {
        if (current->key == key) {
            cout << current->value << " "; // Trả về giá trị tương ứng nếu tìm thấy key
        }
        current = current->next;
    }

    // Nếu không tìm thấy key trong bucket hiện tại, thử tìm trong các bucket khác nếu có
    size_t startIndex = index;
    index = (index + 1) % bucketArray.size(); // Chuyển đến bucket tiếp theo
    while (index != startIndex) {
        current = bucketArray[index];
        while (current != nullptr) {
            if (current->key == key) {
                cout << current->value << " "; // Trả về giá trị tương ứng nếu tìm thấy key
            }
            current = current->next;
        }
        index = (index + 1) % bucketArray.size(); // Chuyển đến bucket tiếp theo
    }

    return V(); // Trả về chuỗi rỗng nếu không tìm thấy key
    }


    // Hàm xóa một cặp key-value khỏi umap
    // void erase(const K& key) {
    //     size_t index = hash(key); // Tính index của key

    //     // Duyệt qua các nút trong bucket
    //     Node<K,V>* current = bucketArray[index];
    //     Node<K,V>* prev = nullptr;
    //     while (current != nullptr) {
    //         if (current->key == key) {
    //             if (prev == nullptr) {
    //                 bucketArray[index] = current->next;
    //             } else {
    //                 prev->next = current->next;
    //             }
    //             delete current;
    //             break;
    //         }
    //         prev = current;
    //         current = current->next;
    //     }
    // }

    // Hàm in ra hash table
    void printHashTable() {
        for (size_t i = 0; i < bucketArray.size(); ++i) {
            cout << "index " << i << ": " << endl;
            Node<K,V>* current = bucketArray[i];
            while (current != nullptr) {
                cout << " || key: " << current->key << " - value: " << current->value;
                current = current->next;
            }
            cout << " ||";
            cout << endl;
            }
        }
    };

int main() {
    umap<int, int> map(2); // Khởi tạo một umap với 10 bucket
    map.insert(1, 1);
    map.insert(2, 0);
    map.insert(2, 3);
    map.insert(12, 2);
    map.insert(2324, 6);
    map.insert(2421455, 7);
    map.insert(12, 3);
    map.insert(2414, 8);
    map.insert(25435412, 9);
    map.insert(2213, 5);
    map.insert(24124, 3);
    map.insert(12342, 2);
    map.insert(26546, 6);
    map.insert(22135, 7);
    map.insert(12231, 3);
    map.insert(23123, 8);
    map.insert(221, 9);
    map.insert(12, 4);
    // erase phần tử đầu tiên của bucket
    // map.erase(2);
    // In ra hash table
    map.printHashTable();
    // In ra giá trị các Node trong key 2 
    cout << "Value of all node with key = 2: " << endl;
    cout << "print 0 to end: " << map.find(2) << endl;
    return 0;
}
