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
    long long n;
    cin >> n;
    unsigned long long summ = 0;
    ll res = 0;
    while (summ < n) {
        long long nn = n - summ;
        unsigned long long del = 1 +8*nn;
        unsigned long long xx = sqrt(del);
        unsigned long long r = xx + 1;
        r/= 2;
        unsigned long long ex = r *(r-1)/2;
        summ += ex;
        res += r;
        cout << summ << ' ' << res << " " << ex <<" " << r <<endl;
    }    
    cout << res <<endl;

}
void solve1() {
    unsigned long long n;
    cin >> n;
    
    unsigned long long del = 1 +8*n;
    unsigned long long xx = sqrt(del);
    unsigned long long r = xx + 1;
    // if (del == xx * xx) {
    //     if (r % 2 == 0) {
    //         cout  <<  r/2 <<endl;
    //         return;
    //     }
    // }
    r/= 2;
    ll comp = r *(r-1)/2;
    while(comp > n) {
        r--;
        comp = r *(r-1)/2;
    }
    unsigned long long ress = r *(r-1)/2;
    unsigned long long cc = n - ress + r;
    cout << cc <<endl;
    // cout << cc << " " << n - ress << ' ' << r << ' ' << ress<<endl;
    // cout <<z << endl << endl;
}

// 
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // unsigned long long x = 1ll*1414213562 *(1414213562- 1) /2;
    // unsigned long long x2 = 1000000000000000000 -x;
    // cout <<x2 << endl;
    // cout << 2648956421 - 1414213562 << endl;
    // cout << x <<endl;
    int t;
    cin >> t;
    while (t--)
    solve1();
    
    return 0;
}