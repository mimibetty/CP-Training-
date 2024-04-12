#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

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

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> a[i]; 
        }
    }

    int row = 3;
    int col = 5;
    vt_col[1] = 1;
    vt_row[1] = 1;
    vt_row[2] = 1;
    vt_col[3] = 1;
    check_vt[1][1] = 1;
    check_vt[2][3] = 1;
    
    cout << check_duongcheo(row,col);
    return 0;
}
    
    
// X.......
// ..X.....
// ..*.X...
// .A......8/8//*8888
// ...A....
// .....**A
// ...*A...
// ......A.