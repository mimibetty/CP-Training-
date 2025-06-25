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

void solve() {
    int n,m;
    cin >> n >> m;
    multiset<int>a;
    multiset<int>b;

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        a.insert(c);
    }
    for (int i = 1; i <= m; i++) {
        int c;
        cin >> c;
        b.insert(c);
    }

    while (1) {
        // for (auto i : a) cout << i << ' ';
        // cout << endl;
        // for (auto i : b) cout << i << ' ';
        // cout << endl << endl;

        if (b.empty() || a.empty()) break; // Ensure the loop exits if b is empty
        auto it = b.rbegin(); // max b
        if (*it < *a.begin()) break; // Ensure the condition is valid
        if (a.find(*it) != a.end()) { // Check if the element is in a
            a.erase(a.find(*it));
            b.erase(prev(b.end()));
            continue;
        }
        if (a.size() < b.size()) break; // Ensure the condition is valid
        int x = *it; // Dereference iterator to get the value
        b.erase(prev(b.end())); // Correctly erase the element from multiset

        vector<int> tmp;
        if (x % 2 == 0) {
            tmp.push_back(x / 2);
            tmp.push_back(x / 2);
        } else {
            tmp.push_back(x / 2);
            tmp.push_back(x / 2 + 1);
        }

        for (auto i : tmp) {
            if (a.find(i) != a.end()) {
                a.erase(a.find(i));
            } else {
                b.insert(i);
            }
        }
    }

    if (a.size() != 0 || b.size() != 0) cout << "NO\n";
    else cout << "YES\n";
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