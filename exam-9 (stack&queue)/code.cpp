#include <iostream>

using std::cout;
using std::cin;

class Stack{
    private:
        int size;
        int data;
        int top;
        int *arr;
        int secLargest;
        int largest;
        int count;
    public:
        Stack(int size){
            this->size = size;
            this->arr = new int[size];
            this->top = -1;
            this->count = 0;
            this->secLargest = 0;
            this->largest = 0;
        }
        ~Stack(){
            delete[] this->arr;
            this->arr = NULL;
        }

        void push(int);
        void pop();
        int getTop();
        bool isEmpty();
        bool isFull();
        void display();
        int getSecondLargest();
        void calculateSecLargest(int);
        int getSize();
        void calculateSecondLargestOnPop();
};

void Stack::push(int data){
    this->calculateSecLargest(data);
    if(this->isFull()){
        cout << "\n-----------------------------\n";
        cout << "Stack has been overflown";
        cout << "\n-----------------------------\n";
        return;
    }
    this->arr[++this->top] = data;
    this->count++;
}

void Stack::pop(){
    if(this->isEmpty()){
        cout << "\nStack is Empty!\n";
        return;
    }
    cout << "\n-----------------------------\n";
    cout << "Popped element: " << this->arr[this->top];
    cout << "\n-----------------------------\n";
    this->arr[this->top] = 0;
    this->calculateSecondLargestOnPop();
    this->top--;
    this->count--;
}

int Stack::getTop(){
    if(this->isEmpty()){
        cout << "\n-----------------------------\n";
        cout << "Stack is Empty!";
        cout << "\n-----------------------------\n";
        return 0;
    }
    return this->arr[this->top];
}

bool Stack::isEmpty(){
    return this->count == 0;
}

bool Stack::isFull(){
    return this->count == size;
}

void Stack::display(){
    if(this->isEmpty()){
        cout << "\nStack is Empty!\n";
        return;
    }
    cout << "\n-----------------------------\n";
    cout << "------\n";
    for (int i = count-1; i >= 0; i--){
        cout << "| " << this->arr[i] << " |\n";
    }
    cout << "------\n";
    cout << "Stack\n";
    cout << "-----------------------------\n";
}

int Stack::getSecondLargest(){
    return this->secLargest;
}

// will run after popping element
void Stack::calculateSecondLargestOnPop(){
    for (int i = 0; i < count; i++){
        this->calculateSecLargest(this->arr[i]);
    }
}

// will check sec largest and largest on push
void Stack::calculateSecLargest(int data){
    if (this->count == 0){
        this->largest = data;
        this->secLargest = data;
    } else if (this->largest < data){
        this->secLargest = largest;
        this->largest = data;
    } else if (this->secLargest < data){
        this->secLargest = data;
    }
}

int Stack::getSize(){
    return this->size;
}

int main(){
    Stack s(3);
    int choice;
    do {
        cout << "\n\n1. Push an element in stack\n";
        cout << "2. Pop an element from stack\n";
        cout << "3. Get top element from stack\n";
        cout << "4. Check if stack is empty?\n";
        cout << "5. Check if stack is full?\n";
        cout << "6. Display Stack\n";
        cout << "7. Get Second largest element from stack\n";
        cout << "0. Exit this program\n\n";
        cout << "Choice : ";
        cin >> choice;

        switch (choice){
            case 1:{
                int data;
                cout << "Enter any Integer value: ";
                cin >> data;
                s.push(data);
                break;
            }
            
            case 2:{
                s.pop();
                break;
            }
            
            case 3:{
                cout << "\n-----------------------------\n";
                cout << "Top element of Stack: " << s.getTop();
                cout << "\n-----------------------------\n";
                break;
            }
            
            case 4:{
                cout << "\n-----------------------------\n";
                s.isEmpty() ? cout << "Stack is empty!" : cout << "Stack is not empty!";
                cout << "\n-----------------------------\n";
                break;
            }
            
            case 5:{
                cout << "\n-----------------------------\n";
                s.isFull() ? cout << "Stack is full!" : cout << "Stack is not full!";
                cout << "\n-----------------------------\n";
                break;
            }
            
            case 6:{
                s.display();
                break;
            }
            case 7:{
                cout << "\n-----------------------------\n";
                cout << "Second largest element in Stack: " << s.getSecondLargest();
                cout << "\n-----------------------------\n";
                break;
            }
            
            default:{
                cout << "\n-----------------------------\n";
                cout << "Invalid choice";
                cout << "\n-----------------------------\n";
            }
        }   
    } while(choice != 0);

    return 0;
}