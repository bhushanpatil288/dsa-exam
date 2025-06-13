#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of an Array: ";
    cin >> size;
    int arr[size] = {};

    // taking values from user
    for (int i = 0; i < size; i++){
        cout << "Enter [" << i << "] value: ";
        cin >> arr[i]; 
    }

    // displaying an array
    cout << "Array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    // finding odd elements and adding to new array
    int oddArr[size] = {};
    int count = 0;
    for (int i = 0; i< size; i++){
        if (arr[i]%2 != 0){
            oddArr[count++] = arr[i];
        }
    }

    cout << "\nOdd elements = ";
    for (int i = 0; i < count; i++){
        cout << oddArr[i] << " ";
    }

    // finding Even elements and adding to new array
    int evenArray[size] = {};
    count = 0;
    for (int i = 0; i< size; i++){
        if (arr[i]%2 == 0){
            evenArray[count++] = arr[i];
        }
    }

    cout << "\nEven elements = ";
    for (int i = 0; i < count; i++){
        cout << evenArray[i] << " ";
    }
    return 0;
}