#include <iostream>
using namespace std;

int main(){
    int x = 5;
    switch (x){
        case 1:
            cout << 1 << endl;

        case 5:
            cout << 5 << endl;

        case 10:
            cout << 10 << endl;
        default:
            cout << "dupa" << endl;
    }
}