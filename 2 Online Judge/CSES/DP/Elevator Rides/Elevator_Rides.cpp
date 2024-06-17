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
const int NN = (1 << 20);

int n;
long long a[22];
long long x;
long long dp[NN + 5];

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
        dp[i] = 1e9;
    }

    for (int i = 1; i <= maxx; i++) {
        bs = i;

        vector<int>pos;
        for (int j = 0; j < n; j++) {
            if (bs[j] == 1) {
                pos.push_back(j);
            }
        }
        int lenn = pos.size();
        // cout << endl;
        // cout << "index "  << i << endl;
        // for (auto i : pos) cout << i << ' ';
        // cout << endl;


        for (int bit = 1; bit < (1 << lenn); bit++) {
            bs = bit;
            long long sumX = 0, sumindex = 0;
            for (int j = 0; j < lenn; j++) {
                if (bs[j] == 1) {
                    sumindex += pow(2, pos[j]);
                    sumX += a[pos[j]];
                }
                if (sumX > x) break;
            }
            
            // cout <<"bit  " <<  bit << ' ' << sumX << ' ' << sumindex << ' ' << dp[i]  << endl; 
            if (sumX <= x) {
                dp[i] = min(dp[i] , dp[i - sumindex] + 1);
                // cout <<"bit ok  " <<  bit << ' ' << sumX << ' ' << sumindex << ' ' << dp[i]  << endl;
            }

        }
    }

    cout << dp[maxx] << endl;
    // for (int i = 0; i <= maxx; i++) {
    //     cout << i << ' '<< dp[i] << endl;
    // }
    return 0;
}