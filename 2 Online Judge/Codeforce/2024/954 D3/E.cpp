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


const int MAXN = 200005;
int a[MAXN];
int n, k;

long long minimalPairSum(vector<int>& a) {
    sort(a.begin(), a.end());  // Sắp xếp mảng theo thứ tự tăng dần
    long long res = 0;
    int n = a.size();

    vector<bool> used(n, false);  // Mảng đánh dấu các phần tử đã được sử dụng

    // Duyệt qua mảng và chọn các cặp phần tử tối ưu
    for (int i = 0; i < n - 1; ++i) {
        if (!used[i]) {
            long long minDiff = LLONG_MAX;
            int best_j = -1;
            for (int j = i + 1; j < n; ++j) {
                if (!used[j] && abs(a[i] - a[j]) < minDiff) {
                    minDiff = abs(a[i] - a[j]);
                    best_j = j;
                }
            }
            if (best_j != -1) {
                res += minDiff / k;
                used[i] = used[best_j] = true;  // Đánh dấu các phần tử đã được sử dụng
            }
        }
    }

    return res;
}

void solve() {
    cin >> n >> k;
    long long res = 0;

    // Nhập các phần tử của mảng
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    unordered_map<int, vector<int>> modGroups;

    // Duyệt qua tất cả các phần tử của mảng để phân nhóm theo phần dư khi chia k
    for (int i = 1; i <= n; ++i) {
        int modd = a[i] % k;
        modGroups[modd].push_back(a[i]);
    }

    // In kết quả và tính toán res
    int num_groupOdd = 0;
    for (const auto &group : modGroups) {
        vector<int> elems = group.second;
        sort(elems.begin(), elems.end());

        num_groupOdd += (elems.size() % 2);

        if ((elems.size() % 2) == 0) {
            for (size_t i = 0; i < elems.size(); i += 2) {
                res += abs(elems[i] - elems[i + 1]) / k;
            }
        } else {
            long long res1 = 0;
            long long res2 = 0;

            // // Tính res1 cho các cặp (0,1), (2,3), ...
            // for (size_t i = 0; i + 1 < elems.size(); i += 2) {
            //     res1 += abs(elems[i] - elems[i + 1]) / k;
            // }

            // // Tính res2 cho các cặp (1,2), (3,4), ...
            // for (size_t i = 1; i + 1 < elems.size(); i += 2) {
            //     res2 += abs(elems[i] - elems[i + 1]) / k;
            // }
            // res += min(res1, res2);
            cout << "sss  " << minimalPairSum(elems) << endl;
            res += minimalPairSum(elems);
        }

        // In các phần tử trong nhóm
        for (int num : elems) {
            cout << num << " ";
        }
        cout << endl;
    }

    // cout << "res: ";
    if (num_groupOdd > 1) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    // cout << endl << endl;
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