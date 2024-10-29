#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int final_result;
    int argument ;
    cin >> argument;
    while (n>=0){ // pewnie bardziej optymalne jest rozwiazanie z tablicmi ale zapomnialem ze sa dozwolone
        int temp_result;
        temp_result = argument;
        int a;
        cin >> a;
        int power;
        power = n;
        bool logic = false;
        if (a!=0){
            if (power>1){
                while (power>1){
                    temp_result*=argument;
                    power-=1;
                }
                temp_result*=a;
                power = 515;
            }
            if (power == 1){
                temp_result*=a;
            }
            if (power == 0){
                temp_result = a;
            }
        }
        else{
            temp_result = 0;
        }
        final_result +=temp_result;
        n-=1;
    }
    cout << final_result;
}