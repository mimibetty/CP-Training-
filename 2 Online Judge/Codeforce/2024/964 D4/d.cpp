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

bool canMatchAndTransform(string &a, const string &b) {
    int n = a.size();
    int m = b.size();

    int j = 0; // Chỉ số cho chuỗi b

    // Duyệt qua chuỗi a
    for (int i = 0; i < n && j < m; ++i) {
        if (a[i] == b[j] || a[i] == '?') {
            if (a[i] == '?') {
                a[i] = b[j]; // Thay thế '?' bằng ký tự tương ứng trong b
            }
            j++; // Chuyển sang ký tự tiếp theo của b
        }
    }

    // Kiểm tra xem toàn bộ b có phải là subsequence của a hay không
    return j == m;
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
        string a;
        string b ;
        cin >> a >> b;

        if (canMatchAndTransform(a, b)) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == '?') a[i] = 'a';
            }
            cout << "YES" << endl;
            cout << a << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}