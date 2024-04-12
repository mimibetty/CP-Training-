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

string s[4];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n = 10; 
    pii vt;
    for (int i = 1; i <= 3; i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10; j++) {
            if (s[i][j] =='=') {
                vt = {i,j};
            }
        }
    }
    string res = "You shall pass!!!";
    while (vt.se < 10) {
        vt.se++;
        if (s[vt.fi][vt.se] !='.') {
            res = s[vt.fi][vt.se];
            cout <<res <<endl;
            return 0;
        }
    }
    cout << res;

    return 0;
}