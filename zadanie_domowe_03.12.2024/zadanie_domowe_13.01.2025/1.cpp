#include <iostream>
using namespace std;

int Count(short int a){
    int result = 0;
    for (int i = 0; i<16;i++){
        result += (a >> i) & 1;
    }
    return result;
}
int Even(short int a){
    int count = Count(a);
    int result = a;
    if (count % 2 == 1){
        for(int i = 0; i < 16; i++){
            if (((a >> i) & 1) == 0){
                result += 1 << i;
                break;
            }
        }
    }
    return result;
}
int Shift_right(short int number, short int shift){
    for (int i = 0; i < shift; i++){
        int temp = (number & 1);
        number >>= 1;
        temp <<= 15;
        number += temp;
    }
    return number;
}
int Shift_left(short int number, short int shift){
    for (int i = 0; i < shift; i++){
        int temp = (number & (1 << 15));
        number <<= 1;
        temp >>= 15;
        number += temp;
    }
    return number;
}
int Multi_3_5(short int number){
    int result = (number << 1) + x;
    result += number >> 1;
    return result;
}
int Xor(short int a, short int b){
    return (a | b) & ~(a & b);
}
int main(){
    cout << Shift_left(-5,1);
}