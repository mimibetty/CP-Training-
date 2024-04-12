#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
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
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

vector<int> zAlgo(string s) {
    int n = s.length();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i <= n - 1; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }
    z[0] = n;
    return z;
}
 
string convert(string s) {
    string rr;
    int n = s.size();
    for (int i = 0; i < n; i++) {

        int num;
        if (s[i] <= '9') num = int(s[i] - '0'); 
        else {
            num = 10 + int(s[i] - 'A');
        }

        
        string ff;
        int stt = 4;
        while (stt > 0) {
            if (num % 2 == 0) {
                ff += '0';
            }
            else ff += '1';
            num/=2;
            stt --;
        } 
        reverse(ff.begin(), ff.end());
        rr += ff;
        ff.clear();

    } 
    
    return rr;
} 

int main() {
 if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
  

    string a,b,c;
    int res = 0;
    vector<int> d;
    cin >> b >> a;


    b = convert(b);
    a = convert(a);


    c = b + "$" + a;
    d = zAlgo(c);
    for (int i = b.size() + 1; i < c.size(); i++) {
        if (d[i] == b.size()) res++;
    }  
    cout << res;
  
    return 0;
}