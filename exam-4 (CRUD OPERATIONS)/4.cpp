#include <iostream>
using namespace std;

int main(){
    int row, col;
    cout << "Enter the size row and column: ";
    cin >> row >> col;
    int arr[row][col] = {};

    // taking values from user
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << "Enter [" << i << "][" << j << "]th element";
            cin >> arr[i][j];
        }
        cout << "\n";
    }

    // displaying 2d array
    cout << "2D Array :\n";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // row sum
    int user_choice, sum=0;
    cout << "Please Enter the row number you want to sum: ";
    cin >> user_choice;
    // validation
    if (user_choice < 1 || user_choice > row){
        cout << "Please Enter valid range";
        return 1;
    }
    for (int i = 0; i < col; i++){
        sum += arr[user_choice-1][i];
    }

    cout << "Sum of row " << user_choice << " is " << sum << "\n";

    // column sum
    sum=0;
    cout << "Please Enter the column number you want to sum: ";
    cin >> user_choice;
    // validation
    if (user_choice < 1 || user_choice > row){
        cout << "Please Enter valid range";
        return 1;
    }
    for (int i = 0; i < row; i++){
        sum += arr[i][user_choice-1];
    }

    cout << "Sum of column " << user_choice << " is " << sum << "\n";


    return 0;
}