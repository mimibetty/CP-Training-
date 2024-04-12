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
 

map<int,int>d;
int a[100005];
void solve() {
    int n;
    cin >> n;
    vector<int>d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;

        vt[x].pb(i);
    }

    for (auto i : d) {
        for ()
    }
}
int main() {
    // if(fopen("YOUTH.INP", "r")) {
    //     freopen("YOUTH.INP","r",stdin);
    //     freopen("YOUTH.OUT","w",stdout);
    // }
      if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve(); 

    return 0;
}