#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

char a[20][20];
bool type1(int i, int j) {
    book ok = 0;
    int cnt = 0;
    if (a[i][j] == '#' && (i > 0 && i < 7 && j > 0 && j < 7)) cnt++;
    if (a[i][j+1] == '#' && (i > 0 && i < 7 && j+1 > 0 && j+1 < 7)) cnt++;
    if (a[i+1][j+1] == '#' && (i+1 > 0 && i+1 < 7 && j+1 > 0 && j+1 < 7)) cnt++;
    if (a[i+1][j+2] == '#' && (i+1 > 0 && i+1 < 7 && j+2 > 0 && j+2 < 7)) cnt++;
    if (a[i+1][j+3] == '#' && (i+1 > 0 && i+1 < 7 && j+3 > 0 && j+3 < 7)) cnt++;
    if (a[i+3][j+3] == '#' && (i+3 > 0 && i+3 < 7 && j+3 > 0 && j+3 < 7)) cnt++;
    if (cnt == 6) return 1;
    cnt = 0;

    //2
    if (a[i][j] == '#' && (i > 0 && i < 7 && j > 0 && j < 7)) cnt++;
    if (a[i][j-1] == '#'&& (i > 0 && i < 7 && j > 0 && j < 7)) cnt++;
    if (a[i+1][j-1] == '#'&& (i > 0 && i < 7 && j > 0 && j < 7)) cnt++;
    if (a[i+2][j-1] == '#'&& (i > 0 && i < 7 && j > 0 && j < 7)) cnt++;
    if (a[i+2][j-2] == '#'&& (i > 0 && i < 7 && j > 0 && j < 7)) cnt++;
    if (a[i+3][j-2] == '#'&& (i > 0 && i < 7 && j > 0 && j < 7)) cnt++;
    if (cnt == 6) return 1;
    cnt = 0;
    //3
    if (a[i][j] == '#') cnt++;
    if (a[i+1][j-1] == '#') cnt++;
    if (a[i+1][j] == '#') cnt++;
    if (a[i+2][j-1] == '#') cnt++;
    if (a[i+3][j-1] == '#') cnt++;
    if (a[i+3][j-2] == '#') cnt++;
    if (cnt == 6) return 1;
    cnt = 0;
    //4
    if (a[i][j] == '#') cnt++;
    if (a[i+1][j] == '#') cnt++;
    if (a[i+1][j+1] == '#') cnt++;
    if (a[i+1][j+2] == '#') cnt++;
    if (a[i+2][j+2] == '#') cnt++;
    if (a[i+2][j+3] == '#') cnt++;
    if (cnt == 6) return 1;
    
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) cin >> a[i][j];
    }     
    
    bool ok = 0;   
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int type = 1; type <= 11; type++) {
                ok = max({type1(i,j),type2(i,j),type3(i,j),type4(i,j),type5(i,j),type6(i,j),type7(i,j),type8(i,j),type9(i,j),type10(i,j),type11(i,j)})
                if (ok == 1) {
                    cout << "can fold";
                    return 0;
                 }    
            }
        }
    }     
    cout << "cannot fold";
    return 0;
}