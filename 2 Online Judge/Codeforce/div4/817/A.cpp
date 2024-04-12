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
    
    int n;
    cin >> n;
    string f = "Timur";
    while (n--) {
        int z;
        cin >> z;

        string s;
        cin >> s;
        if (z != 5) {
            cout << "no" <<endl;
            continue;
        }
        map<char,int>d;
        for (int i = 0 ; i < f.size(); i++) {
            d[f[i]]--;
        }

        for (int i = 0; i < s.size(); i++) {
            d[s[i]]++;
        }

        bool ok = 0;
        // for (auto i : d) {
        //     cout << i.fi << ' ' << i.se << endl;
        // }
        for (auto i : d) {
            if (i.se != 0) {
                ok = 1;
                break;
            } 
        }
        if (ok) cout << "no" << endl;
        else cout << "yes" << endl;

        d.clear();
    }


    return 0;
}