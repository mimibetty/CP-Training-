#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

char a[4][4];
bool checkdoc(int x, char d) {
    for (int i = 1; i <= 3; i++) {
        if (a[x][i] != d) return 0;
    }
    return 1;
} 

bool checkcheo1(char d) {
    for (int i = 1; i <= 3; i++) {
        if (a[i][i] != d) return 0;
    }
    return 1;
} 

bool checkcheo2(char d) {
    for (int i = 1; i <= 3; i++) {
        if (a[i][3-i+1] != d) return 0;
    }
    return 1;
} 


bool checkngang(int x, char d) {
    for (int i = 1; i <= 3; i++) {
        if (a[i][x] != d) return 0;
    }
    return 1;
} 

void solve() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) cin >> a[i][j];
    }

    bool win1 = 0, win2 = 0;
    int cntx = 0, cnt0 = 0;
    bool doc = 0;
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] == 'X') cntx++;
            if (a[i][j] == '0') cnt0++;
            if (a[i][j] == '.') doc = 1;
        }
    }
    
    if (cntx - cnt0 < 0 || cntx - cnt0 >= 2) {
        cout <<"illegal" << endl;
        return;
    }

 
    if (checkcheo1('X') || checkcheo2('X')) {
        win1 = 1;
    }
    if (checkcheo1('0') || checkcheo2('0')) {
        win2 = 1;
    }

   for (int i = 1; i <= 3; i++) {
        if (checkdoc(i,'X') || checkngang(i,'X')) {
            win1 = 1;
        }     
        if (checkdoc(i,'0') || checkngang(i,'0')) {
            win2 = 1;
        }     
    }

    if (win1 == 1 && win2 == 1) {
        cout << "illegal" << endl;
        return;
    }

    if(win1 == 1 && cntx != cnt0 + 1) {
        cout << "illegal" << endl;
        return;   
    }

    if(win2 == 1 && cntx != cnt0) {
        cout << "illegal" << endl;
        return;   
    }

    if (win1 == 1 || win2 == 1) {
        if (win1 == 1) {
            cout << "the first player won" << endl;
            return;      
        }
        else {
            cout << "the second player won" << endl;
            return;   
        }
    }

    if (doc == 0) {
        cout << "draw" << endl;
        return;
    }

    if (cntx == cnt0) cout << "first" << endl;
    else cout << "second" << endl;
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
    while (t--) {
        solve();
    }
    return 0;
}