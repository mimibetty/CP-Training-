/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;


long long a[300005];
ll maxL[300005];
ll minL[300005];
ll maxR[300005];
ll minR[300005];

ll maxL2[300005];
ll minL2[300005];
ll maxR2[300005];
ll minR2[300005];



void solve() {
    long long res = 1e10;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    minL[0] = minL2[0] = minR[n+1] = minR2[n+1] = 1e10;
    // L tức là prefix 
    // R là suffix 
    int midd = (n + 1) / 2;
    for (int i = 1; i <= midd; i++)  {
        int l = i, r = n - i + 1;
        ll s = a[l] + a[r];
        ll s2 = a[l] + a[r + 1];
        maxL[i] = max(s, maxL[i-1]);        
        minL[i] = min(s, minL[i-1]);
        
        maxL2[i] = max(s2, maxL2[i-1]);
        minL2[i] = min(s2, minL2[i-1]);
    }

    // xử lí trường hợp ngoại lệ i = mid 
    int l1 = n - midd + 1, r1 = midd;
    ll ss = a[l1] + a[r1];
    ll ss2 = a[l1 + 1] + a[r1];
    maxR[midd] = ss;
    minR[midd] = ss;
    maxR2[midd] = ss2;
    minR2[midd] = ss2;
    for (int i = midd + 1; i <= n; i++)  {
        int l = n - i + 1, r = i;
        ll s = a[l] + a[r];
        ll s2 = a[l + 1] + a[r];
        maxR[i] = max(s, maxR[i-1]);
        minR[i] = min(s, minR[i-1]);
        
        maxR2[i] = max(s2, maxR2[i-1]);
        minR2[i] = min(s2, minR2[i-1]);
    }
    

    for (int i = 1; i <= n; i++) { // i là số mình sẽ bỏ đi 
        if (i <= midd) {
            int conlai = midd - i;
            ll maxx = max(maxL[i-1],     maxR2[midd + conlai]); // max min R2 ko 4 - 5, 3-6// ddang sai vi mang ko duoc chua mid
            ll minn = min(minL[i-1],     minR2[midd + conlai]);
            res = min(res, maxx - minn);
        }
        else {
            int conlai = n - i ;
            ll maxx = max(maxL[conlai],   maxR2[i - 1]); // max min R2??
            ll minn = min(minL[conlai],   minR2[i - 1]);
            res = min(res, maxx - minn);
            
        }
    }
    cout << res << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}