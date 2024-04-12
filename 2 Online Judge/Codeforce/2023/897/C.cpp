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

int a[100005];
void solve() {
    int n;
    cin >> n;
    map<int,int>d;
    set<int>s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]] = 1;
        s.insert(a[i]);
    }
    if (d[0] == 0) {
        cout << 0 << endl;
        int x;
        cin >> x;
        cout << endl;
        return;
    }

    int mexx = -1;
    for (int i = 0; i <= n + 2; i++) {
        if (d[i] == 0) {
            mexx = i;
            break;
        }
    }

    cout << mexx << endl;
    d[mexx] = 1;
    for (int i = 1; i <= n; i++) {
        int x,y;
        // s.insert(vt);
        cin >> y;
        if (y == -2) {
            while(true) {
                cout<<"???" << endl;
            }
        }

        if (y == -1) {
            //cout <<endl<< "END"<< endl;

            cout << endl;
            return;
        }
        else {
            d[y] = 0;
            cout << y << endl;
        }
    }
}

int main() {


    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    solve();

    return 0;
}
