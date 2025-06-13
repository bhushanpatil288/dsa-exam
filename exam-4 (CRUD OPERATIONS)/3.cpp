#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of an Array: ";
    cin >> size;
    int arr[size] = {};

    // taking values from the user
    for (int i = 0; i < size; i++){
        cout << "Enter [" << i << "] value: ";
        cin >> arr[i]; 
    }

    // displaying an array
    cout << "\nArray: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    // displaying max element
    int max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    cout << "\nMax element: " << max;

    // displaying min element
    int min = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    cout << "\nMin element: " << min;
    return 0;
}