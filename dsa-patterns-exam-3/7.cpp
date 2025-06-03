#include <iostream>
using namespace std;

int main(){

    for (int i = 1; i <= 7; i++){
        for (int j = 1; j <= 6; j++){
            if ((i == 1) || (j == 1) || (i==4) || (i == 7)){
                cout << "A ";
            } else {
                cout << " ";
            }
        }
        
        cout << "\n";
    }

    return 0;
}
