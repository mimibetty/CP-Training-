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
#define whatIs(x) cerr << "Line " << LINE << ": " << #x << " = " << (x) << endl
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

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        vector<int> a(n + 1);
        vector<int> b(n + 1);
        vector<pair<int,int>> arr(n + 1);
        map<int,int>vt,res,vtB;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i].fi;
            vt[arr[i].fi] = i;
            // arr[i].se = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].se;
        }
        sort(arr.begin(),arr.end());

        for (int i = 1; i <= n; i++) {
            a[i] = arr[i].fi;
            b[i] = arr[i].se;
            vtB[b[i]] = i;
        }   
        // for (auto i : a) cout << i << ' '; 
        //     cout << endl;

        // RMQ rmqA(a);
        RMQ rmqB(b);
        for (int i = 1; i <= n; i++) {
            // cout << i << ' ';
            int left,right;
            if (i == n) {
                res[vt[arr[i].fi]] = 1;
            }
            else { 

                left = rmqB.queryMax(1,i);
                right = rmqB.queryMax(i+1,n);
                auto point = rmqB.queryMin(vtB[right],n);
                
                if (left > point) {
                    res[vt[arr[i].fi]] = 1;
                }
                else res[vt[arr[i].fi]] = 0; 
                // cout << i << ' ' << left << ' ' << point << ' ' << res[vt[arr[i].fi]] << ' ' << vt[arr[i].fi] << endl;
            }
            // cout << i << ' ' << left << ' ' << right << endl;
            // cout << res[vt[arr[i].fi]] << ' ' <<vt[arr[i].fi];
            // cout << endl;
            // cout << i << ' ' << arr[i].fi << ' ' << res[vt[arr[i].fi]] << ' ' << vt[arr[i].fi] << endl;
        }

        // res[vt[arr[i].fi]] = 1/0;

        vt.clear();
        vtB.clear();
        // cout << rmq.queryMax(2, 5);

        for (int i = 1; i <= n; i++) {
            swap(arr[i].first, arr[i].second);
            vt[arr[i].fi] = i;
        }
        sort(arr.begin(),arr.end());

        for (int i = 1; i <= n; i++) {
            a[i] = arr[i].fi;
            b[i] = arr[i].se;
            vtB[b[i]] = i;
        }

        RMQ rmqB2(b);
        for (int i = 1; i <= n; i++) {
            // cout << i << ' ';
            int left,right;
            if (i == n) {
                res[vt[arr[i].fi]] = 1;
            }
            else { 

                left = rmqB2.queryMax(1,i);
                right = rmqB2.queryMax(i+1,n);
                auto point = rmqB2.queryMin(vtB[right],n);
                
                if (left > point) {
                    res[vt[arr[i].fi]] = 1;
                }
                else res[vt[arr[i].fi]] = 0; 
                // cout << i << ' ' << left << ' ' << point << ' ' << res[vt[arr[i].fi]] << ' ' << vt[arr[i].fi] << endl;
            }
            // cout << i << ' ' << left << ' ' << right << endl;
            // cout << res[vt[arr[i].fi]] << ' ' <<vt[arr[i].fi];
            // cout << endl;
            // cout << i << ' ' << arr[i].fi << ' ' << res[vt[arr[i].fi]] << ' ' << vt[arr[i].fi] << endl;
        }

        // res[vt[arr[i].fi]] = 1/0;

        for (auto i : res) cout << i.se;
        cout << endl;
        a.clear();
        b.clear();
        arr.clear();
        vt.clear();
        vtB.clear();
        res.clear();
    
    }
    
    return 0;
}