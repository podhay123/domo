//Jakub Podhajski
#include <iostream>
using namespace std;


int power(int number, int pow){
    int result = number;
    for (int i = 0; i < pow -1; i++){
        result *= number;
    }
    return result;
}
int C(int cub[32][32][32], int h_index, int w_index, int d_index, int height, int width, int depth, int n){
    int d_start;
    int w_start;
    int h_start;
    int d_end;
    int w_end;
    int h_end;
    if (h_index < 1.0*n / 2){
        if (h_index <= 0){
            h_start = 0;
        }
        else{
            h_start = h_index;
        }
        if (h_index + height < 0){
            h_end = -1;
        }
        else if (h_index + height >= n){
            h_end = n - 1;
        }
        else{
            h_end = h_index + height;
        }
    }
    else{
        if (h_index >= n - 1){
            h_end = n - 1;
        }
        else{
            h_end = h_index;
        }
        if (h_index - height >= n){
            h_start = n;
        }
        else if (h_index - height < 0){
            h_start = 0;
        }
        else{
            h_start = h_index - height;
        }
    }
    if (w_index < 1.0*n / 2){
        if (w_index <= 0){
            w_start = 0;
        }
        else{
            w_start = w_index;
        }
        if (w_index + width < 0){
            w_end = - 1;
        }
        else if (w_index + width >= n){
            w_end = n - 1;
        }
        else{
            w_end = w_index + width;
        }
    }
    else{
        if (w_index >= n - 1){
            w_end = n - 1;
        }
        else{
            w_end = w_index;
        }
        if (w_index - width >= n){
            w_start = n;
        }
        else if (w_index - width < 0){
            w_start = 0;
        }
        else{
            w_start = w_index - width;
        }
    }
    if (d_index < 1.0*n / 2){
        if (d_index <= 0){
            d_start = 0;
        }
        else{
            d_start = d_index;
        }
        if (d_index + depth < 0){
            d_end = - 1;
        }
        else if (d_index + depth >= n){
            d_end = n - 1;
        }
        else{
            d_end = d_index + depth;
        }
    }
    else{
        if (d_index >= n - 1){
            d_end = n - 1;
        }
        else{
            d_end = d_index;
        }
        if (d_index - depth >= n){
            d_start = n;
        }
        else if (d_index - depth < 0){
            d_start = 0;
        }
        else{
            d_start = d_index - depth;
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
int T(int cub[32][32][32], int h_index, int w_index, int d_index, int m, int n){
    int d_start;
    int w_start;
    int h_start;
    int d_end;
    int w_end;
    int h_end;
    if (h_index < 1.0*n / 2){
        if (h_index <= 0){
            h_start = 0;
        }
        else{
            h_start = h_index;
        }
        if (h_index + m < 0){
            h_end = -1;
        }
        else if (h_index + m >= n){
            h_end = n - 1;
        }
        else{
            h_end = h_index + m;
        }
    }
    else{
        if (h_index >= n - 1){
            h_end = n - 1;
        }
        else{
            h_end = h_index;
        }
        if (h_index - m >= n){
            h_start = n;
        }
        else if (h_index - m < 0){
            h_start = 0;
        }
        else{
            h_start = h_index - m;
        }
    }
    if (w_index < 1.0*n / 2){
        if (w_index <= 0){
            w_start = 0;
        }
        else{
            w_start = w_index;
        }
        if (w_index + m < 0){
            w_end = - 1;
        }
        else if (w_index + m >= n){
            w_end = n - 1;
        }
        else{
            w_end = w_index + m;
        }
    }
    else{
        if (w_index >= n - 1){
            w_end = n - 1;
        }
        else{
            w_end = w_index;
        }
        if (w_index - m >= n){
            w_start = n;
        }
        else if (w_index - m < 0){
            w_start = 0;
        }
        else{
            w_start = w_index - m;
        }
    }
    if (d_index < 1.0*n / 2){
        if (d_index <= 0){
            d_start = 0;
        }
        else{
            d_start = d_index;
        }
        if (d_index + m < 0){
            d_end = - 1;
        }
        else if (d_index + m >= n){
            d_end = n - 1;
        }
        else{
            d_end = d_index + m;
        }
    }
    else{
        if (d_index >= n - 1){
            d_end = n - 1;
        }
        else{
            d_end = d_index;
        }
        if (d_index - m >= n){
            d_start = n;
        }
        else if (d_index - m < 0){
            d_start = 0;
        }
        else{
            d_start = d_index - m;
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
            int h_val = h_index - j;
            if (h_val < 0){
                h_val = -h_val;
            } 
            int w_val = w_index - k;
            if (w_val < 0){
                w_val = -w_val;
            } 
            int d_val = d_index - i;
            if (d_val < 0){
                d_val = -d_val;
            } 
            
            if (d_val + h_val + w_val <= m){
                sum += cub[i][j][k];
            }
            }
        }
    }
    return sum;
}
int O(int cub[32][32][32], int h_index, int w_index, int d_index, int m, int n){
    int d_start;
    int w_start;
    int h_start;
    int d_end;
    int w_end;
    int h_end;
    if (h_index < 1.0*n / 2){
        if (h_index <= 0){
            h_start = 0;
        }
        else{
            h_start = h_index;
        }
        if (h_index + m < 0){
            h_end = -1;
        }
        else if (h_index + m >= n){
            h_end = n - 1;
        }
        else{
            h_end = h_index + m;
        }
    }
    else{
        if (h_index >= n - 1){
            h_end = n - 1;
        }
        else{
            h_end = h_index;
        }
        if (h_index - m >= n){
            h_start = n;
        }
        else if (h_index - m < 0){
            h_start = 0;
        }
        else{
            h_start = h_index - m;
        }
    }
    if (w_index < 1.0*n / 2){
        if (w_index <= 0){
            w_start = 0;
        }
        else{
            w_start = w_index;
        }
        if (w_index + m < 0){
            w_end = - 1;
        }
        else if (w_index + m >= n){
            w_end = n - 1;
        }
        else{
            w_end = w_index + m;
        }
    }
    else{
        if (w_index >= n - 1){
            w_end = n - 1;
        }
        else{
            w_end = w_index;
        }
        if (w_index - m >= n){
            w_start = n;
        }
        else if (w_index - m < 0){
            w_start = 0;
        }
        else{
            w_start = w_index - m;
        }
    }
    if (d_index < 1.0*n / 2){
        if (d_index <= 0){
            d_start = 0;
        }
        else{
            d_start = d_index;
        }
        if (d_index + m < 0){
            d_end = - 1;
        }
        else if (d_index + m >= n){
            d_end = n - 1;
        }
        else{
            d_end = d_index + m;
        }
    }
    else{
        if (d_index >= n - 1){
            d_end = n - 1;
        }
        else{
            d_end = d_index;
        }
        if (d_index - m >= n){
            d_start = n;
        }
        else if (d_index - m < 0){
            d_start = 0;
        }
        else{
            d_start = d_index - m;
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
            int h_val = h_index - j;
            int w_val = w_index - k;
            int d_val = d_index - i;
            
            if (d_val*d_val + h_val*h_val + w_val*w_val <= m*m){
                sum += cub[i][j][k];
            }
            }
        }
    }
    return sum;
}
int D(int cub[32][32][32], char k, int i, int n){
    int matrix[n][n];
    if (k == 'l'){
        for (int d = 0; d <n; d++){
            for (int h = 0; h < n; h++){
                matrix[d][h] = cub[d][h][i];
            }
        }
    }
    else if (k == 'v'){
        for (int d = 0; d < n; d++){
            for (int w = 0; w < n; w++){
                matrix[d][w] = cub[d][i][w];
            }
        }
    }
    else{//p
        for (int h = 0; h < n; h++){
            for (int w = 0; w < n; w++){
                matrix[h][w] = cub[i][h][w];
            }
        }
    }
    long long big_multi = 1;
    for (int k = 0; k < n-1; k++){
        int multi = 1;
        for (int i = 0; i < n; i++){
            multi *= matrix[i][k];
        }
        big_multi*=power(multi,n-1);
        for (int i = 0; i < n; i++){
            int temp = matrix[i][k];
            multi = multi / temp;
            for (int j = 0; j < n; j++){
                matrix[i][j] *= multi;
            }
            multi *= temp;
        }
        for (int j = 0; j < n; j++){
            int temp =  matrix[k][j];
            for (int i = k + 1; i < n; i++){
                matrix[i][j] -= temp;
            }
        }
    }
    long long result = 1;
    for (int i = 0; i < n; i++){
        result *= matrix[i][i];
    }
    
    result = result/big_multi;
    return result;
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
        else if (operation == 'T'){
            int l;
            int v;
            int p;
            int e;
            cin >> l >> v >> p >> e;
            int result;
            result = T(cub, l, v, p, e, n);
            cout << result << endl;
            
        }
        else if (operation == 'O'){
            int l;
            int v;
            int p;
            int r;
            cin >> l >> v >> p >> r;
            int result;
            result = O(cub, l, v, p, r, n);
            cout << result << endl;
            
        }
        else if (operation == 'D'){
            char k;
            int i;
            cin >> k >> i;
            int result;
            result = D(cub, k, i, n);
            cout << result << endl;
            
        }
        cin >> operation;
    }
}