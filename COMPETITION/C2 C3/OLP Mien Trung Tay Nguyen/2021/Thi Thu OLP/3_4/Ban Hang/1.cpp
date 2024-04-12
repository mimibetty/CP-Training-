#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int b[1000005];
int c[1000005];
bool check[1000005];

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int m,n;
    int res = 0;
    
    cin >> m ;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= 1e6; i++) {
        c[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        int d = 0 ; 
        while (d < b[i]) {
           // cout <<i << ' '<< d << ' ' << c[b[i]] <<endl;
            if (c[ b[i] ] > 1e6) break;
            if (check[ c[b[i]] ] == 1) {
                c[ b[i] ] += b[i];
            }
            else {
                check[ c[b[i]] ] = 1;
                d++;
                c[ b[i] ] += b[i];
            }
        }
    }


    for (int i = 1; i <= m; i++) {
        if (check[a[i]] == 1) res++;
    }
    cout << res;
    return 0;
}