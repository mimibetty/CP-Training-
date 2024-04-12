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

int n;
long long prize[4];
void solve() {
    cin >> n;
    string s;
    long long res = 0;
    map<string,int>f2,f3; 
    for (int i = 1; i <= n; i++) {
        cin >> s;
        string z;
        z += s[4];
        z += s[5];
        f3[z]++;
        
        string ff;
        ff += s[2];
        ff += s[3];
        ff += z;
        f2[ff]++; 
    }    
    for (auto i : f2) {
        cout << i.fi << ' ' << i.se <<endl;
    }


    for (auto i : f3) {
        cout << i.fi << ' ' << i.se <<endl;
    }

    prize[1] = 300000;
    prize[2] = 4000;
    prize[3] = 500;
    for (int i = 0; i <= 9999; i++) {
        for (int j = 0; j <= 99; j++) {
            if (i % 100 == j) continue;
            
            string z2 = to_string(i);
            string z3 = to_string(j);
            while(z2.size() < 4) {
                z2 = '0' + z2;
            }
            while(z3.size() < 2) {
                z3 = '0' + z3;
            }

            if (z2[0] == z3[2] && z2[1] == z3[3]) {
                continue;
                // res = max({res, prize[1] + f3[z3]*prize[3], prize[1] + f2[z2]*prize[2]});
            }
            else {
                if (f2[z2] + f3[z3] == n) {
                    if (f2[z2] == n) {
                        res = max({res, f2[z2] * prize[2], prize[1] + f3[z3] * prize[3]*f3[z3]});
                        continue;
                    }
                    if (f3[z3] == n) {
                        res = max({res, f3[z3] * prize[3], prize[1] + f2[z2] * prize[2]*f2[z2]});
                        continue;
                    }


                    res = max({res, prize[1] + f3[z3]*prize[3]
                        , prize[1] + f2[z2]*prize[2], prize[2]*f2[z2] + prize[3]*f3[z3]});

                }
                else {
                    res = max(res, prize[1] + prize[2] * f2[z2] + prize[3] * f3[z3]);
                }
            }
        }
    }
    cout <<endl << endl;
    for (int i = 0; i <= 9999; i++) {
        for (int j = 0; j <= 99; j++) {
            if (i % 100 == j) continue;
            long long tmp = 0;
            string z2 = to_string(i);
            string z3 = to_string(j);
            while(z2.size() < 4) {
                z2 = '0' + z2;
            }
            while(z3.size() < 2) {
                z3 = '0' + z3;
            }

            if (z2[0] == z3[2] && z2[1] == z3[3]) {
                // cout <<"AAAA  " << z2 << ' ' << z3 << endl;
                continue;
                // res = max({res, prize[1] + f3[z3]*prize[3], prize[1] + f2[z2]*prize[2]});
            }
            else {
                if (f2[z2] + f3[z3] == n) {
                    if (f2[z2] == n) {
                        tmp = max({tmp, f2[z2] * prize[2], prize[1] + f3[z3] * prize[3]*f3[z3]});
                        continue;
                    }
                    if (f3[z3] == n) {
                        tmp = max({tmp, f3[z3] * prize[3], prize[1] + f2[z2] * prize[2]*f2[z2]});
                        continue;
                    }


                    tmp = max({tmp, prize[1] + f3[z3]*prize[3]
                        , prize[1] + f2[z2]*prize[2], prize[2]*f2[z2] + prize[3]*f3[z3]});

                }
                else {
                    tmp = max(tmp, prize[1] + prize[2] * f2[z2] + prize[3] * f3[z3]);
                }
            }
            if (tmp == res) {
                cout << z2 << ' ' << z3 <<endl;
            }
        }
    }
    cout << res <<endl;
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
