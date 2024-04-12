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
 
long long arr[1000];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
		ll n,k;
        cin >> n >> k;
        long long res = 0;
        for (int i =0 ;i < n;i++) {
            cin >> arr[i];
        }

        sort(arr,arr+n);
        ll l;
        l=n-2*k;
        for (int i = 0; i < l; i++){
            res+=arr[i];
        }

        ll count = 1;
        ll maxx = 0;

        for (int i =l+1; i<n; i++){
            if (arr[i] == arr[i-1]) {
            	count++;	
            }
            else {
            	maxx = max(maxx,count);
            	count = 1;
            } 
            maxx = max(maxx,count);
        }

        // cout << maxx << endl;
        if (2*maxx >= 2*k) {
        	// cout << 0;
        	res += (2*k - ((2*k-maxx) * 2)) /2;
        }

        // res+=(maxx - (2 * k - maxx))/2;  // tui trung nhau chiem duoi 50%
        cout << res << endl;
 	}
    return 0;
}