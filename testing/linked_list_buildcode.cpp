#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* start;

public:
    LinkedList() : start(nullptr) {}

    Node* create_ll() {
        Node *new_node, *ptr;
        int num;
        cout << "\nEnter -1 to end" << endl;
        cout << "Enter the data: ";
        cin >> num;
        while (num != -1) {
            new_node = new Node(num);
            if (start == nullptr) {
                start = new_node;
            } else {
                ptr = start;
                while (ptr->next != nullptr) {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
            }
            cout << "Enter the data: ";
            cin >> num;
        }
        return start;
    }

    void display() {
        Node* ptr = start;
        while (ptr != nullptr) {
            cout << "\t" << ptr->data;
            ptr = ptr->next;
        }
    }

    void insert_beg() {
        int num;
        cout << "\nEnter the data: ";
        cin >> num;
        Node* new_node = new Node(num);
        new_node->next = start;
        start = new_node;
    }

    void insert_end() {
        int num;
        cout << "\nEnter the data: ";
        cin >> num;
        Node* new_node = new Node(num);
        if (start == nullptr) {
            start = new_node;
        } else {
            Node* ptr = start;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
    }

    void insert_before() {
        int num, val;
        cout << "\nEnter the data: ";
        cin >> num;
        cout << "Enter the value before which the data has to be inserted: ";
        cin >> val;
        Node* new_node = new Node(num);
        if (start == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (start->data == val) {
            new_node->next = start;
            start = new_node;
            return;
        }
        Node* ptr = start;
        Node* preptr = nullptr;
        while (ptr != nullptr && ptr->data != val) {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            cout << "Value not found in the list." << endl;
        } else {
            preptr->next = new_node;
            new_node->next = ptr;
        }
    }

    void insert_after() {
        int num, val;
        cout << "\nEnter the data: ";
        cin >> num;
        cout << "Enter the value after which the data has to be inserted: ";
        cin >> val;
        Node* new_node = new Node(num);
        if (start == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* ptr = start;
        while (ptr != nullptr && ptr->data != val) {
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            cout << "Value not found in the list." << endl;
        } else {
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }

    void delete_beg() {
        if (start == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* ptr = start;
        start = start->next;
        delete ptr;
    }

    void delete_end() {
        if (start == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (start->next == nullptr) {
            delete start;
            start = nullptr;
            return;
        }
        Node* ptr = start;
        Node* preptr = nullptr;
        while (ptr->next != nullptr) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = nullptr;
        delete ptr;
    }

    void delete_node() {
        int val;
        cout << "Enter the value of the node which has to be deleted: ";
        cin >> val;
        if (start == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* ptr = start;
        Node* preptr = nullptr;
        while (ptr != nullptr && ptr->data != val) {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            cout << "Value not found in the list." << endl;
        } else {
            if (ptr == start) {
                start = start->next;
            } else {
                preptr->next = ptr->next;
            }
            delete ptr;
        }
    }

    void delete_after() {
        int val;
        cout << "Enter the value after which the node has to be deleted: ";
        cin >> val;
        if (start == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* ptr = start;
        while (ptr != nullptr && ptr->data != val) {
            ptr = ptr->next;
        }
        if (ptr == nullptr || ptr->next == nullptr) {
            cout << "No node to delete after the given value." << endl;
        } else {
            Node* temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }
    }

    void delete_list() {
        if (start == nullptr) {
            cout << "List is already empty." << endl;
            return;
        }
        Node* ptr = start;
        while (ptr != nullptr) {
            Node* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        start = nullptr;
        cout << "Linked list deleted." << endl;
    }

    void sort_list() {
        if (start == nullptr || start->next == nullptr) {
            cout << "List is already sorted or empty." << endl;
            return;
        }
        Node *ptr1, *ptr2;
        int temp;
        ptr1 = start;
        while (ptr1 != nullptr) {
            ptr2 = ptr1->next;
            while (ptr2 != nullptr) {
                if (ptr1->data > ptr2->data) {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
};

int main() {
    LinkedList list;
    int option;
    do {
        cout << "\n\n *****MAIN MENU *****";
        cout << "\n 1: Create a list";
        cout << "\n 2: Display the list";
        cout << "\n 3: Add a node at the beginning";
        cout << "\n 4: Add a node at the end";
        cout << "\n 5: Add a node before a given node";
        cout << "\n 6: Add a node after a given node";
        cout << "\n 7: Delete a node from the beginning";
        cout << "\n 8: Delete a node from the end";
        cout << "\n 9: Delete a given node";
        cout << "\n 10: Delete a node after a given node";
        cout << "\n 11: Delete the entire list";
        cout << "\n 12: Sort the list";
        cout << "\n 13: EXIT";
        cout << "\n\n Enter your option : ";
        cin >> option;
        switch (option) {
            case 1:
                list.create_ll();
                cout << "\nLINKED LIST CREATED";
                break;
            case 2:
                cout << "\nDisplaying the list:" << endl;
                list.display();
                break;
            case 3:
                list.insert_beg();
                break;
            case 4:
                list.insert_end();
                break;
            case 5:
                list.insert_before();
                break;
            case 6:
                list.insert_after();
                break;
            case 7:
                list.delete_beg();
                break;
            case 8:
                list.delete_end();
                break;
            case 9:
                list.delete_node();
                break;
            case 10:
                list.delete_after();
                break;
            case 11:
                list.delete_list();
                break;
            case 12:
                list.sort_list();
                break;
            default:
                cout << "\nInvalid option. Please try again." << endl;
        }
    } while (option != 13);
    return 0;
}
