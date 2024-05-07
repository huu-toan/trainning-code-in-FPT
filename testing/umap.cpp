#include <iostream>
#include <list>
#include <vector>
#include <functional>

using namespace std;

class HashMap {
public:
    // Pair of key-value entry
    typedef pair<const int, string> Entry;

    // Constructor: initializes the HashMap with a given capacity
    HashMap(int capacity = 10) : size_(0), bucketArray_(capacity) {}

    // Returns the number of elements in the HashMap
    int size() const { return size_; }

    // Returns true if the HashMap is empty, false otherwise
    bool empty() const { return size_ == 0; }

    // Insert an entry with key k and value v into the HashMap
    void insert(const int& k, const string& v);

    // Find an entry with key k in the HashMap
    list<Entry>::iterator find(const int& k);

    // Erase an entry with key k from the HashMap
    void erase(const int& k);

    // Iterator class to traverse through the HashMap
    class Iterator {
    private:
        // Iterator for list of entries
        list<Entry>::iterator entryIterator_;

        // Iterator for bucket array
        vector<list<Entry>>::iterator bucketIterator_;

        // Reference to the bucket array
        const vector<list<Entry>>* bucketArray_;

    public:
        // Constructor
        Iterator(const vector<list<Entry>>& bucketArray,
                 const vector<list<Entry>>::iterator& bucketIterator,
                 const list<Entry>::iterator& entryIterator)
            : entryIterator_(entryIterator),
              bucketIterator_(bucketIterator),
              bucketArray_(&bucketArray) {}

        // Dereference operator to get the entry
        Entry& operator*() const { return *entryIterator_; }

        // Equality operator
        bool operator==(const Iterator& p) const;

        // Inequality operator
        bool operator!=(const Iterator& p) const { return !(*this == p); }

        // Prefix increment operator
        Iterator& operator++();

        friend class HashMap;
    };

    // Begin iterator
    Iterator begin();

    // End iterator
    Iterator end();

private:
    // Number of elements in the HashMap
    int size_;

    // Hash function for integers
    hash<int> hashFunction_;

    // Array of buckets (lists of entries)
    vector<list<Entry>> bucketArray_;
};

// Implementation of insert function
void HashMap::insert(const int& k, const string& v) {
    size_++;
    int index = hashFunction_(k) % bucketArray_.size();
    bucketArray_[index].push_back(make_pair(k, v));
}

// Implementation of find function
list<HashMap::Entry>::iterator HashMap::find(const int& k) {
    int index = hashFunction_(k) % bucketArray_.size();
    for (auto it = bucketArray_[index].begin(); it != bucketArray_[index].end(); ++it) {
        if (it->first == k) {
            return it;
        }
    }
    return bucketArray_[index].end();
}

// Implementation of erase function
void HashMap::erase(const int& k) {
    int index = hashFunction_(k) % bucketArray_.size();
    auto it = find(k);
    if (it != bucketArray_[index].end()) {
        bucketArray_[index].erase(it);
        size_--;
    }
}

// Implementation of Iterator class member functions
bool HashMap::Iterator::operator==(const Iterator& p) const {
    return (bucketIterator_ == p.bucketIterator_ && entryIterator_ == p.entryIterator_);
}

HashMap::Iterator& HashMap::Iterator::operator++() {
    ++entryIterator_;
    while (entryIterator_ == bucketIterator_->end()) {
        ++bucketIterator_;
        if (bucketIterator_ == bucketArray_->end()) {
            break;
        }
        entryIterator_ = bucketIterator_->begin();
    }
    return *this;
}

// Implementation of begin function
HashMap::Iterator HashMap::begin() {
    for (auto it = bucketArray_.begin(); it != bucketArray_.end(); ++it) {
        if (!it->empty()) {
            return Iterator(bucketArray_, it, it->begin());
        }
    }
    return end();
}

// Implementation of end function
HashMap::Iterator HashMap::end() {
    return Iterator(bucketArray_, bucketArray_.end(), list<Entry>::iterator());
}

int main() {
    // Example usage
    HashMap map;
    map.insert(1, "One");
    map.insert(2, "Two");
    map.insert(3, "Three");

    // Iterate through the HashMap
    for (HashMap::Iterator it = map.begin(); it != map.end(); ++it) {
        cout << (*it).first << ": " << (*it).second << endl;
    }

    return 0;
}
