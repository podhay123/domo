//Jakub Podhajski
#include <iostream>
using namespace std;

int C(int cub[32][32][32], int h_index, int w_index, int d_index, int height, int width, int depth, int n){
    int d_start;
    int w_start;
    int h_start;
    int d_end;
    int w_end;
    int h_end;
    if (d_index <= 0){
        d_start = 0;
        if (d_index + depth >= 0){
            if (d_index + depth > n - 1){
                d_end = n - 1;
            }
            else{
                d_end = d_index + depth;
            }
        }
        else{
            d_end = -1;
        }
    }
    else{
        if (d_index >= n){
            d_end = n - 1;
        }
        else{
            d_end = d_index;
        }
        if (d_index - depth < 0){
            d_start = 0;
        }
        else if (d_index - depth > n){
            d_start = n+1;
        }
        else{
            d_start = d_index - depth;
        }
    }
    if (w_index <= 0){
        w_start = 0;
        if (w_index + width >= 0){
            if (w_index + width > n - 1){
                w_end = n - 1;
            }
            else{
                w_end = w_index + width;
            }
        }
        else{
            w_end = -1;
        }
    }
    else{
        if (w_index >= n){
            w_end = n - 1;
        }
        else{
            w_end = w_index;
        }
        if (w_index - width < 0){
            w_start = 0;
        }
        else if (w_index - width > n){
            w_start = n+1;
        }
        else{
            w_start = w_index - width;
        }
    }
    if (h_index <= 0){
        h_start = 0;
        if (h_index + height >= 0){
            if (h_index + height > n - 1){
                h_end = n - 1;
            }
            else{
                h_end = h_index + height;
            }
        }
        else{
            h_end = -1;
        }
    }
    else{
        if (h_index >= n){
            h_end = n - 1;
        }
        else{
            h_end = h_index;
        }
        if (h_index - height < 0){
            h_start = 0;
        }
        else if (h_index - height > n){
            h_start = n + 1;
        }
        else{
            h_start = h_index - height;
        }
    }
    int sum = 0;
    int number_of_points = (h_end-h_start+1)*(w_end-w_start+1)*(d_end-d_start+1);
    int points[number_of_points][3];
    int index = 0;
    for (int i = d_start; i <= d_end; i++){
        for (int j = h_start; j <= h_end; j++){
            for (int k = w_start; k <= w_end; k++){
            points[index][0] = i;
            points[index][1] = j;
            points[index][2] = k;
            index += 1;
            sum += cub[i][j][k];
            }
        }
    }
    return sum;

}
int main(){
    int n;
    cin >> n;
    int cub[32][32][32];
    for (int d = 0; d <n; d++){
        for (int h = 0; h < n; h++){
            for (int w = 0; w < n; w++){
                cin >> cub[d][h][w];
            }
        }
    }
    char operation;
    cin >> operation;
    while (operation != 'E'){
        if (operation == 'C'){
            int l;
            int v;
            int p;
            int h;
            int w;
            int d;
            cin >> l >> v >> p >> h >> w >> d;
            int result;
            result = C(cub, l, v, p, h, w, d, n);
            cout << result << endl;
        }
        cin >> operation;
    }
}