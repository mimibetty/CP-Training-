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

char a[4][4];
void solve() {
    for (int i = 1;i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }
    int w1 = 0, w2 = 0, w3 = 0;
    for (int i = 1; i <= 3; i++) {
        bool ok = 1;
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] != '+') {
                ok = 0;
                break;
            } 
        }
        if (ok) w1 = 1;
    }
    for (int i = 1; i <= 3; i++) {
        bool ok = 1;
        for (int j = 1; j <= 3; j++) {
            if (a[j][i] != '+') {
                ok = 0;
                break;
            } 
        }
        if (ok) w1 = 1;
    }
    int ok1 = 1, ok11 = 1;
    for (int i = 1;i <= 3; i++) {
        if (a[i][i] != '+') {
            ok1 = 0;
        }
        if (a[i][3-i+1] != '+') {
            ok11 = 0;
        }
    }
    w1 |= ok1;
    w1 |= ok11;







    for (int i = 1; i <= 3; i++) {
        bool ok = 1;
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] != 'X') {
                ok = 0;
                break;
            } 
        }
        if (ok) w2 = 1;
    }
    for (int i = 1; i <= 3; i++) {
        bool ok = 1;
        for (int j = 1; j <= 3; j++) {
            if (a[j][i] != 'X') {
                ok = 0;
                break;
            } 
        }
        if (ok) w2 = 1;
    }
    ok1 = 1, ok11 = 1;
    for (int i = 1;i <= 3; i++) {
        if (a[i][i] != 'X') {
            ok1 = 0;
        }
        if (a[i][3-i+1] != 'X') {
            ok11 = 0;
        }
    }
    w2 |= ok1;
    w2 |= ok11;











    for (int i = 1; i <= 3; i++) {
        bool ok = 1;
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] != 'O') {
                ok = 0;
                break;
            } 
        }
        if (ok) w3 = 1;
    }
    for (int i = 1; i <= 3; i++) {
        bool ok = 1;
        for (int j = 1; j <= 3; j++) {
            if (a[j][i] != 'O') {
                ok = 0;
                break;
            } 
        }
        if (ok) w3 = 1;
    }
    ok1 = 1, ok11 = 1;
    for (int i = 1;i <= 3; i++) {
        if (a[i][i] != 'O') {
            ok1 = 0;
        }
        if (a[i][3-i+1] != 'O') {
            ok11 = 0;
        }
    }
    w3 |= ok1;
    w3 |= ok11;


    if (w1 == 1) {
        cout << "+" << endl;
    } 
    else if (w2 == 1) {
        cout << "X" << endl;
    }
    else if (w3 == 1) {
        cout << "O" << endl;
    }
    else cout << "DRAW" << endl;
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