#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    map<int,int>d,vt;
    int n,l,r;
    cin >> n >> l >> r;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;        
    }   
    vector<int>a,y;
    for (int i = 1; i <= n; i++) {
        bool d1 =0;
        bool d2 = 0;

        if ( l - a[i] > 0 ) {
           if (d[a[i]] > 0 && d[l - a[i]] > 0) d1 = 1; 
        } 
        if ( r - a[i] > 0 ) {
           if (d[a[i]] > 0 && d[r - a[i]] > 0) d2 = 1; 
        } 
        if (d1 == 1 && d2 == 1) {
            both.push_back(a[i]);
            both.push_back(l-a[i]);
        }
        else if (d1 == 1) {
            a.push_back(a[i]);
            a.push_back(l-a[i]);
            d[a[i]]--;
            d[l-a[i]]--;    
            vt[a[i]] = 1;
            vt[l-a[i]] = 1;
        }
        else if (d2 == 1) {
            b.push_back(a[i]);
            b.push_back(r-a[i]);
            d[a[i]]--;
            d[r-a[i]]--;    
            vt[a[i]] = 2;
            vt[r-a[i]] = 2;
        }
    }

    return 0;
}