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

struct Data{
    int x,y;

};

Data a[2005];
bitset<22>bs;
long long dis(Data &a, Data &b) {
    long long f = 0;
    f = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    return f;  
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int m,n;
    cin >> m >> n;
    int s = n + m;
    for (int i = 1; i <= m + n; i++) {
        cin >> a[i].x >> a[i].y;
        swap(a[m], a[s]);
    }

    Data start = {a[1].x, a[1].y};
    Data end = {a[s].x, a[s].y};
    
    vector<Data> d;
    vector<int>zz;
    for (int i = 2; i < s; i++) {
        d.pb({a[i].x, a[i].y});
    }
    for (int i = 0; i < d.size(); i++) {
        zz.pb(i);
    }
    sort(zz.begin(), zz.end());
    int siz = s - 2;
    
    long long res = 1e18;
    do {
        // for (auto i : zz) cout << i << ' ';
        //     cout << endl;

        long long temp = 0;
        for (int i = 1; i < siz; i++) {
            temp += dis(d[zz[i]], d[zz[i-1]]);
        }
        // cout << temp << endl;
        temp += dis(d[zz[0]], start);
        temp += dis(d[zz[siz - 1]], end);
        
        // cout << "TT " << endl;
        // for (auto i : zz) cout << i << ' ';
        // cout << endl;
        // for (auto i : zz) {
        //     cout << i << " " << d[i].x << ' ' << d[i].y << endl;
        // }
        // cout << endl;
        // cout << temp << endl;
        // cout << endl;



        res = min(res, temp);
        
    } while (next_permutation(zz.begin(), zz.end()));


    cout <<res <<endl;

    return 0;
}