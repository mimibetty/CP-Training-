#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;

#define pb push_back
#define X first
#define Y second
#define endl "\n"

const ll LINF = 1E18;
const int INF = 1E9;
const int MOD = 1E9 + 7;
const double pi = acos(-1);

const int N = 305;

ll n, F[N][N * N], k, p;

void Input()
{
    cin >> n >> k >> p;
}

void Solve()
{
    //for(int i = 0; i <= n; i++) F[i][0] = 1;
    F[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = k * n; j > 0; j--) {
            for(int t = 1; t <= k; t++) {
                if(j - t >= 0) F[i][j] = (F[i][j] + F[i - 1][j - t]) % MOD;
            }
        }
    }
   for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= n * k; j++) {
           cout << F[i][j] << ' ';
       }
       cout << endl;
   }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n*k; j++) {
    //         cout <<  F[i][j] << ' ' << endl;
    //     }
    // }
    ll ans = 0;
    for(int i = p + 1; i <= k * n; i++) {
        ans = (ans + F[n][i]) % MOD;
        //cout << F[n][i] << ' ';
    }
    cout << ans;
}

#define task "test"
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while (t--) {
        Input();
        Solve();
    }
    return 0;
}
