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

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
		int n;
		string a,b;
		cin >> n >> a >> b;

		int ans1,ans2;
		int dung1 = 0, dung0 = 0,sai1 = 0, sai0 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				if (a[i] == '1') dung1++;
				else dung0++; 
			}
			else {
				if(a[i] == '1') sai1++;
				else sai0++;
			}
		}

		if(sai1 + sai0 == 0) {
			cout << 0 << endl;
			continue;
		}    
	    
	    if ((dung1-dung0 == 0 || dung1-dung0 == 1) && (dung1 + dung0) % 2 == 1){
	        ans1 = dung1 + dung0;
	    }
	    else ans1 = 1e9;
	    
	    if ((sai1 - sai0 == 0 || sai1 - sai0 == 1) && (sai1 + sai0) % 2 == 0){
	        ans2 = sai1 + sai0;
	    }
	    else ans2 = 1e9;
	    
	    if (ans1 == 1e9 && ans2 == 1e9) {
	        cout<< -1 << endl; 
	    }
	    else cout << min(ans1,ans2) << endl;

 	}
    return 0;
}