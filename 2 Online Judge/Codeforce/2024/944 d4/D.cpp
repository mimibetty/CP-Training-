/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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
    string s;
    cin >> s;
    int n = s.size();
    // int res = 1;
    // for (int i = 0; i < n- 1; i++) {
    //     if (s[i] == '1' && s[i+1] == '0') {
    //         cout << i << ' ';
    //         res ++;
    //     }
    // }
    // cout << res << endl;


    string s1 = s;
    sort(All(s1));
    if (s1 == s) {
        // cout << "EEEE" ;
        cout << 1 << endl;
        return;
    }


    int num = 1;
    for (int i = 0; i < n- 1; i++) {
        if (s[i] == '1' && s[i+1] == '0') {
            // if (i == n-2) num++;
            // else num+=2;
            num++;
        } 
       

    }

    cout << num << endl;
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
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}