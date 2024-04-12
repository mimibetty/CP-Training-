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
   long long n, a,b;
   cin >> n >> a >> b;
   // cout << n << ' ' << a << ' ' << b << endl;
   long long s1 = 0, s2 = 0;
   long long bcnn = a*b / __gcd(a,b);
   long long res = 0;
   long long x = n/b - n/a;
   if (bcnn == a) {
        for (int i = 1; i <= x; i++) {
            res+= i;
        }
        res =  (x + 1) * x/2;
        cout <<-res << endl;
   }
   else {
        long long numa = n/a - n/bcnn;
        s1 = numa *(n + 1) - (numa + 1) * numa / 2;
        // for (int i = 1; i <= numa; i++) {
        //     s1 += n-i+1;
        // }


        long long numb = n/b - n/bcnn;
        // for (int i = 1; i <= numb; i++) {
        //     s2+= i;
        // }
        s2 = (numb + 1) * numb / 2;
        res = s1 - s2;
        cout << res <<endl;
   }
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