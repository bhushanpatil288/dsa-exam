#include <iostream>
using namespace std;

int main(){

    int n = 1;
    for (int i = 1; i <= 5; i++){
        i % 2 == 0 ? n = 0 : n = 1;
        for (int s = 5; s > i; s--){
            cout << "* ";
        }
        for (int j = 1; j <= i; j++){
            cout << n << " ";
            n == 1 ? n = 0 : n = 1;
        }
        cout << "\n";
    }

    return 0;
}

// * * * * 1
// * * * 0 1
// * * 1 0 1
// * 0 1 0 1
// 1 0 1 0 1
