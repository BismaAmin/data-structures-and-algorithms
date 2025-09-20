#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

// Insert at end
void insertAtEnd(Node *&head, int value) {
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Delete from start
void deleteAtStart(Node *&head) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    cout << "Deletion is done of " << temp->data << endl;
    delete temp;
}

// Display the list
void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << "The elements are = " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Before deletion:" << endl;
    display(head);

    deleteAtStart(head);

    cout << "After deletion from start:" << endl;
    display(head);

    return 0;
}
