#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

 
struct RMQ {
    vector<ll> a;
    vector<vector<ll>>sparseMax,sparseMin;
    int n;
    RMQ(vector<ll> arr) {
        a = arr;
        n = arr.size();
        sparseMax.resize(n);
        sparseMin.resize(n);
        for (int i = 0; i < n; i++) {
            sparseMax[i].resize(__lg(n) + 1);
            sparseMax[i][0] = a[i];
 
            sparseMin[i].resize(__lg(n) + 1);
            sparseMin[i][0] = a[i];
        }
 
        for (int len = 1; len < __lg(n) + 1; len++) {
            for (int i = 0; i + (1 << (len - 1)) < n; i++) {
                sparseMax[i][len] = max(sparseMax[i][len - 1], sparseMax[(1 << (len - 1)) + i][len - 1]);
                sparseMin[i][len] = min(sparseMin[i][len - 1], sparseMin[(1 << (len - 1)) + i][len - 1]);
            }
        }
    }
 
    int queryMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
    }
 
    int queryMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
    }
 
    // find Max, Min, Gcd
};

void solve() {
    int n;
    cin >> n;
    vector<ll>a(n+1);
    vector<ll>ps(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }

    RMQ rmqA(a);
    RMQ rmqPS(ps);
    // for (int i = 1; i <= n; i++) cout << ps[i] << ' ';
    // cout << endl; 

    for (int i = 1; i <= n; i++) {
        int left = 0, right = 0;
        long long sumleft = 0, sumright = 0;

        int lower = 1, upper = i;
        int mid;
        // cout << "STT   " << i << endl; 
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (rmqA.queryMax(mid, i) == a[i]) {
                upper = mid;
            }
            else lower = mid + 1;
        }
        
        left = lower;

        if (i != left) {
            if (i == 1) sumleft = 0;
            if (i - 2 >= 0) sumleft = ps[i-1] - rmqPS.queryMin(left - 1, i - 2);
            // else 
        }
      
        if (sumleft > 0) {
            cout << "NO" << endl;
            return;
        }
        
        lower = i, upper = n;
        while (lower < upper) {
            mid = (lower + upper+1) / 2;
            if (rmqA.queryMax(i, mid) == a[i]) {
                lower = mid;
            }
            else upper = mid - 1;
        }
        
        right = lower;

        if (i != right) {
            if (i == n) sumright = 0;
            else sumright =  rmqPS.queryMax(i + 1, right) - ps[i];
        }


        if (sumright > 0) {
            cout << "NO" << endl;
            return;
        }

        // cout << i << ' ' << sumleft << ' ' << sumright << endl;
        // cout << left << ' ' << right << endl;

    } 

    cout << "yes" << endl;
    return;
}

int main() {

    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}