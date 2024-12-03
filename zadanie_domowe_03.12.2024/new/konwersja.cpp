#include <iostream>
using namespace std;

int power(int num, int pow){
    int final_num = num;
    if (pow > 0){
        for(int i = 0; i!=pow-1; i++){
            final_num = final_num*num;
        }
    }
    else
        final_num = 1;
    return final_num;
}

void convert(int from, int number, int to){
    if ( from != 10 ){
        int number_of_digits = 0;
        int temp = number;
        while( temp > 0 ){
            number_of_digits = number_of_digits + 1;
            temp = temp/10;
        }
        temp = number;
        int array_of_digits[number_of_digits];
        for (int i = 0; i != number_of_digits; i++){
            array_of_digits[i] = temp % 10;
            temp = temp / 10;
        }
        temp = 0;
        for (int i = 0; i != number_of_digits; i++){
            temp = temp + power(from,i)*array_of_digits[i];
        }

        
        number = temp;
    }
    int i = 0;
    int tmp = number;
    int number_of_digits = 0;
    while ( tmp != 0 ){
        tmp = tmp/to;
        number_of_digits = number_of_digits + 1;
    }
    int final_array[number_of_digits];
    i = 0;
    while( number != 0 ){
        final_array[i] = number % to;
        number = number/to;
        i++;
    }
    for (int i = number_of_digits -1; i != -1; i--){
        if (final_array[i] < 10){
            cout << final_array[i];
        }
        if (final_array[i] == 10)
            cout << "A";
        
        if (final_array[i] == 11)
            cout << "B";
        
        if (final_array[i] == 12)
            cout << "C";
        
        if (final_array[i] == 13)
            cout << "D";
        if (final_array[i] == 14)
            cout << "E";
        if (final_array[i] == 15)
            cout << "F";
        
    }    
}

int main(){
    int from, number, to;
    cin >> from >> number >> to;
    convert(from, number, to);
}