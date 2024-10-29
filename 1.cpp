#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    bool first_iteration = true;
    do{
        if (first_iteration == false){
            x+=1;
            cout << x << endl;
        }
        else
            first_iteration = false;
    }
    while(x<10);
    cout << x;
}
