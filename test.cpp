// Jakub Podhajski
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 0;
    int loose_a = 0;
    int loose_b= 0;
    int loose_c = 0;
    int loose_d = 0;
    float draw_a = 0;
    float draw_b= 0;
    float draw_c = 0;
    float draw_d = 0;
    int win_a = 0;
    int win_b = 0;
    int win_c = 0;
    int win_d = 0;
    while (n!=i){
        i = i + 1;
        char p1,p2; //identity
        char c1,c2; //choice 
        int f1,f2; //sila
        cin >> p1 >> c1 >> f1 >> p2 >> c2 >> f2;
        if (c1 == 'J'){
            if (c2 == 'P')
            {
                if (p1 == 'a')
                {
                    win_a = win_a + 1;
                }
                if (p1 == 'b')
                {
                    win_b = win_b + 1;
                }
                if (p1 == 'c')
                {
                    win_c = win_c + 1;
                }
                if (p1 == 'd')
                {
                    win_d = win_d + 1;
                }
                if (p2 == 'a')
                {
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b')
                {
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c')
                {
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd')
                {
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'S'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'K'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'N'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'J'){
                if (f1>f2){
                    if (p1 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p1 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p1 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p1 == 'd'){
                        win_d = win_d + 1;
                    }
                    if (p2 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p2 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p2 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p2 == 'd'){
                        loose_d = loose_d + 1;
                    }
                }
                if (f1<f2){
                
                    if (p1 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p1 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p1 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p1 == 'd'){
                        loose_d = loose_d + 1;
                    }
                    if (p2 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p2 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p2 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p2 == 'd'){
                        win_d = win_d + 1;
                    }
                }
                if(f1==f2){
                    if (p1 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p1 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p1 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p1 == 'd'){
                        draw_d = draw_d + 1;
                    }
                    if (p2 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p2 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p2 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p2 == 'd'){
                        draw_d = draw_d + 1;
                    }
                }
            }
        }
        if (c1 == 'P'){
            if (c2 == 'S'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'K'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'N'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'J'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'P'){
                if (f1>f2){
                    if (p1 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p1 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p1 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p1 == 'd'){
                        win_d = win_d + 1;
                    }
                    if (p2 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p2 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p2 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p2 == 'd'){
                        loose_d = loose_d + 1;
                    }
                }
                if (f1<f2){
                
                    if (p1 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p1 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p1 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p1 == 'd'){
                        loose_d = loose_d + 1;
                    }
                    if (p2 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p2 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p2 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p2 == 'd'){
                        win_d = win_d + 1;
                    }
                }
                if(f1==f2){
                    if (p1 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p1 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p1 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p1 == 'd'){
                        draw_d = draw_d + 1;
                    }
                    if (p2 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p2 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p2 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p2 == 'd'){
                        draw_d = draw_d + 1;
                    }
                }
            }
        }
        if (c1 == 'S'){
            if (c2 == 'K'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'N'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }         
            if (c2 == 'J'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'P'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'S'){
                if (f1>f2){
                    if (p1 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p1 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p1 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p1 == 'd'){
                        win_d = win_d + 1;
                    }
                    if (p2 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p2 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p2 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p2 == 'd'){
                        loose_d = loose_d + 1;
                    }
                }
                if (f1<f2){
                
                    if (p1 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p1 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p1 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p1 == 'd'){
                        loose_d = loose_d + 1;
                    }
                    if (p2 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p2 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p2 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p2 == 'd'){
                        win_d = win_d + 1;
                    }
                }
                if(f1==f2){
                    if (p1 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p1 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p1 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p1 == 'd'){
                        draw_d = draw_d + 1;
                    }
                    if (p2 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p2 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p2 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p2 == 'd'){
                        draw_d = draw_d + 1;
                    }
                }
            }
        }
        if (c1 == 'K'){
            if (c2 == 'N'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'J'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'P'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'S'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'K'){
                if (f1>f2){
                    if (p1 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p1 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p1 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p1 == 'd'){
                        win_d = win_d + 1;
                    }
                    if (p2 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p2 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p2 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p2 == 'd'){
                        loose_d = loose_d + 1;
                    }
                }
                if (f1<f2){
                
                    if (p1 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p1 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p1 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p1 == 'd'){
                        loose_d = loose_d + 1;
                    }
                    if (p2 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p2 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p2 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p2 == 'd'){
                        win_d = win_d + 1;
                    }
                }
                if(f1==f2){
                    if (p1 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p1 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p1 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p1 == 'd'){
                        draw_d = draw_d + 1;
                    }
                    if (p2 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p2 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p2 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p2 == 'd'){
                        draw_d = draw_d + 1;
                    }
                }
            }
        }
        if (c1 == 'N'){
            if (c2 == 'J'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'P'){
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
            }
            if (c2 == 'S'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'K'){
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
            }
            if (c2 == 'N'){
                if (f1>f2){
                    if (p1 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p1 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p1 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p1 == 'd'){
                        win_d = win_d + 1;
                    }
                    if (p2 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p2 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p2 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p2 == 'd'){
                        loose_d = loose_d + 1;
                    }
                }
                if (f1<f2){
                
                    if (p1 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p1 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p1 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p1 == 'd'){
                        loose_d = loose_d + 1;
                    }
                    if (p2 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p2 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p2 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p2 == 'd'){
                        win_d = win_d + 1;
                    }
                }
                if(f1==f2){
                    if (p1 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p1 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p1 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p1 == 'd'){
                        draw_d = draw_d + 1;
                    }
                    if (p2 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p2 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p2 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p2 == 'd'){
                        draw_d = draw_d + 1;
                    }
                }
            }
        }
    }
    if (loose_a + draw_a + win_a > 0){
        cout << "gracz a" << endl;
        if (win_a > 0){
            cout << "    wygrane: " << (100*win_a)/(loose_a + draw_a + win_a)<<"%"<< endl;
        }
        if (draw_a > 0){
            cout << "    remisy: " << (100*draw_a)/(loose_a + draw_a + win_a)<<"%"<< endl;
        }
        if (loose_a > 0){
            cout << "    przegrane: " << (100*loose_a)/(loose_a + draw_a + win_a)<<"%"<< endl;
        }
        cout << endl;
    }
    if (loose_b + draw_b + win_b > 0){
        cout << "gracz b" << endl;

        if (win_b > 0){
            cout << "    wygrane: " << (100*win_b)/(loose_b + draw_b + win_b)<<"%"<< endl;
        }
        if (draw_b > 0){
            cout << "    remisy: " << (100*draw_b)/(loose_b + draw_b + win_b)<<"%"<< endl;
        }
        if (loose_b > 0){
            cout << "    przegrane: " << (100*loose_b)/(loose_b + draw_b + win_b)<<"%"<< endl;
        }
        cout << endl;

    }
    if (loose_c + draw_c + win_c > 0){
        cout << "gracz c" << endl;
        if (win_c > 0){
            cout << "    wygrane: " << (100*win_c)/(loose_c + draw_c + win_c)<<"%"<< endl;
        }
        if (draw_c > 0){
            cout << "    remisy: " << (100*draw_c)/(loose_c + draw_c + win_c)<<"%"<< endl;
        }
        if (loose_c > 0){
            cout << "    przegrane: " << (100*loose_c)/(loose_c + draw_c + win_c)<<"%"<< endl;
        }
        cout << endl;

    }
    if (loose_d + draw_d + win_d > 0){
        cout << "gracz d" << endl;
        if (win_d > 0){
            cout << "    wygrane: " << (100*win_d)/(loose_d + draw_d + win_d)<<"%"<< endl;
        }
        if (draw_d > 0){
            cout << "    remisy: " << (100*draw_d)/(loose_d + draw_d + win_d)<<"%"<< endl;
        }
        if (loose_d > 0){
            cout << "    przegrane: " << (100*loose_d)/(loose_d + draw_d + win_d)<<"%"<< endl;
        }
        cout << endl;
  
    }
}