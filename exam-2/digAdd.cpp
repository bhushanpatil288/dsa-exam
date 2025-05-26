#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter any number: ";
    cin >> n;

    int last = n%10;
    n /= 10;

    // just an assumption
    int first = n%10;
    n /= 10;

    while (n > 0){
        int rem = n % 10;
        first = rem;
        n/=10;
    }

    cout << "first and last digit addition :" << last+first; 

    return 0;
}