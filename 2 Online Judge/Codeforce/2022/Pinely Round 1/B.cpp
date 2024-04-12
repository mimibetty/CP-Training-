#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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


typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;

// Ex;
// s={2,5,6,10}
// *s.find_by_order(2)=6;
// s.order_of_key(x) == lower_bound(x)-s.begin();
void solve() {
  
    int n;
    cin >> n;
    IndexTree s;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        s.insert({i,a});
    }
    // auto it = s.find_by_order(2);
    // cout << (*it).se; 
    // cout <<  s.find_by_order(2);
    // s.erase(2);
    int cnt = 0;
    while (s.empty() == 0) {
        int num = s.size();
        // cout << num << endl;

        if (num == 1) {
            cnt++;
            break;
        }
        bool ok = 1;
        for (int i = 0; i < num; i++) {
            int l,r;
            l = i-1;
            r = i+1;
            if (i == 0) {
                l = num-1;
            }
            if (i == num - 1) r = 0;
            auto it1 = s.find_by_order(l);
            auto it2 = s.find_by_order(r);
            auto it = s.find_by_order(i);

            if ((*it1).se != (*it2).se) {
                s.erase(it);
                ok = 0;
                cnt++;
                i--;
                num--;
                cout <<"ESSSS" << i + 1 << endl;
                        for (auto i : s) cout << i.se << ' ';
                        cout << endl;
            }
        }
        if (ok == 1) {
            cnt++;
            s.erase(s.find_by_order(0));
            s.erase(s.find_by_order(1));
        }
    }
    cout << cnt << endl;
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
    t = 1;
    while (t--) solve();
    return 0;
}