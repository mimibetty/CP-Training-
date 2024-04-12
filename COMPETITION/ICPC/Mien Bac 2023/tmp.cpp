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
    
}
const int limm = 1e7;
long long a[10000000];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long n;
    cin >> n;
    a[0] = 1;
    a[1] = 0;
    a[2] = 0;
    a[3] = 1;
    a[4] = 4;
    long long modd = 987654321;
    for (int i = 5; i <= limm; i++) {
        a[i] = 5*a[i-1] -10*a[i-2] + 10*a[i-3] - 5*a[i-4] + a[i-5];
        // a[i] %= modd;
        a[i] = (a[i]%modd + modd) %modd;
    }
    if (n > limm) while (1) {

    }
    // cout << a[n];
    // for (int i = 1; i <= 30; i++) {
    //     cout << a[i] << endl;
    // }
    cout <<a[10000000];
       
    return 0;
}