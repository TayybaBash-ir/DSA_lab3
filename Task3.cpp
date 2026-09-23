#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 1 Insert at Head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at the head.\n";
}

// 2 Insert at 3rd Position
void insertAtThird(Node*& head, int val) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    if (count < 2) {
        cout << "Error: List has fewer than 2 nodes. Cannot insert at position 3.\n";
        return;
    }

    Node* curr = head;
    for (int i = 1; i < 2; i++) {
        curr = curr->next;
    }

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = curr->next;
    curr->next = newNode;
    cout << "Inserted " << val << " at position 3.\n";
}

// 3 Display List
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty: NULL\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 4  Delete Last Node
void deleteLast(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    if (head->next == nullptr) {
        cout << "Deleted last node with value: " << head->data << "\n";
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    cout << "Deleted last node with value: " << temp->next->data << "\n";
    delete temp->next;
    temp->next = nullptr;
}

// 5 Count Nodes
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

//  Reverse List 
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    cout << "Linked list reversed successfully.\n";
}

// Search Value 
void searchValue(Node* head, int val) {
    Node* temp = head;
    int position = 1;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data == val) {
            cout << "Value " << val << " found at position (index): " << position << "\n";
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        cout << "Value " << val << " not found in the list.\n";
    }
}

// Free Memory
void freeList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    int choice, val;

    do {
        cout << " SINGLY LINKED LIST LAB MENU\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at 3rd Position\n";
        cout << "3. Display List\n";
        cout << "4. Delete Last Node\n";
        cout << "5. Count Number of Nodes\n";
        cout << "6. Reverse Linked List Iteratively\n";
        cout << "7. Search for a Value\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer value: ";
                cin >> val;
                insertAtHead(head, val);
                break;
            case 2:
                cout << "Enter integer value: ";
                cin >> val;
                insertAtThird(head, val);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                deleteLast(head);
                displayList(head);
                break;
            case 5:
                cout << "Total nodes in list: " << countNodes(head) << "\n";
                break;
            case 6:
                reverseList(head);
                displayList(head);
                break;
            case 7:
                cout << "Enter integer value to search: ";
                cin >> val;
                searchValue(head, val);
                break;
            case 8:
                freeList(head);
                cout << "Exiting program and clearing memory.\n";
                break;
            default:
                cout << "Invalid choice! Select between 1 and 8.\n";
        }
    } while (choice != 8);

    return 0;
}