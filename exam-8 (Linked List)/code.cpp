#include <iostream>

using std::cout;
using std::cin;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        Node *head = NULL;
        int count = 0;

        void addAtStart(int data){
            Node *newNode = new Node(data);

            newNode->next = this->head;
            this->head = newNode;

            this->count++;
            cout << "\n=========================================\n";
            cout << "New Node has been inserted at start...\n";
            cout << "=========================================\n";
        }

        void display(){
            Node *temp = this->head;
            cout << "\n\n";
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL";
            cout << "\n\n";
        }

        void update(int pos){
            if (pos < 0 || pos > count-1){
                cout << "\n==============\n";
                cout << "Out of range\n";
                cout << "==============\n";
                return;
            }

            int data;
            cout << "Enter value to insert data: ";
            cin >> data;

            Node *temp = this->head;

            for(int i = 0; i < pos; i++){
                temp = temp->next;
            }

            temp->data = data;

            cout << "\n=========================================\n";
            cout << "Data has been updated successfully...\n";
            cout << "=========================================\n";
        }

        void deleteAtStart(){
            if (count == 1 || head->next == NULL){
                delete this->head;
                this->head = NULL;
                this->count = 0;
                cout << "\n=========================================\n";
                cout << "Node at Start has been deleted (currently list is empty)...\n";
                cout << "=========================================\n";
                return;
            }
            Node *temp = this->head;
            this->head = head->next;
            this->count--;
            cout << "\n=========================================\n";
            cout << "Node at Start has been deleted...\n";
            cout << "=========================================\n";

            delete temp;
            temp = NULL;
        }

        void deleteAtEnd(){
            if (count == 1 || head->next == NULL){
                delete this->head;
                this->head = NULL;
                this->count = 0;
                cout << "\n=========================================\n";
                cout << "Node at the End has been deleted (currently list is empty)...\n";
                cout << "=========================================\n";
                return;
            }

            Node *temp = this->head;
            while (temp->next->next != NULL){
                temp = temp->next;
            }

            delete temp->next;
            temp->next = NULL;

            this->count--;

            cout << "\n=========================================\n";
            cout << "Node at the End has been deleted...\n";
            cout << "=========================================\n";   
        }
        
        void deleteAtAny(int pos){
            if (pos == 0){
                this->deleteAtStart();
            }
            if (pos < 0 || pos > count-1){
                cout << "\n==============\n";
                cout << "Out of range\n";
                cout << "==============\n";
                return;
            }
             if (count == 1 || head->next == NULL){
                delete this->head;
                this->head = NULL;
                this->count = 0;
                cout << "\n=========================================\n";
                cout << "Node at the End has been deleted (currently list is empty)...\n";
                cout << "=========================================\n";
                return;
            }

            Node *current = this->head;
            Node *previous = this->head;

            for (int i = 0; i < pos; i++){
                current = current->next;
            }
            for (int i = 0; i < pos-1; i++){
                previous = previous->next;
            }

            previous->next = current->next;
            delete current;

            cout << "\n=========================================\n";
            cout << "Node at the position " << pos <<  " has been deleted...\n";
            cout << "=========================================\n"; 
        }

        void find(int value){
            Node *temp = this->head;
            int pos = -1;
            for (int i = 0; i < count; i++){
                if (value == temp->data){
                    pos = i;
                    break;
                }
                temp = temp->next;
            }

            if (pos == -1){
                cout << "\n==============\n";
                cout << "Value Not Found\n";
                cout << "==============\n";
                return;
            }
            cout << "\n========================\n";
            cout << "Value found at position: " << pos << "\n";
            cout << "========================\n";
            
        }
};


int main(){
    LinkedList list;
    int choice;
    cout << "\n        Linked List (CRUD operations)\n";
    do {
        cout << "\n1. Add a node at start\n";
        cout << "2. View Linked List\n";
        cout << "3. update data at a specific index (0 based)\n";
        cout << "4. delete a node at start\n";
        cout << "5. delete a node at end\n";
        cout << "6. delete a node at a specific index (0 based)\n";
        cout << "7. Search for data in Linked List\n";
        cout << "\nChoice : ";
        cin >> choice;

        switch(choice){
            case 1:{
                int val;
                cout << "Enter a value to insert: ";
                cin >> val;
                list.addAtStart(val);
                break;
            }
            case 2:{
                list.display();
                break;
            }
            case 3:{
                int pos;
                cout << "Enter a Index of target Node: ";
                cin >> pos;
                list.update(pos);
                break;
            }
            case 4:{
                list.deleteAtStart();
                break;
            }
            case 5:{
                list.deleteAtEnd();
                break;
            }
            case 6:{
                int pos;
                cout << "Enter the position (0 based index) of node to delete: ";
                cin >> pos;

                list.deleteAtAny(pos);
                break;
            }
            case 7:{
                int value;
                cout << "Enter the value you want to search for: ";
                cin >> value;
                list.find(value);
                break;
            }
            default:{
                cout << "\n==============\n";
                cout << "Invalid Choice\n";
                cout << "==============\n";
            }
        }
    } while (choice != 0);


    return 0;
}