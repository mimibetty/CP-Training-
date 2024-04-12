#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
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
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int a[5][5];
int x[1005][10];
double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
  
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{  
   double A = area (x1, y1, x2, y2, x3, y3);
  
   double A1 = area (x, y, x2, y2, x3, y3);
  
   double A2 = area (x1, y1, x, y, x3, y3);
  
   double A3 = area (x1, y1, x2, y2, x, y);
    
   return (A == A1 + A2 + A3);
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 1; i <= 3; i++) {
        cin >> a[i][1] >> a[i][2];
        // cout << a[i][1] << ' ' <<a[i][2] << endl;
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i][1] >> x[i][2];
    }

    long double S = 1.0 *abs(1.0*(a[2][1] - a[1][1])*(a[3][2] - a[1][2]) - 1.0*(a[3][1] - a[1][1])*(a[2][2] - a[1][2]) )/2; 
    precision(1);
    cout << S <<endl;

    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (isInside(a[1][1], a[1][2], a[2][1] , a[2][2] , a[3][1] , a[3][2] , x[i][1] , x[i][2] )) cnt++;
    }
    cout << cnt;
    return 0;
}