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
 
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
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
    for (int z = 1; z <= t; z++) {
        int type;
        cin >> type;

        if (type == 1) {
            unsigned long long x;
            cin >> x;


            unsigned long long dd = x;
            string s;
            while (dd > 1) {
                if (dd % 2 == 0) {
                    s += 'L';
                }
                else {
                    s += 'R';
                }
                dd /= 2;
            }

            unsigned long long p = 1, q = 1;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == 'L') q = q + p;   
                else p = p + q;
            }
            cout << p << ' ' << q  << endl;
            s.clear();
        }
        else {
            unsigned long long ax,ay;
            cin >> ax >> ay; 
            // cout << ax << ' ' << ay << endl;
            // cout << 100 <<endl;
            string ss;
            while (ax != 1 || ay != 1) {
                // cout << ax << ' ' << ay << endl;
                if (ax > ay) {
                    ss += 'R';
                    ax -= ay;  

                } 
                else {
                    ss += 'L';
                    ay -= ax;
                }
            }
         

            unsigned long long vt = 1;
            for (int i = ss.size() - 1; i >= 0; i--) {
                if (ss[i] == 'L') vt = vt*2;   
                else vt = vt*2 + 1;
            }
            cout << vt << endl;
            
            ss.clear();
        }
    }


    return 0;
}