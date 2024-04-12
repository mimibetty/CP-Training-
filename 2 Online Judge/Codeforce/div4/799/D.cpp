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


void solve() {
    string s;
    cin >> s;

    int x;
    cin >> x;

    int cnt = 0;
    int h,phut;
    h = (s[0] - '0') * 10 + (s[1] - '0');
    phut = (s[3] - '0') * 10 + (s[4] - '0');

    map<string,int>f;
    set<string>fff;
    string d,dd;
    d += (h/10)  +  '0';
    d += (h%10)  +  '0';
    d += (phut/10) + '0';
    d += (phut%10) + '0';
    dd = d;
    reverse(dd.begin(),dd.end());
    if (d == dd)  {
        f[d]++;
        fff.insert(d);
    }
    while (1) {
        for (int i = 1 ; i <= x; i++) {
            phut++;
            if (phut == 60) {
                phut = 0;
                h++;
                if (h == 24) h = 0;
            }
        }
        d.clear();
        dd.clear();

        d += (h/10)  +  '0';
        d += (h%10)  +  '0';
        d += (phut/10) + '0';
        d += (phut%10) + '0';
        dd = d;
        f[d]++;
        if (f[d] == 2) break;
        reverse(dd.begin(),dd.end());
        if (d == dd)  {
            fff.insert(d);
        }

    }
    // cout << h << ' '<< phut << endl;
    cout <<fff.size() << endl;
    // for (auto i: f) cout << i << ' ';
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