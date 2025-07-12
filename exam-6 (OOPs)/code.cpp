#include <iostream>
using namespace std;

class Book{
    private:
        bool isIssued = false;

    protected:
        int bookID;
        string title, author;

    public:
        void addBook(int bookID, string title, string author){
            this->bookID = bookID;
            this->title = title;
            this->author = author;
        }
        void viewBookDetails(){
            cout << "\n================================\n";
            cout << "Book ID: "<< this->bookID << "\n";
            cout << "Title: " << this->title << "\n";
            cout << "Author: " << this->author << "\n";
            cout << "Avaibility: " << (this->isIssued ? "No" : "Yes"); 
            cout << "\n================================\n";
        } 

        int getBookId(){
            return this->bookID;
        }

        void availableFlip(){
            this->isIssued = (isIssued ? false : true);
        }

        bool getIsIssued(){
            return this->isIssued;
        }
};

class IssuedBook : public Book{
    protected:
        string issuedTo = "Not Issued";
        int issueDate = 0;
        int dueDate = 0;
        int finePerDay = 10;
    
    public:
        void issueBook(string name, int issueDate, int dueDate){
            availableFlip();
            this->issuedTo = name;
            this->issueDate = issueDate;
            this->dueDate = dueDate;
        }
        void returnBook(int returnDate){
            calculateFine(returnDate);
            this->issuedTo = "Not Issued";
            this->issueDate = 0;
            this->dueDate = 0;
            availableFlip();
        }
        void calculateFine(int returnDate){
            if(returnDate > dueDate){
                int fine = (returnDate - dueDate) * finePerDay;
                cout << "\nFine for late return : " << fine << "rs\n";
            } else {
                cout << "\nThank you for using our service no fine required\n";
            }
        }
        void getBorrowerDetails(){
            cout << "\n================================\n";
            cout << "Borrower Name : " << this->issuedTo << "\n";
            cout << "Issue Date : " << this->issueDate << "\n";
            cout << "Due Date : " << this->dueDate << "\n";
            cout << "BookID : " << this->bookID << "\n";
            cout << "Title : " << this->title << "\n";
            cout << "Author : " << this->author << "\n";
            cout << "================================\n";
        }

};

int main(){
    int librarySize = 2;
    IssuedBook library[librarySize];
    int choice = 0, idx = 0;
    do{
        cout << "\n----------------------------\n";
        cout << "Enter 1 to add a book: \n";
        cout << "Enter 2 to issue a book: \n";
        cout << "Enter 3 to return a book: \n";
        cout << "Enter 4 to view book/'s details: \n";
        cout << "Enter 5 to check borrower's details: \n";
        cout << "Enter 6 to exit the program \n";
        cout << "Choice: ";
        cin >> choice;
        cout << "----------------------------\n";
        switch(choice){
            // adding books
            case 1:{
                if (idx == librarySize){
                    cout << "Library is full!\n";
                    break;
                }
                int bookID;
                string title, author;
                cout << "Enter the book Id: ";
                cin >> bookID;
                cin.ignore();
                cout << "Enter the title of the book: ";
                getline(cin, title);
                cout << "Enter the name of the author: ";
                getline(cin, author);
    
                library[idx].addBook(bookID, title, author);
                idx++;
                break;
            }
            // issueing book
            case 2:{
                int bookID, issueDate, dueDate;
                string issuedTo;
                cout << "Enter the book ID : ";
                cin >> bookID;
                cin.ignore();
                for (int i = 0; i < idx; i++){
                    if (library[i].getIsIssued() == true){
                        cout << "This book is already issued!\n";
                        break;
                    }
                    if (library[i].getBookId() == bookID){
                        cout << "Enter the name of borrower: ";
                        getline(cin, issuedTo);
                        cout << "Enter the Issue Date: ";
                        cin >> issueDate;
                        cout << "Enter the Due Date: ";
                        cin >> dueDate;
                        library[i].issueBook(issuedTo, issueDate, dueDate);
                    }
                }
                break;
            }
            // returng book
            case 3:{
                int bookID;
                cout << "Enter the book ID: ";
                cin >> bookID;
                bool killFlag = false;
                for (int i = 0; i < idx; i++){
                    if (library[i].getIsIssued() == false){
                        cout << "This book was never issued!\n";
                        killFlag = true;
                        break;
                    }
                    if (library[i].getBookId() == bookID){
                        int returnDate;
                        cout << "Enter the return date: ";
                        cin >> returnDate;
                        library[i].returnBook(returnDate);
                        cout << "Book returned successfully!\n";
                        killFlag = true;
                        break;
                    }
                }
                if (killFlag){
                    break;
                }
                cout << "This book doesn't belong to this library!\n";
                break;
            }
            // view book details
            case 4:{
                for (int i = 0; i < idx; i++){
                    library[i].viewBookDetails();
                }
                break;
            }
            // check borrower details
            case 5:{
                int bookID;
                cout << "Enter the book ID: ";
                cin >> bookID;

                for (int i = 0; i < idx; i++){
                    if (bookID = library[i].getBookId()){
                        library[i].getBorrowerDetails();
                    }
                }
                break;
            }
            default:{
                cout << "Invalid choice (please choose from 1 to 5)\n";
            }
        }
    } while (choice != 6);


    return 0;
}