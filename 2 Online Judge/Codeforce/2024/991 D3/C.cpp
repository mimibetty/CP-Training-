/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define bit(n, i) ((n >> i) & 1)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(), (v).end()

#define cntBit __builtin_popcount
#define fi first
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long double PI = acos(-1);

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r) {
    uniform_int_distribution<ll> rnd(l, r);
    return rnd(gen);
}

int d[12];
vector<int> a2 = {0, 2, 4, 6, 8, 1, 3, 5, 7};
vector<int> a6 = {0, 6, 3};

void solve() {
    // Reset the digit frequency array
    for (int i = 0; i <= 9; i++) {
        d[i] = 0;
    }

    string s;
    cin >> s;

    ll ss = 0;
    for (char c : s) {
        ss += c - '0';
        d[c - '0']++;
    }

    ss %= 9;

    int s2 = a2.size();
    int s3 = a6.size();
    // cout <<s2 << ' ' << s3 << endl;
    for (int i = 0; i < min(s2,d[2]+1); i++) {  // Loop through all elements in a2
        for (int j = 0; j < min(s3,d[3]+1); j++) {  // Loop through all elements in a6
            if ((ss + a2[i] + a6[j]) % 9 == 0) {  // Check divisibility by 9
                cout << "YES" << endl;
                return;
            }
        }
    }

    // If no valid combination is found
    cout << "NO" << endl;
}

int main() {
    // Check for input file and redirect input/output
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    }

    // Fast IO
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    cin >> t;

    // Solve test cases
    while (t--) {
        solve();
    }

    return 0;
}