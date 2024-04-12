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
const int lennn = 300* 300;
int preDP[lennn + 5];
void Input()
{
    cin >> n >> k >> p;
}

void Solve()
{
    //for(int i = 0; i <= n; i++) F[i][0] = 1;
    F[0][0] = 1;
    for (int i = 1; i <= lennn; i++) {
        if (i <= k) F[1][i] = 1;
        preDP[i] = F[1][i] + preDP[i-1];
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = k * n; j > 0; j--) {
    //         for(int t = 1; t <= k; t++) {
    //             if(j - t >= 0) F[i][j] = (F[i][j] + F[i - 1][j - t]) % MOD;
    //             F[i][j] = preDP[j-1] + preDP[j-2] + preDP[j-k];
    //         }
    //     }
    // }
    // for (int i = 1; i <= n*k; i++) {
    //     cout << preDP[i] << ' ';
    // }
    // cout << endl;
    for(int i = 2; i <= n; i++) {
        for(int j = k * n; j > 0; j--) {
            F[i][j] = preDP[j-1] - preDP[max(1ll*0,j-k-1)];
            F[i][j] %= MOD;
            F[i][j] = (F[i][j] + MOD) % MOD;

        }
        for (int z = 1; z <= lennn; z++) {
            preDP[z] = preDP[z-1] + F[i][z];
            preDP[z] %= MOD;
        }
    }

   // for(int i = 1; i <= n; i++) {
   //     for(int j = 1; j <= n * k; j++) {
   //         cout<< F[i][j] << ' ';
   //     }
   //     cout << endl;
   // }
    ll ans = 0;
    for(int i = p + 1; i <= k * n; i++) {
        ans = (ans + F[n][i]) % MOD;
        //cout << F[n][i] << ' ';
    }
    cout << ans;
}

int main()
{
     if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        Input();
        Solve();
    }
    return 0;
}
