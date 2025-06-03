#include <iostream>
using namespace std;

int main(){
    int n = 25;
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= i; j++){
            if (i % 2 == 0){
                cout << "* ";
                n++;
            } else {
                cout << n++ << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}


// 25
// * *
// 28 29 30
// * * * *
// 35 36 37 38 39