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

int a[55];
int b[55];
int pos[55];
int vui[55];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        vector<int>l,r,d;

        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1, b + 1 +n);

        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                cnt++;
                for (int j = i + 1; j <= n; j++) {
                    if (a[j] == b[i]) {
                        l.pb(i);
                        r.pb(j);
                        d.pb(j-i);
                        
                        for (int z = i ; z <= j; z++) {
                            vui[z] = a[z];
                        } 
                        int kc = j-i;
                        for (int z = i; z <= j; z++) {
                            int vt = z;
                            int need = kc;
                            while (need > 0) {
                                if (vt == i) vt = j;
                                else vt--;
                                need--;
                            }
                            pos[z] = vt;
                            a[vt] = vui[z];
                        }
                        
                      
                        // for (int z = i; z <= j; z++) cout << pos[z] << endl;
                        // return 0;
                        break;
                    }
                }
            }
                   }

        cout << cnt << endl;
        for (int i = 0 ; i < cnt; i++) {
            cout << l[i] << ' ' << r[i] <<' ' << d[i] << endl;
        }
        l.clear();
        r.clear();
        d.clear();

        for (int i = 0; i <= n; i++) {
            a[i] = 0;
            b[i] = 0;
            pos[i] = 0;
            vui[i] = 0;
        }
    }

    return 0;
}