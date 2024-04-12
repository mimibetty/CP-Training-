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
bitset<30>bs;

int a[2000];
void solve() {
    int n;
    cin >> n;
    // cout << "OKK  "<< n <<endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    vector<int>zz;
    for (int bit = 1; bit < (1 << n) - 1; bit++) {
        bs = bit;
        vector<int>t1,t2;
        for (int i = 0; i < n; i++) {
            if (bs[i] == 0) t1.pb(a[i]);
            else t2.pb(a[i]);
        }

        int tmp = 2e9;
        for (int i = 0; i < t1.size(); i++) {
            for (int j = 0; j < t2.size(); j++) {
                    tmp = min(tmp, (t1[i]^t2[j]));
            }
            // cout <<t1[i] <<endl;
        }
        // for (auto i : t1) cout << i << ' ';
        // EL;

        // for (auto i : t2) cout << i << ' ';
        // EL;
        // cout <<tmp <<endl << endl;
            
        res = max(res, tmp);
    }

    for (int bit = 1; bit < (1 << n) - 1; bit++) {
        bs = bit;
        vector<int>t1,t2;
        for (int i = 0; i < n; i++) {
            if (bs[i] == 0) t1.pb(a[i]);
            else t2.pb(a[i]);
        }

        int tmp = 2e9;
        for (int i = 0; i < t1.size(); i++) {
            for (int j = 0; j < t2.size(); j++) {
                    tmp = min(tmp, (t1[i]^t2[j]));
            }
            // cout <<t1[i] <<endl;
        }
        if (tmp != res) continue;
        for (auto i : t1) cout << i << ' ';
        EL;

        for (auto i : t2) cout << i << ' ';
        EL;
    EL;     
        // cout <<tmp <<endl << endl;
            
        res = max(res, tmp);
    }

    vector<int>t;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if((a[i]^a[j]) == res) {
                cout <<"this   " <<a[i] << ' ' << a[j] <<endl;
            }
            t.pb(a[i]^a[j]);  
        }  
    }
        sort(All(t));
        for (auto i : t) cout << i << ' ';
        EL;
    cout <<"resss   "  <<res <<endl << endl; 
    // cout <<res <<endl;
}

void solve2() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    long long x = a[1]^a[n];
    cout << x <<endl;
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
    while (t--) 
    solve();
    
    return 0;
}