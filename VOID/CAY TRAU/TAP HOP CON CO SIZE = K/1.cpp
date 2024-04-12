#include<bits/stdc++.h>
using namespace std;


int a[25];
int b[25];
int limMax[25];
map<int,int> vt;

void backtrack(int n, int k) {
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        if (b[i] == limMax[i]) cnt++;
    }
    if (cnt == k) {
        return;
    }

    for (int i = 1; i <= k; i++) {
        cout << b[i] << ' ' ;
    }
    cout << endl;

    for (int i = k; i >= 1; i--) {
        bool done = 1;
        if (b[i] != limMax[i]) {
            b[i] = a[vt[b[i]] + 1];
            break;
        }
        else if (b[i] == limMax[i] && b[i-1] != limMax[i-1]) {
            b[i-1] = a[vt[b[i-1]] + 1];
            for (int j = i; j <= k; j++) {
                b[j] = a[vt[b[j-1]]+ 1] ;
                done = 0;
                break;
            }
        }

        if (done == 0) break;
    } 
    
    backtrack(n,k);
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vt[a[i]] = i;
    }

    int cnt = 1;
    for (int i = 1; i <= k; i++) {
        b[i] = a[i];
        limMax[i] = a[n-k+i];
    }

    //for (int i = 1; i <= k; i++) cout << limMax[i] << ' ';
    backtrack(n,k);       
    return 0;
}