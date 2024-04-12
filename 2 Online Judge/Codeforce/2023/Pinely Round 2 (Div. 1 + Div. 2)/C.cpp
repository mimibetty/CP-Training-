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

int a[200005];
void solve() {
    int n,k;
    cin >> n >> k ;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];               
    }

    for (int i = 1; i <= k; i++) {
        cout << i << "   ";
        for (int j = 1; j <= n; j++) {
            map<int,int>d;
            for (int z = 1; z <= n; z++) {
                d[a[z]]++;
            }
            for (int z = 0; z <= n; z++) {
                if (d[z] == 0) {
                    a[j] = z; 
                    break;
                } 
            }
            cout << a[j] << ' ';
        }
        EL;
    }
    // for (int i = 1 ;i<= n; i++) cout << a[i] << ' ';
    // EL;
}

void solve2() {
        int n,k;
    cin >> n >> k ;
    set<int>f;
    set<int>s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(i);
        f.insert(i);
               
    }
    s.insert(0);
    f.insert(0);


    for (int i = 1; i <= n; i++) {
        if (s.find(a[i]) != s.end()) {
            s.erase(a[i]);
        }
    }
    vector<int>z(n+1);
    for (int i= 1; i <= n; i++) {
        
        int x = *s.begin();
        s.insert(a[i]);
        s.erase(x);
        a[i] = x;
        z[i] = x;
        // cout << a[i] << ' ';
    }
    // EL;
    for (int i = 1; i <= n; i++) {
        if (f.find(z[i]) != f.end()) {
            f.erase(z[i]);
        }
    }   
    int num = *f.begin();
    // cout << num << endl;;


    int kk = k %(n+1);
    // cout << kk <<endl;
    if (kk == 1 || k == 1) {
        for (int i = 1; i <= n; i++) cout << z[i] << ' ';
        EL;
    }
    else if (kk == 0) {
        for (int i = 2; i <= n; i++) cout << z[i] << ' ';
        cout << num << endl; 
    }
    else {

        int aa = kk - 2;
        aa = max(0,aa);
        for (int i = aa; i >= 1; i--) {
            cout << z[n-i+1] << ' ';
        }
        cout << num << ' ';
        for (int i = 1; i < n-aa; i++) cout << z[i] << ' ';
        EL;
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
    solve2();
    
    return 0;
}