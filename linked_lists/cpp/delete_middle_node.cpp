#include <iostream>

struct Node {
    char data;
    Node * next;
    Node(char c): data{ c }, next{ nullptr } {}
};

void printList(Node * head) {
    while(head) {
        std::cout << head->data << "-->";
        head = head->next;
    }
}

void deleteNode(Node * node) {
    if (node == nullptr || node->next == nullptr)
        return;

    Node * nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
};

int main() {
    Node * head = new Node('a');
    head->next = new Node('b');
    head->next->next = new Node('c');
    head->next->next = new Node('d');
    head->next->next = new Node('e');
    std::cout << "List before deletion:" << '\n';
    printList(head);
    std::cout << "Deleting node containing data as 'c'" << '\n';
    deleteNode(head->next->next);
    std::cout << "List after deletion:" << '\n';
    printList(head);
    return 0;
}
