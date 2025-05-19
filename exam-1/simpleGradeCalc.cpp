#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter your grade: ";
    cin >> n;

    // step 1 using ternary operator

    (n >= 90) ? 
        cout << "Your grade is A. " 
        : (n >= 80) ? 
            cout << "Your grade is B. " 
            : (n>=70) ? 
                cout << "Your grade is C. " 
                : (n >= 50) ?
                    cout << "Your grade is D. "
                    : cout << "Your grade is E. "; 
    
    // step 2 switch case statement

    // checking grade first
    char grade;
    if(n >= 90){
        grade = 'A';
    } else if (n >= 80){
        grade = 'B';
    } else if (n >= 70){
        grade = 'C';
    } else if (n >= 50){
        grade = 'D';
    } else {
        grade = 'E';
    }

    // switch case statement
    switch(grade){
        case 'A':{
            cout << "Excellent work!";
            break;
        }
        case 'B':{
            cout << "Great work!";
            break;
        }
        case 'C':{
            cout << "Good work!";
            break;
        }
        case 'D':{
            cout << "nice work!";
            break;
        }
        case 'E':{
            cout << "better luck next time!";
            break;
        }
    }

    // step 3: eligibility test

    if (n >= 50){
        cout << " Congratulations! You are eligible for the next level!";
    } else {
        cout << " Sorry you failed!";
    }


    return 0;
}