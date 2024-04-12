/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
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


struct RMQ {
    vector<int> a;
    vector<vector<int>> sparseMax, sparseMin;
    int n;
    RMQ(vector<int> arr) {
        a = arr;
        n = arr.size();
        sparseMax.resize(n);
        sparseMin.resize(n);
        for (int i = 0; i < n; i++) {
            sparseMax[i].resize(__lg(n) + 1);
            sparseMax[i][0] = a[i]; // {a[i], i}

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
};
 
void solve() {
    int n;
    cin >> n;
    vector<int>a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 

    RMQ rmq(a);
    int t;
    cin >> t;
    for (int z = 1; z <= t ;z++) {
        int f1, f2;
        cin >> f1 >> f2 ;
        if (rmq.queryMax(f1,f2) == rmq.queryMin(f1,f2)) {
            cout << "-1 -1" << endl;
        }
        else {
            int l = f1, r = f2;
            while (l < r) {
                int mid = (l + r  )/2;
                if (rmq.queryMax(f1, mid) == rmq.queryMax(f1, f2)) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
                // cout << l << ' ' << r << endl;
            }

            int l2 = f1, r2 = f2;
            while (l2 < r2) {
                int mid = (l2 + r2)/2;
                if (rmq.queryMin(f1, mid) > rmq.queryMin(f1, f2)) {
                    l2 = mid + 1;
                }
                else {
                    r2 = mid;
                }
                // cout << "LEEE  " << l2 << ' ' << r2 << endl;
            }
            cout  << l << ' ' << l2 << endl;
        }
    }

    cout << endl;
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
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}