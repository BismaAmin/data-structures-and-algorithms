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

// Delete from end
void deleteAtEnd(Node *&head) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete" << endl;
        return;
    }

    // If only one node
    if (head->next == NULL) {
        cout << "Deletion is done of " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    Node *del = temp->next;
    temp->next = NULL;
    cout << "Deletion is done of " << del->data << endl;
    delete del;
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

    deleteAtEnd(head);

    cout << "After deletion from end:" << endl;
    display(head);

    return 0;
}

