//Jakub Podhajski
#include <iostream>
using namespace std;

int main(){
    int special;
    cin >> special;
    int n;
    cin >> n;
    int anws[n];
    int i = 0;
    while (n>0){
        int temp;
        temp = 0;
        temp+=special;
        n-=1;
        int number;
        cin >> number;
        if (number<0)
            number =-number;
        while (temp>=number)
            temp-=number;
        if (number==temp or temp == 0)
            anws[i] = 1;
        else{
            anws[i] = 0;
        }
        i+=1;

    }
    int j;
    j = 0;
    while (j<i){
        if (anws[j]==0)
        {
            cout << "NIE" << endl;
        }
        else
        {
            cout << "TAK" << endl;
        }
        j+=1;
    }
}
