#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                           //Created by CUBERLONG
using namespace std;
#define int long long

int n, a[100];
const int INF = 0x3f3f3f3f3f3f3f3f;

bool minimize(int &a, int b) {
    if (b < a) return a = b, 1;
    else return 0;
}

// SUB 1 ########################################################################
int sum, ans;
void lui(int x, int n1, int n2) {
    if (x == n+1) {
        if (n1 == n2)
            ans = min(ans, sum-n1-n2);
        return;
    }
    lui(x+1, n1, n2);
    lui(x+1, n1+a[x], n2);
    lui(x+1, n1, n2+a[x]);
}
int sub1() {
    if (n == 1) return a[1];
    ans = 1e18;
    lui(1, 0, 0);
    return (sum-ans)/2;
}

// SUB 2 ########################################################################
#define II pair<int,int>
#define fi first
#define se second
II p[1000005];
int cnt;
int res;
void back_track(int pos, int en, int x = 0, int y = 0, int sum = 0) {
    if (pos == en) {
        if (en != n + 1) {
            p[++cnt] = {x-y, sum-x-y}; // lưu hiệu x1-y1 và tiền bán đi
        } else {
            int u = lower_bound(p + 1, p + 1 + cnt, make_pair(y-x, -INF)) - p;
            if (u == cnt + 1 || p[u].fi != y-x) return; // không tồn tại
            res = min(res, p[u].se + sum - x - y); 
        }
        return;
    }
    back_track(pos+1, en, x+a[pos], y, sum+a[pos]); // đưa cho Alice
    back_track(pos+1, en, x, y+a[pos], sum+a[pos]); // đưa cho Bob
    back_track(pos+1, en, x, y, sum+a[pos]); // bán đi
}
int sub2() {
    cnt = 0; res = INF;
    int m = (1 + n) / 2;
    back_track(1, m + 1); sort(p + 1, p + 1 + cnt);
    back_track(m + 1, n + 1); // tính toán kết quả
    return (sum-res)/2;
}

// SUB 3 ########################################################################
int f[2][2500][2500];
int sub3() {
    int s = 0;
    for (int i = 1; i <= n; ++ i) s += a[i];
    s /= 2;
    memset(f[0], 0x3f, sizeof f[0]);
    f[0][0][0] = 0;
    for (int i = 1; i <= n; ++ i) {
        int cur = i&1;
        int pre = !cur;
        for (int j = 0; j <= s; ++ j)
            for (int h = 0; h <= s; ++ h) {
                f[cur][j][h] = INF;
                if (j >= a[i])
                    minimize(f[cur][j][h], f[pre][j-a[i]][h]);
                if (h >= a[i])
                    minimize(f[cur][j][h], f[pre][j][h-a[i]]);
                minimize(f[cur][j][h], f[pre][j][h] + a[i]);
            }
    }
    int res = INF;
    for (int i = 0; i <= s; ++ i)
        minimize(res, f[n&1][i][i]);
    return (sum-res)/2;
}

// SUB 4 ########################################################################
const int base = 5e4;
int dp[2][100005];
int sub4() {
    int s = 0;
    for (int i = 1; i <= n; ++ i) s += a[i];
    s /= 2;
    memset(dp[0], 0x3f, sizeof dp[0]);
    dp[0][base] = 0;
    for (int i = 1; i <= n; ++ i) {
        int cur = i&1;
        int pre = !cur;
        for (int j = -s; j <= s; ++ j) {
            dp[cur][j+base] = INF;
            if (j + a[i] <= s)
                minimize(dp[cur][j+base], dp[pre][j+a[i]+base]);
            if (j - a[i] >= -s)
                minimize(dp[cur][j+base], dp[pre][j-a[i]+base]);
            minimize(dp[cur][j+base], dp[pre][j+base] + a[i]);
        }
    }
    return (sum - dp[n&1][base])/2;
}

// MAIN ########################################################################
signed main() {
    // string LINK = "E:";
    // ifstream filenum((LINK+"/VScode/C++/Online/filenum.txt").c_str());
    // string finp = "", fout = "";
    // filenum >> finp >> fout;
    // ifstream cin(finp.c_str());
    // ofstream cout(fout.c_str());
	    // freopen("input.txt", "r", stdin);

    while (cin >> n) {
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (n <= 12) cout << sub1();
        else if (n <= 24) cout << sub2();
        else if (n <= 48) cout << sub3();
        else cout << sub4();
        cout << '\n';
    }

    // cin.close();
    // cout.close();
    return 0;
}