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
bool res[100005];
void solve() {
    int n;
    cin >> n;
    string s ;
    cin >> s;
    s = ' ' + s;


    string tmp = s;
    reverse(All(tmp));
    if (s == tmp) res[0] = 1;


    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 1; i <= n/2; i++) {
        if (s[i] != s[n-i+1]) cnt1++;
        else cnt2++;
    }
    // cout << cnt1 << ' ' << cnt2<< endl;
    int z = cnt1;
    res[z] = 1;
    for (int i = 1; i <= cnt2; i++) {
        z += 2;
        res[z] = 1;
    }
    if (n % 2 == 1) {
        for (int i = n-1; i >= 0; i--) {
            if (res[i] == 1) {
                res[i+1] = 1;
            }
        } 
    }

    // if (n % 2 == 1) {
    //     z = 1;
    //     res[1] = 1;
    //     z += cnt1;
    //     res[z] = 1;
    //     for (int i = 1; i <= cnt2; i++) {
    //         z += 2;
    //         res[z] = 1;
    //     }   
    // }
    for (int i = 0; i <= n; i++) cout << res[i];
    cout << endl;
    for (int i = 0; i <= n; i++) res[i] = 0;

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