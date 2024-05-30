/*
link submit: 
Note:
https://en.wikipedia.org/wiki/Derangement
https://www.youtube.com/watch?v=6ENst56fdPc&ab_channel=NeatlyStructured
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

const long long MODD = 1e9 + 7;
long long derangement[1000005];


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long n;
    cin >> n;
    derangement[1] = 0;
    derangement[2] = 1;
    for (int i = 3; i <= n; i++) {
        derangement[i] = derangement[i-1] * i + pow(-1, i);
        derangement[i] %= MODD;
    }
    cout << derangement[n] << endl;
    return 0;
}