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
    int j = 0; 
    while (n1 != j){ 
        int logic = 0;  
        int k = 0; 
        while (n2 != k){ 
            if (second[k] == first[j]){ 
                logic = 1; 
                k = n2; 
            } 
            else{ 
                k = k + 1; 
            } 
        } 
        if (logic == 1){ 
            final[i] = first[j]; 
            i = i + 1; 
        } 
        j = j + 1; 
    } 
    int n3 = i; 
    j = 0; 
    while(j != i){ 
        cout << final[j] << endl; 
        j = j + 1; 
    } 
} 