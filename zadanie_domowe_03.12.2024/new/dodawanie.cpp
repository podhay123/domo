#include <iostream>
using namespace std;

void add(char num1[], char num2[], int len1, int len2){
    int bigger = 0;
    if (len1 >= len2)
        bigger = bigger + len1;
    else
        bigger = bigger + len2;
    int final_array[bigger+1] = {0};
    for (int i = 0; i != len1; i++){
        char x;
        x = num1[i];
        if ( x == '1')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 1;
        if ( x == '2')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 2;
        if ( x == '3')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 3;
        if ( x == '4')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 4;
        if ( x == '5')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 5;
        if ( x == '6')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 6;
        if ( x == '7')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 7;
        if ( x == '8')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 8;
        if ( x == '9')
            final_array[len1 - i -1] =  final_array[len1 - i -1] + 9;   
    }
    for (int i = 0; i != len2; i++){
        char x;
        x = num2[i];
        if ( x == '1')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 1;
        if ( x == '2')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 2;
        if ( x == '3')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 3;
        if ( x == '4')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 4;
        if ( x == '5')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 5;
        if ( x == '6')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 6;
        if ( x == '7')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 7;
        if ( x == '8')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 8;
        if ( x == '9')
            final_array[len2 - i -1] =  final_array[len2 - i -1] + 9;
    }
    for (int i = 0; i != bigger; i++){
        if (final_array[i] > 9){
            final_array[i+1] = final_array[i+1] + 1;
            final_array[i] = final_array[i] - 10;
        }
    }
    bool after_0 = false;
    int zero_counter = 0;
    for (int i = bigger; i >= 0; i--){
        if (final_array[i] == 0 && after_0 == false){
            after_0 = false;
            zero_counter = zero_counter + 1;
        }
        else{
            after_0 = true;
            cout << final_array[i];
        }
    }
    if (zero_counter == bigger)
        cout << 0;
}

int main(){
    int len1,len2;// ograniczeniem jest to ze dlugosc cyfr tej liczby jest w int czyli nie moze byc to liczba nieskonczenie wielka 
    cin >> len1;
    char anum1[len1+1]; //tylko dodatnie :C
    for (int i = 0; i != len1; i++){
        char num;
        cin >> num;
        anum1[i] = num; 
    }

    cin >> len2;
    char anum2[len2+1];
    for (int i = 0; i != len2; i++){
        char num;
        cin >> num;
        anum2[i] = num; 
    }

    add(anum1, anum2, len1, len2);
}