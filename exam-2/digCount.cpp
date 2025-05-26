#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter any number: ";
    cin >> n;

    int counter = 0;

    while (n > 0){
        n/=10;
        counter++;
    }

    cout << "total digits in number: " << counter;

    return 0;
}