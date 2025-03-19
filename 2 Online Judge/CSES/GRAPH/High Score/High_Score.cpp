/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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

const long long INF = 1e18;
long long dp[2501][2501];

void solve() {
    int n, m;
    cin >> n >> m;

    // Khởi tạo ma trận khoảng cách với giá trị âm vô cùng
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dp[i][j] = 0; // Khoảng cách từ một đỉnh đến chính nó là 0
            } else {
                dp[i][j] = -INF; // Khởi tạo khoảng cách là âm vô cùng
            }
        }
    }

    // Đọc vào các cạnh của đồ thị
    for (int i = 1; i <= m; i++) {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        dp[x][y] = max(dp[x][y], z); // Lưu trọng số đường đi từ x đến y
    }

    // Thuật toán Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] > -INF && dp[k][j] > -INF) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    // Kiểm tra chu trình dương
    bool hasPositiveCycle = false;
    for (int i = 1; i <= n; i++) {
        if (dp[i][i] > 0) {
            hasPositiveCycle = true;
            break;
        }
    }

    if (hasPositiveCycle) {
        cout << -1 << endl;
    } else {
        if (dp[1][n] == -INF) {
            cout << -1 << endl; // Không có đường đi từ 1 đến n
        } else {
            cout << dp[1][n] << endl; // Đường đi dài nhất từ 1 đến n
        }
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