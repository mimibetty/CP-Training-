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

int a,b,c;
vector<long long>contain;
void build(int vt, int nn, long long num) {
    if (vt >= nn) {
        // cout << num <<endl;
        vector<int>aa;
        long long tmp = num;
        int summ = 0;
        
        while (tmp > 0) {
            aa.pb(tmp % 10);
            summ += (tmp % 10);
            tmp /= 10;
        }   
        if (aa.size() != nn) return;
        for (auto i : aa) {
            int newS = summ - i;
            if (1ll * i * (nn-1) == newS) {
                contain.pb(num);
                return;
            }
        }
        return;
    }
    // cout << vt << ' ' << nn << ' ' << num << endl;
    build(vt + 1, nn, 1ll* num*10 + a);
    build(vt + 1, nn, 1ll* num*10 + b);
    build(vt + 1, nn, 1ll* num*10 + c);
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int q;
    cin >> a >> b >>c >> q;
    for (int i = 2; i <= 9; i++) {
        if (a != 0) build(1,i,a);
        if (b != 0) build(1,i,b);
        if (c != 0) build(1,i,c);
           
    }


    // Sort the vector
    sort(contain.begin(), contain.end());

    // Remove duplicates using unique()
    auto new_end = unique(contain.begin(), contain.end());

    // Resize the vector to its new size
    contain.resize(distance(contain.begin(), new_end));    
    int res = -1;
    int vt = -1;
    for (int i = 1; i <= q; i++) {
        int l,r;
        cin >> l >> r;
        int num1 = upper_bound(contain.begin(), contain.end(),r) - contain.begin() - 1;

        int num2 = upper_bound(contain.begin(), contain.end(),l-1) - contain.begin() - 1;
        int xx = num1 - num2;
        // cout << i << ' ' <<xx << endl;
        if (res < xx) {
            res = xx;
            vt = i;
        }
    }
    cout << vt <<endl;
    // cout <<res <<endl;
    return 0;
}

