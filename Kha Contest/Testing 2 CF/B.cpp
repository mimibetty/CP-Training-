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

void solve() {
        long long l,d,x;
        cin >> l >> d >> x;
        long double res = -100*l + x*(l + d);
        res /= (100 - x);
       
        // cout <<res <<endl;
        
        for (long long i = -1000000; i <= 1000000; i++) {
            long long tmp = res + i;
            if (tmp < 0) continue;

            long long left = tmp * (100 - x);
            long long right = -100*l + x*(l + d);
            // cout << i <<' ' << ff <<' ' << left << ' ' << right << endl;
            if (left >= right) {
                cout << tmp << endl;
                return;
            }
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
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}