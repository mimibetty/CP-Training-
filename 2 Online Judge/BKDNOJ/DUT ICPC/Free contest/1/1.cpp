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
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
const int limx = 1e6;

// int a[1005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int cnt = 0;
        map<int,bool>d;
        int n;
        cin >> n;
        vector<int>a;
        for (int i = 1; i <= n; i++) {
            int s;
            cin >> s;
            a.pb(s);
            d[s] = 1;
        }

        bool check = 0;
        while (check == 0) {
            check = 1;
            for (int i = 0; i < (a.size()-1);i++) {
                bool done = 0;
                for (int j = i+1; j < a.size(); j++) {
                    int val = abs(a[i] - a[j]); 
                    if (d[val] == 0) {
                        d[val] = 1;
                        cnt++;
                        a.pb(val);
                        check = 0;
                        done = 1;
                        break;
                    }
                }
                if (done == 1) break;
            }
            // for (auto i : a) cout << i << ' ';
            // cout << endl;
        }
        for(auto i :a)cout << i << ' ';
            cout << endl;
        d.clear();
        a.clear();
        if (cnt % 2 == 0) cout << "M";
        else cout << "DD";
        cout << endl;
        // cout << cnt << endl;

    }
    return 0;
}