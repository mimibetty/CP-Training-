#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;

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
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);


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

int vt[100005];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n ;
        cin >> n;
        vector<int>x;
        vector<int>a;
        a.clear(); 
        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            vt[b] = i-1;
            a.pb(b);
        }

        RMQ rmq(a);

        if (a[0] == n) {
            for (auto i : a) cout << i << ' ';
            cout << endl;
            continue;
        }
        else {
            int csOld = n;
            int csNew = n-1;
            // cout << rmq.queryMax(0,3);
            while (csNew >= 0) {

                int val = rmq.queryMax(0,csNew);
                // cout << csNew 
                csNew = vt[val] ;
                // cout << csNew << ' ' << val << endl;
                for (int i = csNew; i < csOld; i++) cout << a[i] << ' ';
                csOld = csNew;
                csNew--;
            }
            cout << endl;
        }
    }    
    return 0;
}