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
    int bigger;
    if (constn1>=constn2){
        bigger=constn1;
    }
    else{
        bigger=constn2;
    }
    int final[bigger+1];
    i=0;
    while (bigger>=0){
        final[i] = 0;
        if (i<=constn1){
            final[i]+=first[i];
        }
        if (i<=constn2){
            final[i]+=second[i];
        }
        i+=1;
        bigger-=1;
    }
    bigger = i;
    i=0;
    while (bigger>0){
        cout << final[i] << endl;
        i+=1;
        bigger-=1; 
    }
}