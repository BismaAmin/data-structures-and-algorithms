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

int main(){
	Node *head= NULL;
	
	insertAtEnd(head,10);
	insertAtEnd(head,20);
	insertAtEnd(head,30);
	insertAtEnd(head,40);
	insertAtEnd(head,50);
	
	display(head);
	
	int choice;
	do{
	cout<<"----MENU----"<<endl;
	cout<<"1. deletion at start "<<endl;
	cout<<"2. deletion at end "<<endl;
	cout<<"3. deletion at given position "<<endl;
	cout<<"4. display "<<endl;
	cout<<"5. exit "<<endl;
	
	cout<<"Enter the number from menu ";
	cin>>choice;
	
	switch(choice){
		case 1:
		   deleteAtStart(head);
		break;
		
		case 2:
		   deleteAtEnd(head);
		break;
		
		case 3:
		   deleteAtGiven(head,3);
		break;
		
		case 4:
		   display(head);
		break;
		
		case 5:
		   cout<<"You have been exited from program"<<endl;
		break;
		
		default:
		   cout<<"Invalid choice ";				
	}
	
}while(choice!=5);
}