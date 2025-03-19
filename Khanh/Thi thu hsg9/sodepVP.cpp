/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

void solve() {
    int n;
    long long X;
    cin >> n >> X;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    // DP arrays:
    // dp0[i] = maximum subarray sum ending at i without using the operation.
    // dp1[i] = maximum subarray sum ending at i when the operation is active.
    // dp2[i] = maximum subarray sum ending at i after the operation has ended.
    vector<long long> dp0(n), dp1(n), dp2(n);
    
    dp0[0] = a[0];
    dp1[0] = a[0] * X;
    dp2[0] = a[0];  // Starting by immediately “finishing” on a[0] is same as a[i]
    
    // Start with empty subsequence possibility incorporated:
    long long ans = max({0LL, dp0[0], dp1[0], dp2[0]});
    
    for (int i = 1; i < n; i++){
        dp0[i] = max(dp0[i-1] + a[i], a[i]);
        dp1[i] = max({ dp0[i-1] + a[i] * X, dp1[i-1] + a[i] * X, a[i] * X });
        dp2[i] = max({ dp1[i-1] + a[i], dp2[i-1] + a[i], a[i] });
        
        ans = max({ans, dp0[i], dp1[i], dp2[i]});
    }
    
    cout << ans << "\n";
    
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

Let dp0[i] be the maximum subarray sum ending at
 position i without having applied the multiplication operation.
1 2 3 4|| 5 6
-1 -2 -3 4|| 5 6


1 2 3  ||=> 4 5 6 7 8 9

th1 : + ai 
th2 : + ai * x
th3 : ko đóng góp gì được vào mảng tổng lớn nhất


trạng thái cho tất cả 
0: + ai (chua tung nhan x)
1: + ai * x (dang trong trang thai nhan x)
2: + ai (bởi vì đã hết lượt * x)


0 0 0 0 0 (1) [1] 0 1 1 1  2 2 2 2 

0 0 0 0 0 1 1  1  1  1  (2) {2} {2} 2 2

