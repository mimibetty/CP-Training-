#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double ld;

// note dp[r] =max( p + max (dp[1] - > dp[l-1])   , max (dp[1] - > dp[r]) )
struct datas {
    int l, r, p;

    // Định nghĩa toán tử < để sắp xếp theo thứ tự ưu tiên l, sau đó đến r, và cuối cùng là p
    bool operator<(const datas& other) const {
        if (r != other.r)
            return r < other.r;
        return l < other.l;
    }
};

int n;
datas a[200005];
ll maxdp[400005];
ll dp[400005];

void compress() {
    map<int,int>d; 
    for (int i = 1; i <= n; i++) {
        d[a[i].l]++;
        d[a[i].r]++;
    }

    int cnt = 0;
    map<int,int>convert;
    for(auto [key, val] : d) {
        cnt++;
        convert[key] = cnt;
    }

    for (int i = 1; i <= n; i++) {
        a[i].l = convert[a[i].l];
        a[i].r = convert[a[i].r];
    }
}



int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long res = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].p;
    }

    compress();
    sort(a + 1, a + 1 + n);
    
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].l << ' ' << a[i].r << ' ' << a[i].p << endl;
    // }    

    for (int i = 1; i <= n; i++) {
        int l = a[i].l, r = a[i].r;
        
        for (int j = 0; j <= r; j++) {
            dp[r] = max(dp[r], dp[j]);
        }


        for (int j = 0; j <= l - 1 ; j++) {
            dp[r] = max(dp[r], dp[j] + a[i].p);
        }
        res = max(res, dp[r]);
    }

    // for (int i = 1; i <= 10; i++) {
    //     cout << i << ' ' << dp[i] << endl;
    // }
    cout << res << endl;

    return 0;
}