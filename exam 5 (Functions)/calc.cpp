#include <iostream>
using namespace std;

void add(float, float);
void sub(float, float);
void multiply(float, float);
void division(float, float);
void mod(float, float);
void isPalindrome(int);

int main(){
    float a, b;
    int choice, pal;
    cout << "Enter the value of number 1 & 2: ";
    cin >> a >> b;
    cout << "Enter the value to check if its palindrome: ";
    cin >> pal;

    do{
        cout << "\nPress 1 for +\n";
        cout << "Press 2 for -\n";
        cout << "press 3 for *\n";
        cout << "press 4 for /\n";
        cout << "press 5 for %\n";
        cout << "press 6 to check Palindrome: \n";
        cout << "Enter 7 to exit the program: \n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                add(a,b);
                break;
            }
            case 2:{
                sub(a,b);
                break;
            }
            case 3:{
                multiply(a,b);
                break;
            }
            case 4:{
                division(a,b);
                break;
            }
            case 5:{
                mod(a, b);
                break;
            }
            case 6:{
                isPalindrome(pal);
                break;
            }
            default:{
                if (choice > 7){
                    cout << "Invalid choice!\n";
                }
                break;
            }
        }
    } while (choice != 7);
    cout << "\n\nThank you for using our program !";
    return 0;
}

void add(float x, float y){
    cout << "\n\nAddition of " << x << " and " << y << " is " << x+y << "\n";
}


void sub(float x, float y){
    cout << "\n\nSubtraction of " << x << " and " << y << " is " << x-y << "\n";
}
void multiply(float x, float y){
    cout << "\n\nMultiplication of " << x << " and " << y << " is " << x*y << "\n";
}
void division(float x, float y){
    cout << "\n\nDivision of " << x << " and " << y << " is " << x/y << "\n";
}
void mod(float x, float y){
    cout << "\n\nModulo of " << x << " and " << y << " is " << (int)x % (int)y << "\n";
}

void isPalindrome(int n){
    int reversed = 0, original = n;

    while (n != 0){
        reversed = reversed * 10 + (n%10);
        n/=10;
    }

    cout << "\nReverse of " << original << " is " << reversed << "\n";

    if (reversed == original){
        cout << original << " is " << " Palindrome Number!\n";
    } else {
        cout << original << " is " << " Not a Palindrome Number!\n";
    }
}