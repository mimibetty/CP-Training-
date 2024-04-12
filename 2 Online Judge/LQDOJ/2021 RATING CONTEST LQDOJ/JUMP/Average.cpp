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
 

// struct RMQ {
//     vector<long long> a;
//     vector<vector<long long>> sparseMax, sparseMin;
//     long long n;
//     RMQ(vector<long long> arr) {
//         a = arr;
//         n = arr.size();
//         sparseMax.resize(n);
//         sparseMin.resize(n);
//         for (long long i = 0; i < n; i++) {
//             sparseMax[i].resize(__lg(n) + 1);
//             sparseMax[i][0] = a[i];

//             sparseMin[i].resize(__lg(n) + 1);
//             sparseMin[i][0] = a[i];
//         }

//         for (long long len = 1; len < __lg(n) + 1; len++) {
//             for (long long i = 0; i + (1 << (len - 1)) < n; i++) {
//                 sparseMax[i][len] = max(sparseMax[i][len - 1], sparseMax[(1 << (len - 1)) + i][len - 1]);
//                 sparseMin[i][len] = min(sparseMin[i][len - 1], sparseMin[(1 << (len - 1)) + i][len - 1]);
//             }
//         }
//     }

//     long long queryMax(long long l, long long r) {
//         long long k = __lg(r - l + 1);
//         return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
//     }

//     long long queryMin(long long l, long long r) {
//         long long k = __lg(r - l + 1);
//         return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
//     }

//     // find Max, Min, Gcd
// };

double a[1000005];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n,l,r;
 	cin >> n >> l >> r;

 	vector<double>ps(n+2);
 	ps[0] = 0;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		ps[i] = ps[i-1] + a[i];
 		// cout <<ps[i] << ' ' ;
 	}
 	// cout << endl;
 	// RMQ.rmq(ps);
 	precision(4);
 	double res = -1e16;
 	for (int i = 1; i <= n-l+1; i++) {
 		// cout << i << endl;
 		for (int j = l; j <= r; j++) {
 			if (i + j - 1 > n) break;
 			else {
 				double x = (ps[i+j-1] - ps[i-1]) / (j);
 				res = max(res, x);
 				// cout << i << ' ' << j + i - 1 <<  ' ' << ps[i-1] << ' ' << ps[i+j-1] << ' ' <<x << endl;
 			}
 		}
 	}
 	cout << res;
    return 0;
}