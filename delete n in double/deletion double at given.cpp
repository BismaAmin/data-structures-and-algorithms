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

// Delete at given position
void deleteAtGiven(Node *&head, int pos) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete" << endl;
        return;
    }

    if (pos == 1) { // delete first node
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        cout << "Deletion is done of " << temp->data << endl;
        delete temp;
        return;
    }

    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position" << endl;
        return;
    }

    Node *del = temp->next;
    temp->next = del->next;
    if(del->next!=NULL)
    {
        del->next->prev = temp;
    }
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
    insertAtEnd(head, 50);

    cout << "Before deletion:" << endl;
    display(head);

    deleteAtGiven(head, 3); // delete 3rd node (30)

    cout << "After deletion at given position:" << endl;
    display(head);

    return 0;
}

