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
    ll n;
    cin >> n;

    std::vector<ll> v(n);

    for(ll i=0; i<n; i++)
    {
        cin >> v[i];
    }

    std::vector<ll> a;
    ll sz = 0;
    for(ll i=0; i<n; i++)
    {
        if(a.empty() || a[sz - 1] * v[i] < 0)
        {
            a.push_back(v[i]);
            sz++;
        }
        else
        {
            a[sz - 1] += v[i];
        }
    }

    if(a.size() == 1)
    {
        ll sub;
        if(a[0] > 0)
            sub = min(v[0], v[n - 1]);
        else
            sub = max(v[0], v[n - 1]);
        cout << abs(a[0] - 2 * sub);
        return;
    }

    ll sum = a[0];
    ll sum2 = a[0];
    ll mx = INT_MIN;
    for(ll i=1; i<a.size(); i++)
    {
        mx = max({mx, abs(a[i] - sum), abs(a[i] - sum2), abs(a[i] - a[i - 1])});
        if(sum < 0)
            sum = a[i];
        else
            sum += a[i];
        if(sum2 > 0)
            sum2 = a[i];
        else
            sum2 += a[i];
    }
    sum = a[sz - 1];
    sum2 = a[sz - 1];
    for(ll i=sz - 2; i >= 0; i--)
    {
        mx = max({mx, abs(a[i] - sum), abs(a[i] - sum2)});
        if(sum < 0)
            sum = a[i];
        else
            sum += a[i];
        if(sum2 > 0)
            sum2 = a[i];
        else
            sum2 += a[i];
    }
    cout << mx;
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