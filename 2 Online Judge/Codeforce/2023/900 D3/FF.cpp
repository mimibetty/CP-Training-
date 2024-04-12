/*
link submit: 
Note: cách này bị runtime do N * x quá lớn 
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
int countDiv(long long x) {
    int res = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) res+=2;
    }

    long long z = sqrt(x);
    if (z * z == x) res--;
    return res;
}
void solve() {
    long long n,t;
    map<long long,long long>d;
    map<long long,long long>d1;

    cin >> n >> t;
    long long tmp = n;
    if (n != 1) {
        for (int i = 2; i <= sqrt(n); i++) {
            while (tmp % i == 0) {
                d[i]++;
                tmp /= i;
            }
        }
        if (tmp > 1) {
            d[tmp]++;
        }

        for (auto i : d) {
            d1[i.fi] = d[i.fi];
        }
    }
    tmp = n;

    while (t--) {
        int type;
        cin >> type;
        // cout <<"type  " << type << endl;
        if (type == 2) {
            // cout <<"ss  " <<  type << endl;
            // cout << nowDiv <<' ' << tmp << endl;
            d1.clear();
            for (auto i : d) {
                d1[i.fi] = d[i.fi];
            }

        }
        else {
            bool ok =1;
            long long x;
            cin >> x;
            if (x != 1) {
                long long tt = x;
                for (int i = 2; i <= sqrt(x); i++) {
                    if (tt % i == 0) {
                        int cnt = 0;
                        while (tt % i == 0) {
                            cnt++;
                            tt /= i;                            
                        }
                        if (d1[i] < cnt) ok = 0;
                        d1[i] += cnt;
                        cout << i << ' ' << cnt << endl;
                    }
                }
                if (tt > 1) {
                    cout << tt << ' ' << d1[tt] << endl;
                    if (d1[tt] <= 0) ok = 0;
                    d1[tt]++;
                }
            }
            if (ok == 1) {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        // EL;
    }
    EL;
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