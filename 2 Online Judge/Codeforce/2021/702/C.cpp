#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;

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
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl;
#define SQ(a) a*a;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
const int limx = 1e6;


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

int par[105];
int vt[105];

void backtrack (int vtd, int vtc, rmq &rmq, int parent) {
    int val = rmq.queryMax(vtd,vtc);
    int pos = vt[val];

    par[val] = parent;

     int vtd1 = 0, vtc1 = vt[n] - 1;
        int vtd2 = vt[n] + 1, vtc2 = n-1;
    if(vt[n] == 0) {
            backtrack(1,n-1,rmq,vt[n]);
        }
        else if (vt[n] == n-1) backtrack(0,n-2,rmq,vt[n]);
        else {
            backtrack(0,vt[n]-1,rmq,vt[n]);
            backtrack(0,vt[n]+1,rmq,vt[n]);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    // cout << pow(8, 1.0/3);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a;
        for (int i = 0; i < n;i++) {
            int b;
            cin >> b;
            a.pb(b);
            vt[b] = i;  
        } 

        RMQ rmq(a);
        int vtd1 = 0, vtc1 = vt[n] - 1;
        int vtd2 = vt[n] + 1, vtc2 = n-1;
        
        if(vt[n] == 0) {
            backtrack(1,n-1,rmq,vt[n]);
        }
        else if (vt[n] == n-1) backtrack(0,n-2,rmq,vt[n]);
        else {
            backtrack(0,vt[n]-1,rmq,vt[n]);
            backtrack(0,vt[n]+1,rmq,vt[n]);
        }

        for (int i = 0 ; i < n; i++) {

        }
    }
    return 0;
}