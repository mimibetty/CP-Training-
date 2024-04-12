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

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    long long num = n*2;
    ll sum = (num+1)*num/2;
    ll sumxy = sum*2 / (n);
    ll x = (sumxy + n) / 2;
    ll y = sumxy - x;
    swap(x,y);
    cout << x << ' ' << y;
    // cout << sumxy;
    // x + y = sumxy;
    // y - x = n; 
    // 2y = sumxy + n
    // 9 10 11 12 13
    // (x+y) ( y - x + 1) = sum * 2;
    
    return 0;
}