#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;


#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);

bool check_palin(string s) {
    string a = s;
    reverse(All(a));
    if (s == a) return 1;
    return 0;
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {

    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (k == 0) {
        cout << "YES" << endl;
        continue;   
    }
    if (n % 2 == 0 && k == (n/2)) {
        cout << "NO" << endl;
        continue;
    }
    // cout << s.substr(0,k);
    string d = s.substr(0, k) + s.substr(n-k,n-1);
    if (check_palin(d) == 1) cout << "YES";
    else cout << "NO";
    cout << endl;    

    }
    return 0;
}

// 7
// 5 1
// qwqwq
// 2 1
// ab
// 3 1
// ioi
// 4 2
// icpc
// 22 0
// dokidokiliteratureclub
// 19 8
// imteamshanghaialice
// 6 3
// aaaaaa
