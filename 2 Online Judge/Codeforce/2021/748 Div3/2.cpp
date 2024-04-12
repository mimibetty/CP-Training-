#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;

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
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
const int limx = 1e6;

string a[10];
int check[10][10];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    a[1] = "25";
    a[2] = "50";
    a[3] = "75";
    a[4] = "00";
    while(t--) {

        for (int i = 1; i <= 7; i++) {
            for (int j = 1; j <= 7; j++) check[i][j] = -1;
        }

        string s;
        cin >> s;
        int n = s.size();

        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; j <= 4; j++) {
                if (check[j][2] == -1) {
                    if (s[i] == a[j][1]) {
                        check[j][2] = i;
                        // cout << a[j] << ' '<< i << endl;
                        continue;  
                    }  
                }
                if (check[j][2] != -1 && check[j][1] == -1) {
                    if (s[i] == a[j][0]) {
                        check[j][1] = i; 
                        // cout << a[j] << ' '<< i << endl; 
                    }     
                }
            }
        }
        // cout << check[4][0] << ' '<< check[4][1] << endl;
        // cout << a[1][1];
        int res = 1e9;
        for (int i = 1; i <= 4; i++) {
            int cnt = 0;

            if (check[i][1] != -1 && check[i][2] != -1) {
                cnt = (n - check[i][2] - 1) + (check[i][2] - check[i][1] -1);
                res = min(res,cnt);  
            }  
        }
        cout << res << endl;
    }

    return 0;
}