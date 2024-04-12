/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
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
    
    cout << 7*15;
    ll n;
    cin >> n;
    int a[200];
    for (int i = 1; i <= 2*n; i++) {
        a[i] = i;
    }
    sort(a+1,a+1+2*n);
    
    do {
        vector<ll>f;
        for (int  i = 1; i <= 2*n; i+=2) f.pb(a[i] + a[i+1]);
        sort(All(f));
        bool ok = 1;



        // for (int i = 1; i <= 2*n; i++) {
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
        // for (auto i : f)cout << i << ' ';
        // cout << endl;
        

        for (int i = 0; i < f.size() - 1; i++) {
            if (f[i] != f[i+1] - 1) {
                ok = 0;
                break;
            }
        }

        if (ok == 1) {
            for (int i = 1; i <= 2*n; i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
            for (auto i : f) cout << i << ' ';
                cout << endl;
            break;
        }
        // else {
        //     cout << n << "   NO " << endl;
        // }

    } while(next_permutation(a + 1, a + 1 + 2*n) );

    return 0;
}