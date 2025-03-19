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

int solve(int a, int b) {
    a = a + 2 ;
    return a + b;
}

int solve2(int &a, int &b) {
    a = a + 2 ;
    return a + b;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int a1= 1,a2=5,b1 = 1,b2 = 5;
    cout <<solve(a1,b1) << endl;
    cout << a1 << ' ' << b1 << endl;


   cout <<solve2(a1,b1) << endl;
    cout << a1 << ' ' << b1 << endl;

    int b = a1;
    int c = a2;
    cout << b << ' ' << c << endl;
    return 0;
}


1/To   tp (|xt|2)  (0 to to)
1/To   tp (A^2)  (0 to to)
    (A^2)to /T0 
    1 *to / (3to) = 1/3
    A = 1
    To = 3to