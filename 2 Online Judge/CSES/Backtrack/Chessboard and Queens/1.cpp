#include<bits/stdc++.h>
using namespace std;

char a[20][20];
bool vt_row[20], vt_col[20];
bool check_vt[20][20];
int res = 0;

bool check_duongcheo(int row, int col) {
    for (int i = row, j = col; i >= 1 && j >= 1; i--, j--) {
        if (check_vt[i][j] == 1) return false;       
    }

    for (int i = row, j = col; i <= 8 && j <= 8; i++, j++) {
        if (check_vt[i][j] == 1) return false;  
    }

    for (int i = row, j = col; i <= 8 && j >= 1; i++, j--) {
        if (check_vt[i][j] == 1) return false;  
    }

    for (int i = row, j = col; i >= 1 && j <= 8; i--, j++) {
        if (check_vt[i][j] == 1) return false;  
    }   
   return true;            
}

void backtrack(int idx) {
    if (idx == 8) {
        res++;
        return;
    }

    for (int row = 1; row <= 8; row++) {
        for (int col = 1; col <= 8; col++) {
            bool check = 1;

            if (a[row][col] == '*') continue;
            if (check_duongcheo(row,col) == 0) continue;
               
            if (vt_col[col] == 0 && vt_row[row] == 0 && check == 1) {
                vt_col[col] = 1; 
                vt_row[row] = 1;
                check_vt[row][col] = 1;

                backtrack(idx + 1);
                
                check_vt[row][col] = 0;
                vt_col[col] = 0;
                vt_row[row] = 0;
            }
        }
    }
}

int main() {
  
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) cin >> a[i][j];
    }    

    backtrack(0);
    cout << res;
    return 0;
}