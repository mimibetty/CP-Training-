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

void doo(priority_queue<int, vector<int>, greater<int>> p){
    while (p.empty() == 0) {
        cout << p.top() << ' ' ;
        p.pop();
    } 
    cout << endl;
}



struct RMQ {
    vector<int> a;
    vector<vector<int>> sparseMax, sparseMin;
    int n;
    RMQ(vector<int> arr) {
        a = arr;
        n = arr.size();
        sparseMax.resize(n);
        sparseMin.resize(n);
        for (int i = 0; i < n; i++) {
            sparseMax[i].resize(__lg(n) + 1);
            sparseMax[i][0] = a[i]; // {a[i], i}

            sparseMin[i].resize(__lg(n) + 1);
            sparseMin[i][0] = a[i];
        }

        for (int len = 1; len < __lg(n) + 1; len++) {
            for (int i = 0; i + (1 << (len - 1)) < n; i++) {
                sparseMax[i][len] = max(sparseMax[i][len - 1], sparseMax[(1 << (len - 1)) + i][len - 1]);
                sparseMin[i][len] = min(sparseMin[i][len - 1], sparseMin[(1 << (len - 1)) + i][len - 1]);
            }
        }
    }

    int queryMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
    }

    int queryMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<int>a(n + 3);

    for (int i = 1; i <= n; i++) {
        a[i] = int(s[i] - 48);
    }

    RMQ rmq(a);
    vector<int>res;
    priority_queue<int, vector<int>, greater<int>> p;
    // p.push(2);
    // p.push(2);
    // while (p.empty() == 0) {
    //     cout << p.top();
    //     p.pop();
    // }

    for (int i = 1; i <= n; i++) {
        // cout << "STT  " << i << endl;
        if (p.empty() == 1) {
            int ff = rmq.queryMin(i,n);
            if (a[i] == min(ff,a[i]) ) {
                res.pb(a[i]);
                // cout << "1   " << endl;
            }
            else {
                // cout << "2   " << endl;
                p.push(min(a[i] + 1,9));
            } 
        }
        else {
            int dd = p.top();
            int ff = rmq.queryMin(i,n);

            if (a[i] == min(ff, a[i]) ) {
                // cout<<"3    " << endl;

                bool check = p.empty();
                while(check == 0) {
                    int z = p.top();
                    if (a[i] >= z) {
                        res.pb(z);
                        p.pop();
                    }
                    else {
                        break;
                    }
                    // cout << "zzz  " << z << endl;
                    check = p.empty();
                }
                res.pb(a[i]);
                // if (i == 4 || i == 5) {
                //     for (auto i : res )cout << i;
                //         cout <<endl;
                //     doo(p);
                //     cout << endl;
                // }
                // for (auto i : p) cout << i << ' ';
                    // cout <<endl;
            }
            else {
                // cout << "4   " << endl;

                p.push(min(a[i] + 1,9));
                bool fx = p.empty();
                while (p.top() <= ff) {
                    cout << "zzz   " << p.top() << endl; 
                    res.pb(p.top());
                    p.pop();

                    fx = p.empty();
                    if(fx == 1) break;
                }
                // if (i == 3) {
                    // for (auto i : res )cout << i;
                    //     cout <<endl;
                    // doo(p);
                    // cout << endl;
                // }
            }
        }
            // else {
            //     p.push(min(a[i] + 1,9));
            //     cout << "5    ";
            // }   
        // }
        // cout << endl;
    }
    while(p.empty() == 0) {
        int dd = p.top();
        res.pb(dd);
        p.pop();
    }
    for (auto i : res ) cout << i;
    cout << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}