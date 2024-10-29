#include <iostream>
using namespace std;

int main(){//odwrotnie wspolczynniki niz w innych programach
    int n1;
    int i;
    int constn1;
    i = 0;
    cin >> n1;
    constn1 = n1;
    int first[n1+1];
    while (n1>=0){
        cin >> first[i];
        n1-=1;
        i+=1;
    }
    int deg;
    cin >> deg;
    
    while (deg> 0){
        i=0;
        while(i!=constn1){
            first[i] = first[i+1]*(i+1);
            i+=1;
        }
        first[i]=0;
        deg-=1;
    }
    i=0;
    cout << "WYNIK" << endl;
    while (i!=constn1+1){
        cout << first[i] << endl;
        i+=1;
    }

}