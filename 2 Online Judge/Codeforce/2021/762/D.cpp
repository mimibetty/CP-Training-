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
 
int n,m;
vector<vector<int>> a;

int check(int mid) {
    bool pair = 0;
    vector<bool>cs(n);
    for (int i = 0; i < m; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] >= mid) {
                cs[j] = true;
                c++;
            }
        }
        if (c > 1) pair = true;
    } 

    if (!pair) { // ko co cua hang nao ban duoc 2 mon qua,  !pair => pair == 0, if(pair) pair != 0
        return 0;
    }
    int x = pair;
    for (auto j : cs) {
        x = x & j;
    }

    if (x) return 1;
    return 0;
}

void solve() {
    cin >> m >> n;
        a.assign(m, vector<int>(n)); // tạo m khoảng trống vector chứa vector size(n) 

    for (int i = 0 ; i < m; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> a[i][j]; 
        }
    }

    int lower = 0, uper = 1e9;
    while (lower < uper) {
        int mid = (lower + uper + 1) / 2;
        if (check(mid)) {
            lower = mid;
        }
        else uper = mid - 1;
        // cout << mid << endl;
    }

    cout << lower << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;

 	while (t--) {
 		solve(); 		
 	}
    return 0;
}