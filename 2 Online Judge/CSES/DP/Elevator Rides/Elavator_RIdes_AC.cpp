/*
link submit: 
Note:// dp[i] = {num, sumx} {số lượng chuyến thang máy tính đến hiện tại, tổng số kg ở thang máy cuối}
gọi z là 1 vị trí trong i và có bs[z] == 1
dp[i] = (dp[i- (2^z)] + 1, a[z] )  nếu a[z] + dp[i- (2^z)].second > x
dp[i] = (dp[i- (2^z)] , a[z] + dp[i- (2^z)].second)  nếu a[z] + dp[i- (2^z)].second <= x

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
const int NN = (1 << 20);

int n;
long long a[22];
long long x;
pair<int,long long> dp[NN + 5]; 
bitset<21>bs;


void preprocess() {

}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 

    int maxx = (1 << n) - 1;
    
    for (int i = 1; i <= maxx; i++) {
        dp[i] = {1e9, 1e9};
    }


    for (int i = 1; i <= maxx; i++) {
        bs = i;
        for (int j = 0; j < n; j++) {
            if (bs[j]) {
                int pre = i - pow(2, j);
 
                if (dp[pre].second + a[j] > x) {
                    dp[i] = min(dp[i], {dp[pre].first + 1, a[j]});
                }
                else {
                    dp[i] = min(dp[i], {dp[pre].first, a[j] + dp[pre].second});
                }
            }
        }
    }
    // for (int i = 1; i <= maxx; i++) {
    //     cout << i << ' ' << dp[i].first << ' ' << dp[i].second << endl;;
    // }
    cout << dp[maxx].first + 1 << endl;
    return 0;
}