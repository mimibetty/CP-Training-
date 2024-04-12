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

int n = 10;
int m = 10;
char a[11][11];
int cnt[1003];
int team[13][13];
bool ok[12][12];
bool live[12][12];
int teamhit[100000];
void solve() {
    int sum = 0, hit = 0, die = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ok[i][j] == 0 && a[i][j] == '#') {
                sum++; 
                ok[i][j] = 1;
                team[i][j] = sum;
                cnt[sum]++;
                            
                int xx = i + 1;
                int yy = j + 1;
                if (xx <= n) {
                    if (a[xx][j] == '#') {
                        while (a[xx][j] == '#') {
                            ok[xx][j] = 1;
                            team[xx][j] = sum;
                            cnt[sum]++;
                            xx++;
                            if (xx > n) break;
                        }
                    }
                }
                if (yy <= n) {
                    if (a[i][yy] == '#') {
                        while (a[i][yy] == '#') {
                            ok[i][yy] = 1;
                            team[i][yy] = sum;
                            cnt[sum]++;
                            yy++;
                            if (yy > n) break;
                        }
                    }
                } 
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << team[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // for (int i = 1; i <= sum; i++) {
    //     cout << i << ' ' << cnt[i] << endl;
    // }
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        string z;
        for (int i = 0; i <= 3; i++) {
            z += s[i];
        }
        // cout << z << ' ';
        if (z == "SHOW") {
            cout << sum << ' ' << hit << ' ' << die << endl;
        }
        else {
            long long numa = 0, numb = 0, vt = 0;
            for (int i = 5; i <= 1e9; i++) {
                numa = numa*10 + (s[i] - 48);
                if (s[i+ 1] == ' ') {
                    vt = i+2;
                    break;
                }
            }
            for (int i = vt; i < s.size(); i++) {
                numb = numb * 10 + (s[i] - 48);
            }
            if (a[numa][numb] == '*') continue;
            if (live[numa][numb] == 0) {
                if (teamhit[team[numa][numb]] == 0) {
                    sum--;
                    hit++;
                    teamhit[team[numa][numb]] = 1;
                }
                live[numa][numb] = 1;
                cnt[team[numa][numb]]--;
                if(cnt[team[numa][numb]] == 0) {
                    die++;
                    hit--;
                }
            }
            // cout << numa << ' ' << numb << endl;
        }
    // cout << sum << endl;

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