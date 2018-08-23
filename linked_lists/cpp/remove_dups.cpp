#include <iostream>
#include <unordered_map>
#include <random>

struct Node {
    int data = 0;
    Node * next = nullptr;
};

// Insert a node at the head of list
void insert(Node * & head, int data) {
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList(Node * head) {
    while (head) {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "nullptr" << '\n';
}

static inline int random_range(const int min, const int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
};

// method 1
// space complexity O(1)
// time complexity O(n^2)
// Remove duplicates wihout using a temporary buffer
void removeDuplicates_wihout_buffer(Node * head) {
    if (head == nullptr || (head && (head->next == nullptr))) {
        return;
    }
    Node * curr = head;
    while (curr) {
        Node * runner = curr;
        while (runner->next != nullptr) {
            if (runner->next->data == curr->data) {
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

/*
    method 2
    space - O(n)
    time - O(n)
    Remove duplicates by using hash table
*/
void removeDuplicates(Node * head) {
    if (head == nullptr || (head && (head->next == nullptr))) {
        return;
    }

    std::unordered_map<int, int> node_map;
    Node * prev = head;
    Node * curr = head->next;
    node_map[head->data] = 1;
    while (curr != nullptr) {
        while (curr && node_map.find(curr->data) != node_map.end()) {
            curr = curr->next;
        }
        prev->next = curr;
        prev = curr;
        if (curr) {
            node_map[curr->data] = 1;
            curr = curr->next;
        }
    }
};

int main() {
    std::cout << "Method 1: " << '\n';
    Node * head = nullptr;
    for (int i = 0; i < 10; i++) {
        insert(head, random_range(1, 7));
    }
    printList(head);
    removeDuplicates_wihout_buffer(head);
    printList(head);

    std::cout << "Method 2: " << '\n';
    head = nullptr;
    for (int i = 0; i < 10; i++) {
        insert(head, random_range(1, 7));
    }
    printList(head);
    removeDuplicates(head);
    printList(head);

    std::cout << '\n';
    return 0;
}
