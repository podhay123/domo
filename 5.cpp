#include <iostream>
using namespace std;

int main(){
    int n1;
    int n2;
    int constn1;
    int constn2;
    int i;
    i = 0;
    cin >> n1;
    constn1 = n1;
    int first[n1+1];
    while (n1>=0){
        cin >> first[i];
        n1-=1;
        i+=1;
    }
    cin >> n2;
    constn2 = n2;
    i = 0;
    int second[n2+1];
    while (n2>=0){
        cin >> second[i];
        n2-=1;
        i+=1;
    }
    n1 = constn1;
    int final[constn1+constn2+1] = {0};
    while (n1>=0){
        n2 = constn2;
        
        while(n2>=0){
            final[n1+n2]+=first[n1]*second[n2];
            n2-=1;
        }
        n1-=1;
    }
    i=0;
    cout << "WYNIK" << endl;
    while (i!=constn1+constn2+1){
        cout << final[i] << endl;
        i+=1;
    }
}