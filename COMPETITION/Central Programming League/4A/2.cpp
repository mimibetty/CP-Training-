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

int a,b,c,k,d;
void out(int x, int y, int z) {
    cout << x << ' ' << y << ' ' << z << endl;
    return;
}

void solve() {
    if (a + c < k) {
        int cuu = 0;
        for (int i = 1; i <= 1000;i++) {
            if (cuu >= b) {
                cout << "-1 -1 -1\n";
                break;
            }
            else {
                int cnt = min(b - cuu, k - a - c);
                cuu += cnt;
                // cout <<"ssss  " <<  i << ' ' << cnt << ' ' << cuu << endl;
                cout << a << ' ' << cnt << ' ' << c << endl;
                if (cuu >= b) {
                    cout << "-1 -1 -1\n";
                    // cout << "sos ii  ";
                    break;           
                }
                cout << a << ' ' << 0 << ' ' << c << endl;
            }
        }
        return;
    }





    if (b < k) {
        int soi = 0, cai = 0;
        for (int i = 1; i <= 1000;i++) {
            // cout << "SOI   ";
            if (soi >= a) {
                if (cai >= c) {
                    cout << "-1 -1 -1 \n";
                    return;
                }
            }
            else {
                int cnt = min(a - soi, k - b);
                soi += cnt;
                cout << cnt << ' ' << b << ' ' << 0 << endl;
                if (soi >= a) {
                    if (cai >= c) cout << "-1 -1 -1\n";
                    else {
                        cout << 0 << ' '<< b << ' ' << 0 << endl;;
                    }
                    break;           
                }
                // cout <<"ve " ;
                cout << 0 << ' ' << b << ' ' << 0 << endl;
            }
        }

        for (int i = 1; i <= 1000;i++) {
            // cout << "CUU   ";
            if (cai >= c) {
                cout << "-1 -1 -1\n";
                return;
            }
            else {
                int cnt = min(c - cai, k - b);
                cai += cnt;
                cout << 0 << ' ' << b << ' ' << cnt << endl;
                if (cai >= c) {
                    cout << "-1 -1 -1 \n";
                    return;
                }
                // cout << "ve ";
                cout << 0 << ' ' << b << ' ' << 0 << endl;
            }
        }
        return;
    }


    if (b == k && d <= 2*k) {
        int cuu = 0, soi = 0, cai = 0;
        out(0,b,0);
        out(0,0,0);
        soi = min(k, a);
        cai = max(0, k - soi);

        out(soi,0, cai);
        out(0,b,0);

        out(a - soi, 0, c - cai);
        out(0,0,0);
        out(0,b,0);
        out(-1,-1,-1);
        return;
    }

    if (d == k && b <= 2*k) {
       int cuu = 0, soi = 0, cai = 0;
        out(a,0,c);
        out(0,0,0);
        // soi = min(k, a);
        // cai = max(0, k - soi);
        cuu = max(k - cuu,0);
        out(0,cuu, 0);
        out(a,0,c);

        // out(a - soi, 0, c - cai);
        out(0,b - cuu,0);
        out(0,0,0);
        out(a,0,c);
        out(-1,-1,-1);
        return;
    
    }
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
        cin >> a >> b >> c >> k;
        d = a + c;
        if(max(a, max(b,c)) <= k||b < k|| a+c < k|| 
        (b == k && a+c <= k*2) || ( a+c == k && b <= k*2)) solve();
        else cout<<"0 \n";
    }   
    return 0;
}