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

ll a[20000];

bitset<10>bs;
int b[13];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll k,n;
    cin >> k >> n;
    for (int i = 1; i <= n; i++ ) cin >> a[i];
    sort(a + 1 , a + 1 + n);
    ll time = 0, ac = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        bs = bit;
        if (bs.count() < ac) continue;
        vector<int>z;
        ll ss = 0;
        for (int i = 0; i < n; i++) {
            if (bs[i]) {
                z.pb(a[i+1]);
                ss += a[i+1];
            }
        }
           
        if (ss > k) continue;

        int nn = z.size();
        for  (int i = 1; i <= nn; i++) b[i] = z[i-1];
        // for  (int i = 1; i <= nn; i++) cout << b[i] << endl;;
        // for (auto i : z) cout << i << ' ';

        do {
            ll s = 0;
            for (int i = 1; i <= nn; i++) {
                s += b[i]*(i);
            }
            s %= 1440;
            if (z.size() == ac) { 
                time = min(time,s);
            }   
            if (z.size() > ac) { 
                ac = z.size();
                time = s;
            }
            // if (z.size() == 5) {
            //     cout << z.size() << ' ' << s<< endl;
            //     for (int i = 1; i <= nn; i++) cout << b[i] << endl;
            //     // for (auto i : z) cout << i << ' ';
            //     EL;
            //     EL;
            // }
        } while(next_permutation(b + 1, b + 1 + nn) );
        
    }
    cout << ac << ' ' <<time <<endl;     
    return 0;
}       