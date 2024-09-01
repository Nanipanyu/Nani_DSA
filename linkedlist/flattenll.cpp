#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        if (this->child != NULL) {
            delete child;
            this->child = NULL;
        }
        cout << "Node with value " << value << " is freed" << endl;
    }
};

Node* merge(Node* h1, Node* h2) {
    if (h1 == NULL) {
        return h2;
    }
    if (h2 == NULL) {
        return h1;
    }

    Node* mergehead = NULL;
    Node* mergetail = NULL;

    if (h1->data <= h2->data) {
        mergehead = h1;
        h1 = h1->child;
    } else {
        mergehead = h2;
        h2 = h2->child;
    }
    mergetail = mergehead;

    while (h1 != NULL && h2 != NULL) {
        if (h1->data <= h2->data) {
            mergetail->child = h1;
            h1 = h1->child;
        } else {
            mergetail->child = h2;
            h2 = h2->child;
        }
        mergetail = mergetail->child;
    }

    if (h1 != NULL) {
        mergetail->child = h1;
    } else {
        mergetail->child = h2;
    }

    return mergehead;
}

Node* flattenLinkedList(Node* head) {
    //base case
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // Going forward towards next recursively
    Node* nextList = flattenLinkedList(head->next);
    head->next = NULL;
    // merging the ll with the next ll
    Node* mergedList = merge(head, nextList);
    return mergedList;
}

void printFlattenedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl;
}

int main() {
    // Example linked list creation
    Node* head = new Node(1);
    head->child = new Node(2);
    head->child->child = new Node(3);

    head->next = new Node(4);
    head->next->child = new Node(5);
    head->next->child->child = new Node(6);

    head->next->next = new Node(7);
    head->next->next->child = new Node(8);

    head->next->next->next = new Node(9);
    head->next->next->next->child = new Node(12);

    head->next->next->next->next = new Node(20);
    printFlattenedList(head);

    Node* flattenedList = flattenLinkedList(head);
    printFlattenedList(flattenedList);

    delete flattenedList;

    return 0;
}
