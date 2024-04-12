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

// void solve() {
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     int res = 0;
//     for (int i = 1; i <= n; i++) {
//         map<pair<char,char>,bool>d;
//         for (int j = 1; j <= i; j++) {
//             for (int k = j ; k <= i; k++) {
//                 d[{s[i], s[j]}] = 1;
//             }
//         }
//         res += d.size();
//     }
//     cout << res <<endl;
// }

// void solve() {
//     int n;
//     std::cin >> n;
//     std::string s;
//     std::cin >> s;
//     s = ' ' + s; // Prefixing the string with a space for 1-based indexing.
//     int res = 0;

//     EL;
//     for (int i = 1; i <= n; i++) {
//         std::map<std::pair<char, char>, bool> d;
//         for (int j = 1; j <= i; j++) {
//             // Directly set the value in the map without the third loop.
//             d[{s[j], s[i]}] = true;
//         }
//         res += d.size(); // Add the number of unique pairs to the result.
//         cout << d.size() << ' ';
//     }
//     EL;
//     std::cout << res << std::endl;
// }

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    long long res = 0;
    int x = 0;
    map<char, bool>d;
    for (int i = 1; i <= n;i++) {
       d[s[i]] = 1;
       res += d.size(); 
    } 
    cout << res <<endl;
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
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}