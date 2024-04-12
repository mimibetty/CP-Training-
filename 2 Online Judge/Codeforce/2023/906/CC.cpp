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

void show(deque<int>d) {
    while (d.empty() == 0) {
            cout <<d.front();
            d.pop_front();
        }
    EL;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a = s;
    if (n % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    deque<int>d;
    int x1 = 0, x0= 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            d.pb(0);
            x0++;
        }
        else {
            d.pb(1);
            x1++;  
        } 
    }
    if (x1 != x0) {
        cout << -1 <<endl;
        return;
    }
    
    int l = 0, r = n - 1;
    vector<int>trace;
    vector<int>left, right;
    int cnt = 0;


   
    int x = d.front();
    int y = d.back();
    while (x + y == 1 && d.empty() == 0) {
        cnt++;
        d.pop_front();
        d.pop_back();
        l++; r--;
        if (d.empty() == 0) {
            x = d.front();
            y = d.back();
        }
        else break;
    }

    if (d.empty())  {
        // cout <<s << endl;
        cout << 0 << endl;
        return;
    }


    //     cout << x << ' ' << y << endl;

    int res = 0;
    for (int i = 1; i <= 300; i++) {
        res = i;
        x = d.front();
        y = d.back();
        if (x == 0 && y == 0) {
            d.push_back(0);
            d.push_back(1);
            right.pb(cnt);
            trace.pb(n + (right.size()-1) *2 - cnt);
            // cout << "R " << n + (right.size()-1) *2 - cnt << endl;
        }
        else if (x == 1 && y == 1) {
            d.push_front(1);
            d.push_front(0);
            left.pb(cnt);
            trace.pb(cnt);
            // cout << "L " << cnt << endl;
        }
     


        x = d.front();
        y = d.back();
        while (x + y == 1 && d.empty() == 0) {
            d.pop_front();
            d.pop_back();
            cnt++;
            if (d.empty() == 0) {
                x = d.front();
                y = d.back();
            }
            else break;
        }   
        
        // cout << i << ' ';
        // show(d);

        if (d.empty()) break;
    }
    // cout <<"TRACE  " << endl;
    // cout <<"LLL" <<endl;
    // for (auto i : left) cout << i << ' ';
    // EL;
    // cout <<"RRR" << endl;
    // for (auto i :right) cout << i << ' ';
    // EL;
    if (d.empty() == 1)  {
        cout << res << endl;
        for (auto i : trace) cout << i << ' ';
        EL;
    }
    else {
        // while (d.empty() == 0) {
        //     cout <<d.front();
        //     d.pop_front();
        // }
        // cout <<"???" << endl;
        cout << -1 << endl;    
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
    cin >> t;

    while (t--)    
    solve();
    
    return 0;
}