#include <iostream> 
using namespace std; 
 
int main(){ 
    int n1; 
    int n2; 
    cin >> n1; 
    int first[n1]; 
    int i = 0; 
    while (n1 != i){ 
        int number; 
        cin >> number; 
        first[i] = number; 
        i = i + 1; 
    } 
    cin >> n2; 
    int second[n2]; 
    int final[n1+n2]; 
    i = 0; 
    while(n2 != i){ 
 
        int number; 
        cin >> number; 
        second[i] = number; 
        i = i + 1; 
    } 
    i = 0;
    int k = 0;
    int j =0;
    while (n1!=i){
        j = 0;
        bool logic = true;
        while (n2!=j){
            if (first[i] == second[j]){
                logic = false;
            }
            j = j + 1;
        }
        if (logic == true){
            final[k] = first[i];
            k = k + 1;
        }
        i = i + 1;
    }
    i = 0;
    while (n2!=i){
        j = 0;
        bool logic = true;
        while (n1!=j){
            if (second[i] == first[j]){
                logic = false;
            }
            j = j + 1;
        }
        if (logic == true){
            final[k] = second[i];
            k = k + 1;
        }
        i = i + 1;
    }
    j = 0;
    while (j!=k){
        cout << final[j]<< endl;
        j = j + 1;
    }
}