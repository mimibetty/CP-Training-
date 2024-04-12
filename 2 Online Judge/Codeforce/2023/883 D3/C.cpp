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

ll p[200005];
ll time1[200005];
void solve() {
    ll n , m , h;
    cin >> n >> m >> h;
    vector<vector<ll>>a;
    a.resize(n + 2);
    for (int i = 1; i <= n; i++) {
        a[i].resize(m);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(All(a[i]));
    }

    for (int i = 1; i <= n; i++) {
        ll timee = 0;
        for (int j = 0; j < m; j++) {
            timee += a[i][j];
            if (timee <= h) {
                p[i]++;
                time1[i] += timee;
            }
            else break;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << p[i] << ' ' << time1[i] << endl;
    // }
    int res = 1;
    for (int i = 2; i <= n; i++) {
        if (p[1] < p[i]) res++;
        else if (p[1] == p[i] && time1[1] > time1[i]) res++;   
    }
    cout <<res <<endl;

    for (int i = 1; i <= n; i++) {
        p[i] = 0;
        time1[i] = 0;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << time1[i] << ' ' << p[i] << endl;
    // }
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