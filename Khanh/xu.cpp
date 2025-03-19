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

// dp[102][100005]; 
// dp i,j là mình được sử dụng i đồng xu đầu tiên và j là tổng của 1 vài đồng xu từ i đồng xu đầu 
// dp i,j = 1|0
bool dp[100005];
int a[100005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);  
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

// dp[i][0] = 1
    dp[0] = 1;
    const int maxSum = 1e5;
    for (int i = 1; i <= n; i++) {
        for (int j = maxSum; j >= 1; j--) {
            if (j - a[i] >= 0) {
                dp[j] |= dp[j - a[i]];
            }
        }
    }
 
    int cnt = 0;
    for (int i = 1; i <= maxSum; i++) if (dp[i]) cnt++;
    cout << cnt << endl;
    for (int i = 1; i <= maxSum; i++) if (dp[i]) cout << i << ' ';
    return 0;
}



1 2  3 4 5 
a :1 + min(dp(2,4), dp(3,5))    b: dp(2,5)    5 , 2 
2 3 4 5 

dp(l,r) : số điểm cao nhất có thể khi đi trước và có đoạn là l, r
a: r          l  l+1 l+2 .... r-1             r


l