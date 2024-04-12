#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
 
const int lim = 45000000;
bitset<lim>prime;
vector<ll>sieve;
ll ps[3000000];
// vector<ll>ps;

void normalSieve(ll n)
{
    //bool prime[n/2];
    //memset(prime, false, sizeof(prime));
 
    for (ll i=3 ; i*i < n; i+=2)
    {
        if (prime[i/2] == false)
            for (ll j=i*i; j<n; j+=i*2)
                prime[j/2] = true;
    }
 
    //prllf("2 ");
    sieve.push_back(2);
    ps[0] = 2;
    int cnt = 1;
    for (ll i=3; i<n ; i+=2) {
        if (prime[i/2] == false) {
           //prllf( "%d " , i );
            sieve.push_back(i);
            ps[cnt] = ps[cnt - 1] + i;
            cnt++;
            // cout << i << endl;
        }
    }
}
 
int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    normalSieve(lim);
    // cout << sieve.size() << endl;
    // ps[0] = sieve[0];
 	// cout << ps[0] << endl;
 	// cout << sieve[0] << endl;

 	// for (int i = 1; i < sieve.size(); i++) {
 	// 	ps[i] = ps[i-1] + sieve[i];
 	// }


 	int t;
 	cin >> t;
 	while (t--) {
 		int n;
 		cin >> n;
 		cout << ps[n-1] << endl;
 	}
    return 0;
}