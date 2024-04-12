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
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};  // 
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
const int limx = 1e6;
 
ll res = 0;
bool d[10][10];
 
bool check(int i, int j) {
    if (i > 7 || i < 1) return 0;
    if (j > 7 || j < 1) return 0;
    if (d[i][j] == 1) return 0;
    return 1;
 
}
vector<string>str;
void backtrack(int vt, int i, int j, string &s) {
    int x,y;
    
    if (d[i][j] == 1)
    if(i == 7 && j == 7) {
        if (vt == s.size()) {
            res++;
            return;
        }
        else return;
    }

    if (s[vt] == '?') {
        for (int q = 0; q < 4; q++) {
            x = i + dx[q];
            y = j + dy[q];
            if (check(x,y) == 0) continue;
            str += s[vt];
            d[x][y] = 1;
            // cout << vt + 1 << ' ' << x << ' ' << y << ' ' << res << endl;
            backtrack(vt + 1, x , y , s);
            d[x][y] = 0;
        }
    } 
    else {
        if (s[vt] == 'R') {
             x = i ;
             y = j + 1;    
        }   
        if (s[vt] == 'L') {
             x = i ;
             y = j - 1;    
        }   
        if (s[vt] == 'D') {
             x = i + 1;
             y = j ;    
        }   
        if (s[vt] == 'U') {
             x = i - 1;
             y = j ;    
        }
        str += s[vt];
        if (check(x,y) == 0) return;
        d[x][y] = 1;
        // cout << vt + 1 << ' ' << x << ' ' << y << ' ' << res<< endl;
        backtrack(vt+1, x , y , s);
        d[x][y] = 0;
    }
 
}
 
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s;
    cin >> s;
 
    if (s[0] == '?') {
        d[1][1] = 1;
        backtrack(1, 2, 1, s);
        backtrack(1, 1, 2, s);    
    }
    else  backtrack(0, 1, 1, s);
    cout << res;
 
    return 0;
}