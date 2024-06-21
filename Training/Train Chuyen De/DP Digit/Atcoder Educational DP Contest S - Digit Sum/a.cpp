#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double ld;


const int MAXL = 10000;
const int MAXD = 100;
const int MOD = 1e9 + 7;

int dp[MAXL + 1][MAXD];

int add(int i, int j) {
    if ((i += j) >= MOD)
        i -= MOD;
    return i;
}

string s;
int d;

void init(int l, int d) {
    dp[l][0] = 1;
    for (int i = l - 1; i >= 0; --i) {
        for (int j = 0; j < d; ++j) {
            for (int k = 0; k < 10; ++k) {
                dp[i][j] = add(dp[i][j], dp[i + 1][(j + k) % d]);
            }
        }
    }
}

int query(const string& s, int d) {
    int ans = 0, carry = 0;
    for (int i = 0; i < (int) s.length(); ++i) {
        for (int j = 0; j < (s[i] - '0'); ++j) {
            ans = add(ans, dp[i + 1][(carry + j) % d]);
        }
        carry = (carry + (s[i] - '0')) % d;
    }
    if (carry == 0) ans++;
    if (--ans < 0) ans += MOD;
    return ans;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
     
    cin >> s;
    cin >> d;    

   init((int) s.size(), d);
    cout << query(s, d) << '\n';

    return 0;
}