//Jakub Podhajski
#include <iostream>
using namespace std;

struct PLACE{
    unsigned short int amount;
    unsigned char label[2];
};
struct SHELF{
    PLACE place[128];
    unsigned short int amount;
};
struct RACK{
    SHELF shelf[128];
    unsigned short int amount;
};
struct WAREHOUSE{
    unsigned short int amount;
    RACK rack[128];
    SHELF handy_shelf;
    long long int total;
}; 
struct DEPOT{//w sensie sklad xd
    WAREHOUSE warehouse[128];
    SHELF handy_shelf;
    RACK handy_rack;
    long long int total;
    unsigned short int amount;
}depot;
bool Validate(long long int num, long long int limit){
    if (num >= 0 && num <= limit){
        return true;
    }
    return false;
}
void SET_AP(long long int w, long long int r, long long int s, long long int P){
    if (!(Validate(w,128) && Validate(r,128) && Validate(s, 128) && Validate(P,128))){
        cout << "error"<< endl;
        return;
    }

    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].amount <= r){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].shelf[s].amount >= P){//kasujemy nadmiar
        for (long long int p = P; p < depot.warehouse[w].rack[r].shelf[s].amount; p++)
        {
            depot.warehouse[w].total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
            depot.total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
            depot.warehouse[w].rack[r].shelf[s].place[p].amount = 0;
        }
        depot.warehouse[w].rack[r].shelf[s].amount = P;
    }
    else{//dodajemy brakujace
        for (long long int p = depot.warehouse[w].rack[r].shelf[s].amount; p < P; p++){
            depot.warehouse[w].rack[r].shelf[s].place[p].amount = 0;
            depot.warehouse[w].rack[r].shelf[s].place[p].label[0] = '\0';
        }
        depot.warehouse[w].rack[r].shelf[s].amount = P;
    }
}
void SET_AS(long long int w, long long int r, long long int S, long long int P){
    if (!(Validate(w,128) && Validate(r,128) && Validate(S, 128) && Validate(P,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].amount <= r){
        cout << "error"<< endl;
        return;
    }
    for (long long int s = S ; s < depot.warehouse[w].rack[r].amount; s++){
        for (long long int p = 0 ; p < depot.warehouse[w].rack[r].shelf[s].amount; p++)
        {
            depot.warehouse[w].total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
            depot.total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
            depot.warehouse[w].rack[r].shelf[s].place[p].amount = 0;
        }
        depot.warehouse[w].rack[r].shelf[s].amount = 0;

    }
    depot.warehouse[w].rack[r].amount = S;
    for (long long int s = 0; s < S; s++){
        SET_AP(w, r, s, P);
    }
    depot.warehouse[w].rack[r].amount = S;
    
}
void SET_AR(long long int w, long long int R, long long int S, long long int P){
    if (!(Validate(w,128) && Validate(R,128) && Validate(S, 128) && Validate(P,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    for (long long int r = R ; r < depot.warehouse[w].amount; r++){
        for (long long int s = 0 ; s < depot.warehouse[w].rack[r].amount; s++){
            for (long long int p = 0 ; p < depot.warehouse[w].rack[r].shelf[s].amount; p++)
            {
                depot.warehouse[w].total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
                depot.total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
                depot.warehouse[w].rack[r].shelf[s].place[p].amount = 0;
            }
            depot.warehouse[w].rack[r].shelf[s].amount = 0;
        }
        depot.warehouse[w].rack[r].amount = 0;
    }
    depot.warehouse[w].amount = R;

    
    for (long long int r = 0; r < R; r++){
        SET_AS(w, r, S, P);
    }
    depot.warehouse[w].amount = R;
    
}
void SET_AW(long long int W, long long int R, long long int S, long long int P){

    if (!(Validate(W,128) && Validate(R,128) && Validate(S, 128) && Validate(P,128))){
        cout << "error"<< endl;
        return;
    }
    for (long long int w = W ; w < depot.amount; w++){
        for (long long int p = 0; p < depot.warehouse[w].handy_shelf.amount; p++){
            depot.warehouse[w].total -= depot.warehouse[w].handy_shelf.place[p].amount;
            depot.total -= depot.warehouse[w].handy_shelf.place[p].amount;
            depot.warehouse[w].handy_shelf.place[p].amount = 0;
        }
        depot.warehouse[w].handy_shelf.amount = 0;
        for (long long int r = 0; r < depot.warehouse[w].amount; r++){
            for (long long int s = 0; s < depot.warehouse[w].rack[r].amount; s++){
                for (long long int p = 0; p < depot.warehouse[w].rack[r].shelf[s].amount; p++)
                {
                    depot.warehouse[w].total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
                    depot.total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
                    depot.warehouse[w].rack[r].shelf[s].place[p].amount = 0;
                }
                depot.warehouse[w].rack[r].shelf[s].amount = 0;
            }
            // depot.warehouse[w].rack[r].amount = 0;
        }
    }
    depot.amount = W;
    
    for (long long int w = 0; w < W; w++){
        depot.warehouse[w].total = 0;
        SET_AR(w, R, S, P);
    }
    depot.amount = W;
    
}
void SET_HW(long long int w, long long int  P){
    if (!(Validate(w,128) && Validate(P, 128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].handy_shelf.amount >= P){//kasujemy nadmiar
        for (long long int p = P; p < depot.warehouse[w].handy_shelf.amount; p++)
        {
            depot.warehouse[w].total -= depot.warehouse[w].handy_shelf.place[p].amount;
            depot.total -= depot.warehouse[w].handy_shelf.place[p].amount;
            depot.warehouse[w].handy_shelf.place[p].amount = 0;
        }
        depot.warehouse[w].handy_shelf.amount = P;
    }
    else{//dodajemy brakujace
        for (long long int p = depot.warehouse[w].handy_shelf.amount; p < P; p++){
            depot.warehouse[w].handy_shelf.place[p].amount = 0;
            depot.warehouse[w].handy_shelf.place[p].label[0] = '\0';
        }
        depot.warehouse[w].handy_shelf.amount = P;
    }
}
void SET_HAP(long long int s, long long int P){//pomocnicza funckja do SET_HR 
    if (!(Validate(s,128)) && Validate(P, 128) ){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.shelf[s].amount >= P){//kasujemy nadmiar
        for (long long int p = P; p < depot.handy_rack.shelf[s].amount; p++)
        {
            depot.total -= depot.handy_rack.shelf[s].place[p].amount;
            depot.handy_rack.shelf[s].place[p].amount = 0;
        }
        depot.handy_rack.shelf[s].amount = P;
    }
    else{//dodajemy brakujace
        for (long long int p = depot.handy_rack.shelf[s].amount; p < P; p++){
            depot.handy_rack.shelf[s].place[p].amount = 0;
            depot.handy_rack.shelf[s].place[p].label[0] = '\0';
        }
        depot.handy_rack.shelf[s].amount = P;
    }
}
void SET_HR(long long int S, long long int  P){
    if (!(Validate(S, 128) && Validate(P,128))){
        cout << "error"<< endl;
        return;
    }
    for (long long int s = S; s < depot.handy_rack.amount; s++){
        for (long long int p = 0; p < depot.handy_rack.shelf[s].amount; p++)
        {
            depot.total -= depot.handy_rack.shelf[s].place[p].amount;
            depot.handy_rack.shelf[s].place[p].amount = 0;
        }
        depot.handy_rack.shelf[s].amount = 0;
    }
    depot.handy_rack.amount = S;
    for (long long int s = 0; s < S; s++){
        SET_HAP(s, P);
    }
    depot.handy_rack.amount = S;
    
}
void SET_HS(long long int P){
    if (!Validate(P,128)){
        cout << "error"<< endl;
        return;
    }

    if (depot.handy_shelf.amount >= P){//kasujemy nadmiar
        for (long long int p = P; p < depot.handy_shelf.amount; p++)
        {
            depot.total -= depot.handy_shelf.place[p].amount;
            depot.handy_shelf.place[p].amount = 0;
        }
        depot.handy_shelf.amount = P;
    }
    else{//dodajemy brakujace
        for (long long int p = depot.handy_shelf.amount; p < P; p++){
            depot.handy_shelf.place[p].amount = 0;
            depot.handy_shelf.place[p].label[0] = '\0';
        }
        depot.handy_shelf.amount = P;
    }
}
void PUT_W(long long int w, long long int r, long long int s, long long int p, long long int A){
    if (!(Validate(w,128) && Validate(r,128) && Validate(s, 128) && Validate(p,128)) && Validate(A, 65535)){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].amount <= r){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].shelf[s].amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].shelf[s].place[p].amount + A > 65535){
        depot.warehouse[w].total += 65535 - depot.warehouse[w].rack[r].shelf[s].place[p].amount;
        depot.total += 65535 - depot.warehouse[w].rack[r].shelf[s].place[p].amount;
        depot.warehouse[w].rack[r].shelf[s].place[p].amount = 65535;
    }
    else{
        depot.warehouse[w].rack[r].shelf[s].place[p].amount += A;
        depot.total += A;
        depot.warehouse[w].total += A;
    }
}
void PUT_H(long long int w, long long int p, long long int A){
    if (!(Validate(w,128) && Validate(p,128) && Validate(A, 65535))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].handy_shelf.amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].handy_shelf.place[p].amount + A > 65535){
        depot.warehouse[w].total += 65535 - depot.warehouse[w].handy_shelf.place[p].amount;
        depot.total += 65535 - depot.warehouse[w].handy_shelf.place[p].amount;
        depot.warehouse[w].handy_shelf.place[p].amount = 65535;
    }
    else{
        depot.warehouse[w].handy_shelf.place[p].amount += A;
        depot.total += A;
        depot.warehouse[w].total += A;
    }
}
void PUT_R(long long int s, long long int p, long long int A){
    if (!(Validate(s,128) && Validate(p,128) && Validate(A, 65535))){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.shelf[s].amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (A < 0){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.shelf[s].place[p].amount + A > 65535){
        depot.total += 65535 - depot.handy_rack.shelf[s].place[p].amount;
        depot.handy_rack.shelf[s].place[p].amount = 65535;
    }
    else{
        depot.handy_rack.shelf[s].place[p].amount += A;
        depot.total += A;
    }
}
void PUT_S(long long int p, long long int A){
    if (!(Validate(p,128) && Validate(A, 65535))){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_shelf.amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (A < 0){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_shelf.place[p].amount + A > 65535){
        depot.total += 65535 - depot.handy_shelf.place[p].amount;
        depot.handy_shelf.place[p].amount = 65535;
    }
    else{
        depot.handy_shelf.place[p].amount += A;
        depot.total += A;
    }
}
void FILL(long long int W, long long int R, long long int S, long long int P, long long int A){
    if (!(Validate(W,128) && Validate(R,128) && Validate(S, 128) && Validate(P,128) && Validate(A, 65535))){
        cout << "error"<< endl;
        return;
    }
    depot.total = 0;
    depot.amount = W;
    depot.handy_shelf.amount = P;
    for (long long int p = 0; p < depot.handy_shelf.amount; p++){
        depot.total += A;
        depot.handy_shelf.place[p].amount = A;
        depot.handy_shelf.place[p].label[0] = '\0';
    }
    depot.handy_rack.amount = S;
    for (long long int s = 0; s < S; s++){
        depot.handy_rack.shelf[s].amount = P;
        for (long long int p = 0; p < P; p++){
            depot.total += A;
            depot.handy_rack.shelf[s].place[p].amount = A;
            depot.handy_rack.shelf[s].place[p].label[0] = '\0';
        }
    }
    for (long long int w = 0; w < W; w++){
        depot.warehouse[w].total = 0;
        depot.warehouse[w].amount = R;
        depot.warehouse[w].handy_shelf.amount = P;
        for (long long int p = 0; p < depot.warehouse[w].handy_shelf.amount; p++){
            depot.total += A;
            depot.warehouse[w].total += A;
            depot.warehouse[w].handy_shelf.place[p].amount = A;
            depot.warehouse[w].handy_shelf.place[p].label[0] = '\0';
        }
        for (long long int r = 0; r < R; r++){
            depot.warehouse[w].rack[r].amount = S;
            for (long long int s = 0; s < S; s++){
                depot.warehouse[w].rack[r].shelf[s].amount = P;
                for (long long int p = 0; p < P; p++){
                    depot.total += A;
                    depot.warehouse[w].total += A;
                    depot.warehouse[w].rack[r].shelf[s].place[p].amount = A;
                    depot.warehouse[w].rack[r].shelf[s].place[p].label[0] = '\0';
                }
            }
        }
    }
}
void POP_W(long long int w, long long int r, long long int s, long long int p, long long int A){
    if (!(Validate(w,128) && Validate(r,128) && Validate(s, 128) && Validate(p,128)) && Validate(A, 65535)){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].amount <= r){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].shelf[s].amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].shelf[s].place[p].amount - A < 0){
        depot.warehouse[w].total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
        depot.total -= depot.warehouse[w].rack[r].shelf[s].place[p].amount;
        depot.warehouse[w].rack[r].shelf[s].place[p].amount = 0;
    }
    else{
        depot.warehouse[w].rack[r].shelf[s].place[p].amount -= A;
        depot.total -= A;
        depot.warehouse[w].total -= A;
    }
}
void POP_H(long long int w, long long int p, long long int A){
    if (!(Validate(w,128) && Validate(p,128) && Validate(A, 65535))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].handy_shelf.amount <= p){
        cout << "error"<< endl;
        return;
    }

    if (depot.warehouse[w].handy_shelf.place[p].amount - A < 0){
        depot.warehouse[w].total -= depot.warehouse[w].handy_shelf.place[p].amount;
        depot.total -= depot.warehouse[w].handy_shelf.place[p].amount;
        depot.warehouse[w].handy_shelf.place[p].amount = 0;
    }
    else {
        depot.warehouse[w].handy_shelf.place[p].amount -= A;
        depot.total -= A;
        depot.warehouse[w].total -= A;
    }
}
void POP_R(long long int s, long long int p, long long int A){
    if (!(Validate(s,128) && Validate(p,128)  && Validate(A, 65535))){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.shelf[s].amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.shelf[s].place[p].amount - A < 0){
        depot.total -= depot.handy_rack.shelf[s].place[p].amount;
        depot.handy_rack.shelf[s].place[p].amount = 0;
    }
    else{
        depot.handy_rack.shelf[s].place[p].amount -= A;
        depot.total -= A;
    }
}
void POP_S(long long int p, long long int A){
    if (!(Validate(p, 128) && Validate(A, 65535))){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_shelf.amount <= p){
        cout << "error"<< endl;
        return;
    }

    if (depot.handy_shelf.place[p].amount - A < 0){
        depot.total -= depot.handy_shelf.place[p].amount;
        depot.handy_shelf.place[p].amount = 0;
    }
    else{
        depot.handy_shelf.place[p].amount -= A;
        depot.total -= A;
    }
}
void GET_E(){
    cout << depot.total << endl;
}
void GET_W(long long int w){
    if (!Validate(w,128)){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    cout << depot.warehouse[w].total << endl;
}
void GET_RW(long long int w, long long int r){
    long long int result = 0;
    if (!(Validate(w,128) && Validate(r, 128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].amount <= r){
        cout << "error"<< endl;
        return;
    }
    for (long long int s = 0; s < depot.warehouse[w].rack[r].amount; s++){
        for (long long int p = 0; p < depot.warehouse[w].rack[r].shelf[s].amount; p++){
            result += depot.warehouse[w].rack[r].shelf[s].place[p].amount;
        }
    }
    cout << result << endl;
}
void GET_RH(){
    long long int result = 0;
    for (long long int s = 0; s < depot.handy_rack.amount; s++){
        for (long long int p = 0; p < depot.handy_rack.shelf[s].amount; p++){
            result += depot.handy_rack.shelf[s].place[p].amount;
        }
    }
    cout << result << endl;
}
void GET_SW(long long int w, long long int r, long long int s){
    long long int result = 0;
    if (!(Validate(w,128) && Validate(r, 128) && Validate(s, 128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].amount <= r){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].amount <= s){
        cout << "error"<< endl;
        return;
    }
    for (long long int p = 0; p < depot.warehouse[w].rack[r].shelf[s].amount; p++){
        result += depot.warehouse[w].rack[r].shelf[s].place[p].amount;
    }
    cout << result << endl;
}
void GET_SH(long long int w){
    long long int result = 0;
    if (!Validate(w,128)){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    for (long long int p = 0; p < depot.warehouse[w].handy_shelf.amount; p++){
        result += depot.warehouse[w].handy_shelf.place[p].amount;
    }
    cout << result << endl;
}
void GET_SR(long long int s){
    if (depot.handy_rack.amount <= s){
        cout << "error"<< endl;
        return;
    }
    long long int result = 0;
    for (long long int p = 0; p < depot.handy_rack.amount; p++){
        result += depot.handy_rack.shelf[s].place[p].amount;
    }
    cout << result << endl;
}
void GET_S(){
    long long int result = 0;
    for (long long int p = 0; p < depot.handy_shelf.amount; p++){
        result += depot.handy_shelf.place[p].amount;
    }
    cout << result << endl;
}
void SET_LW(long long int w, long long int r, long long int s, long long int p, unsigned char dd[3]){
    if (!(Validate(w,128) && Validate(r,128) && Validate(s, 128) && Validate(p,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].amount <= r){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].shelf[s].amount <= p){
        cout << "error"<< endl;
        return;
    }
    depot.warehouse[w].rack[r].shelf[s].place[p].label[0] = dd[0];
    depot.warehouse[w].rack[r].shelf[s].place[p].label[1] = dd[1];
}
void GET_LW(long long int w, long long int r, long long int s, long long int p){
    if (!(Validate(w,128) && Validate(r,128) && Validate(s, 128) && Validate(p,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].amount <= r){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].shelf[s].amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].rack[r].shelf[s].place[p].label[0] != '\0')
        cout << depot.warehouse[w].rack[r].shelf[s].place[p].label[0] << depot.warehouse[w].rack[r].shelf[s].place[p].label[1] << endl;
    else
        cout << "--" << endl;
}
void SET_LH(long long int w, long long int p, unsigned char dd[3]){
    if (!(Validate(w,128) && Validate(p,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].handy_shelf.amount <= p){
        cout << "error"<< endl;
        return;
    }
    depot.warehouse[w].handy_shelf.place[p].label[0] = dd[0];
    depot.warehouse[w].handy_shelf.place[p].label[1] = dd[0];
}
void GET_LH(long long int w, long long int p){
    if (!(Validate(w,128) && Validate(p,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.amount <= w){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].handy_shelf.amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (depot.warehouse[w].handy_shelf.place[p].label[0] != '\0')
        cout << depot.warehouse[w].handy_shelf.place[p].label[0] << depot.warehouse[w].handy_shelf.place[p].label[1] << endl;
    else
        cout << "--" << endl;
}
void SET_LR(long long int s, long long int p, unsigned char dd[3]){
    if (!(Validate(s,128) && Validate(p,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.shelf[s].amount <= p){
        cout << "error"<< endl;
        return;
    }
    depot.handy_rack.shelf[s].place[p].label[0] = dd[0];
    depot.handy_rack.shelf[s].place[p].label[1] = dd[1];
}
void GET_LR(long long int s, long long int p){
    if (!(Validate(s,128) && Validate(p,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.amount <= s){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.shelf[s].amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_rack.shelf[s].place[p].label[0] != '\0')
        cout << depot.handy_rack.shelf[s].place[p].label[0] << depot.handy_rack.shelf[s].place[p].label[1] << endl;
    else
        cout << "--" << endl;
}
void SET_LS(long long int p, unsigned char dd[3]){
    if (!(Validate(p,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_shelf.amount <= p){
        cout << "error"<< endl;
        return;
    }
    depot.handy_shelf.place[p].label[0] = dd[0];
    depot.handy_shelf.place[p].label[1] = dd[1];
}

void GET_LS(long long int p){
    if (!(Validate(p,128))){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_shelf.amount <= p){
        cout << "error"<< endl;
        return;
    }
    if (depot.handy_shelf.place[p].label[0] != '\0')
        cout << depot.handy_shelf.place[p].label[0] << depot.handy_shelf.place[p].label[1] <<endl;
    else
        cout << "--" << endl;
}


int main(){
    depot.total = 0;
    depot.amount = 0;
    while (true){
        char command[8];
        cin >> command;
        if (command[0] == 'S' && command[4] == 'A' && command[5] == 'P'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            cin >> W >> R >> S >> P;
            SET_AP(W, R, S, P);
        }
        else if (command[0] == 'S' && command[4] == 'A' && command[5] == 'S'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            cin >> W >> R >> S >> P;
            SET_AS(W, R, S, P);
        }
        else if (command[0] == 'S' && command[4] == 'A' && command[5] == 'R'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            cin >> W >> R >> S >> P;
            SET_AR(W, R, S, P);
        }
        else if (command[0] == 'S' && command[4] == 'A' && command[5] == 'W'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            cin >> W >> R >> S >> P;
            SET_AW(W, R, S, P);
        }
        else if (command[0] == 'S' && command[4] == 'H' && command[5] == 'S'){
            long long int P;
            cin >> P;
            SET_HS(P);
        }
        else if (command[0] == 'S' && command[4] == 'H' && command[5] == 'R'){
            long long int S;
            long long int P;
            cin >> S >> P;
            SET_HR(S, P);
        }
        else if (command[0] == 'S' && command[4] == 'H' && command[5] == 'W'){
            long long int W;
            long long int P;
            cin >> W >> P;
            SET_HW(W, P);
        }
        else if (command[0] == 'S' && command[4] == 'H' && command[5] == 'R'){
            long long int S;
            long long int P;
            cin >> S >> P;
            SET_HR(S, P);
        }
        else if (command[0] == 'S' && command[4] == 'H' && command[5] == 'S'){
            long long int P;
            cin >> P;
            SET_HS(P);
        }
        else if (command[0] == 'P' && command[1] == 'U' && command[4] == 'W'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            long long int A;
            cin >> W >> R >> S >> P >> A;
            PUT_W(W, R, S, P, A);
        }
        else if (command[0] == 'P' && command[1] == 'U' && command[4] == 'H'){
            long long int W;
            long long int P;
            long long int A;
            cin >> W >> P >> A;
            PUT_H(W, P, A);
        }
        else if (command[0] == 'P' && command[1] == 'U' && command[4] == 'R'){
            long long int S;
            long long int P;
            long long int A;
            cin >> S >> P >> A;
            PUT_R(S, P, A);
        }
        else if (command[0] == 'P' && command[1] == 'U' && command[4] == 'S'){
            long long int P;
            long long int A;
            cin >> P >> A;
            PUT_S(P, A);
        }
        else if (command[0] == 'F'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            long long int A;
            cin >> W >> R >> S >> P >> A;
            FILL(W, R, S, P, A);
        }
        else if (command[0] == 'P' && command[1] == 'O' && command[4] == 'W'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            long long int A;
            cin >> W >> R >> S >> P >> A;
            POP_W(W, R, S, P, A);
        }
        else if (command[0] == 'P' && command[1] == 'O' && command[4] == 'H'){
            long long int W;
            long long int P;
            long long int A;
            cin >> W >> P >> A;
            POP_H(W, P, A);
        }
        else if (command[0] == 'P' && command[1] == 'O' && command[4] == 'R'){
            long long int S;
            long long int P;
            long long int A;
            cin >> S >> P >> A;
            POP_R(S, P, A);
        }
        else if (command[0] == 'P' && command[1] == 'O' && command[4] == 'S'){
            long long int P;
            long long int A;
            cin >> P >> A;
            POP_S(P, A);
        }
        else if (command[0] == 'G' && command[4] == 'E'){
            GET_E();
        }
        else if (command[0] == 'G' && command[4] == 'W'){
            long long int W;
            cin >> W;
            GET_W(W);
        }
        else if (command[0] == 'G' && command[4] == 'R' && command[5] == 'W' ){
            long long int W;
            long long int R;
            cin >> W >> R;
            GET_RW(W, R);
        }
        else if (command[0] == 'G' && command[4] == 'R' && command[5] == 'H' ){
            GET_RH();
        }
        else if (command[0] == 'G' && command[4] == 'S' && command[5] == 'W' ){
            long long int W;
            long long int R;
            long long int S;
            cin >> W >> R >> S;
            GET_SW(W, R, S);
        }
        else if (command[0] == 'G' && command[4] == 'S' && command[5] == 'H'){
            long long int W;
            cin >> W;
            GET_SH(W);
        }
        else if (command[0] == 'G' && command[4] == 'S' && command[5] == 'R'){
            long long int S;
            cin >> S;
            GET_SR(S);
        }
        else if (command[0] == 'G' && command[4] == 'S'){
            GET_S();
        }
        else if (command[0] == 'S' && command[4] == 'L' && command[5] == 'W'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            unsigned char DD[3];
            cin >> W >> R >> S >> P >> DD;        
            SET_LW(W,R,S,P,DD);
        }
        else if (command[0] == 'G' && command[4] == 'L' && command[5] == 'W'){
            long long int W;
            long long int R;
            long long int S;
            long long int P;
            cin >> W >> R >> S >> P;        
            GET_LW(W,R,S,P);
        }
        else if (command[0] == 'S' && command[4] == 'L' && command[5] == 'H'){
            long long int W;
            long long int P;
            unsigned char DD[3];
            cin >> W >> P >> DD;        
            SET_LH(W,P,DD);
        }
        else if (command[0] == 'G' && command[4] == 'L' && command[5] == 'H'){
            long long int W;
            long long int P;
            cin >> W >> P;        
            GET_LH(W,P);
        }
        else if (command[0] == 'S' && command[4] == 'L' && command[5] == 'R'){
            long long int S;
            long long int P;
            unsigned char DD[3];
            cin >> S >> P >> DD;        
            SET_LR(S,P,DD);
        }
        else if (command[0] == 'G' && command[4] == 'L' && command[5] == 'R'){
            long long int S;
            long long int P;
            cin >> S >> P;        
            GET_LR(S,P);
        }
        else if (command[0] == 'S' && command[4] == 'L' && command[5] == 'S'){
            long long int P;
            unsigned char DD[3];
            cin >> P >> DD;  
            SET_LS(P,DD);
        }
        else if (command[0] == 'G' && command[4] == 'L' && command[5] == 'S'){
            long long int P;
            cin >> P;        
            GET_LS(P);
        }
        else if (command[0] == 'E'){
            break;
        }
    }

}
