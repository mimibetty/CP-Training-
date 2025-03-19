#include<bits/stdc++.h>
using namespace std;
 
char a[20][20];
int res = 0;
int vt_col[20];
int check[20][20];
 
int number;
bool isSafe(int row, int col) {
    if (a[row][col] == '*') return false;
    if (vt_col[col] == 1) return false;
 
    for (int i = row, j = col; i >= 1 && j >= 1; i--, j--) {
        if (check[i][j] == 1) return false;       
    }
 
    for (int i = row, j = col; i <= 8 && j <= 8; i++, j++) {
        if (check[i][j] == 1) return false;  
    }
 
    for (int i = row, j = col; i <= 8 && j >= 1; i++, j--) {
        if (check[i][j] == 1) return false;  
    }
 
    for (int i = row, j = col; i >= 1 && j <= 8; i--, j++) {
        if (check[i][j] == 1) return false;  
    }   
    return true;
}
 
void backtrack (int idx, int val) {
    if (idx > number) {
        // res++;
        res = max(res, val);
        return;
    }
 
    for (int i = 1; i <= 8; i++) {
        if (isSafe(idx, i) == 1) {
            vt_col[i] = 1;
            check[idx][i] = 1; 
            backtrack(idx+1, val + a[idx][i]);
            
            vt_col[i] = 0;
            check[idx][i] = 0;
        }
    }
    
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) cin >> a[i][j];
    }
    
    backtrack(1);
    cout << res;
    return 0;
}
