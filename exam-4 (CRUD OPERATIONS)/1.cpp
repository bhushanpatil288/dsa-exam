#include <iostream>
using namespace std;

int main(){
    int size = 3;
    cout << "Enter the size of an Array: ";
    cin >> size;
    int arr[size] = {};

    // taking values from user
    for (int i = 0; i < size; i++){
        cout << "Enter [" << i << "] value: ";
        cin >> arr[i]; 
    }

    // displaying Array
    cout << "\nArray : ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    // printing Negative elements
    int neg_count = 0;
    cout << "\nNegative elements = ";
    for (int i = 0; i < size; i++){
        if (arr[i] < 0){
            cout << arr[i] << " ";
            neg_count+=1;
        }
    }
    cout << "\nNumber of negative elements: " << neg_count;

    // printing positive elements
    int pos_count = 0;
    cout << "\nPositive elements = ";
    for (int i = 0; i < size; i++){
        if (arr[i] > 0){
            cout << arr[i] << " ";
            pos_count += 1;
        }
    }

    cout << "\nNumber of positive elements: " << pos_count;
    return 0;
}