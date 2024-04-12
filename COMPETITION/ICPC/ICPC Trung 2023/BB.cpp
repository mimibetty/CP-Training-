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
const ll maxN = ll(2e5 + 1);

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

vector<vector<ll>> g(maxN, vector<ll>(0));

vector<ll> cur;
ll calc(ll a, ll b, ll k)
{
    if(a == b)
    ll res = 0;
    for(auto i: g[a])
    {
        res += calc(i, b, k - 1);        
    }

    return res;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
       {
           cin >> a[i];
       }   
       sort(All(a));
       // for(int i = 0; i < n; i ++ )
       // {
       //  cout << a[i] << " ";
       // }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if(__gcd(a[i], a[j]) == 1)
            {
                g[a[i]].push_back(a[j]);
            }  
        }
    }
    // for(int i = 0; i < 10; i++)
    // {
    //     cout << i << ": " << " ";
    //     for(auto j: g[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    for(auto i: cur)
    {
        cout << i << " ";
    }
    cout << endl;
    ll q;
    cin >> q;

    while(q--)
    {
        ll a, b, k;
        cin >> a >> b >> k;

        cout << calc(a, b, k + 1) << endl;
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
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}