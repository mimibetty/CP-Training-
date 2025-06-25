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
const int MOD = 1e9 + 7;

vector<ll> fact;

void precalculate(int max_n) {
    fact.resize(max_n + 1);
    fact[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void generate_sums(int n, const vector<ll>& trails, map<int, vector<ll>>& sums_by_k) {
    for (int i = 0; i < (1 << n); ++i) {
        ll current_sum = 0;
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_sum += trails[j];
                k++;
            }
        }
        if (k > 0) {
            sums_by_k[k].push_back(current_sum);
        }
    }
}

ll count_valid_routes(int k_e, int k_w, ll x, ll C, ll D,
                    map<int, vector<ll>>& east_sums,
                    map<int, vector<ll>>& west_sums) {

    if (east_sums.find(k_e) == east_sums.end() || west_sums.find(k_w) == west_sums.end()) {
        return 0;
    }

    ll bridges = k_e + k_w - 1;
    if (bridges < 1) return 0;

    ll bridge_len = bridges * x;
    ll min_total_sum = C - bridge_len;
    ll max_total_sum = D - bridge_len;

    if (max_total_sum < 0) return 0;

    vector<ll>& sums_A = east_sums[k_e];
    vector<ll>& sums_B = west_sums[k_w];

    ll count_pairs = 0;
    for (ll sum_a : sums_A) {
        ll target_min = min_total_sum - sum_a;
        ll target_max = max_total_sum - sum_a;

        auto it_low = lower_bound(sums_B.begin(), sums_B.end(), target_min);
        auto it_high = upper_bound(sums_B.begin(), sums_B.end(), target_max);
        
        count_pairs += distance(it_low, it_high);
    }
    
    if (count_pairs == 0) return 0;
    
    ll permutations = (fact[k_e] * fact[k_w]) % MOD;
    ll result = (count_pairs % MOD * permutations) % MOD;
    
    return result;
}

void solve() {
    int n, m;
    ll x, C, D;
    cin >> n >> m >> x >> C >> D;

    vector<ll> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    vector<ll> B(m);
    for (int i = 0; i < m; ++i) cin >> B[i];

    map<int, vector<ll>> east_sums_by_k;
    generate_sums(n, A, east_sums_by_k);

    map<int, vector<ll>> west_sums_by_k;
    generate_sums(m, B, west_sums_by_k);
    
    for (auto it = east_sums_by_k.begin(); it != east_sums_by_k.end(); ++it) {
        sort(it->second.begin(), it->second.end());
    }
    for (auto it = west_sums_by_k.begin(); it != west_sums_by_k.end(); ++it) {
        sort(it->second.begin(), it->second.end());
    }

    ll total_routes = 0;

    // Case: Single trail from Mt. East
    for (ll len : A) {
        if (len >= C && len <= D) {
            total_routes = (total_routes + 1) % MOD;
        }
    }

    // Case: Single trail from Mt. West
    for (ll len : B) {
        if (len >= C && len <= D) {
            total_routes = (total_routes + 1) % MOD;
        }
    }

    // Case: Alternating routes
    for (int k_e = 1; k_e <= n; ++k_e) {
        for (int k_w = 1; k_w <= m; ++k_w) {
            if (abs(k_e - k_w) > 1) continue;

            ll term = count_valid_routes(k_e, k_w, x, C, D, east_sums_by_k, west_sums_by_k);

            if (term == 0) continue;
            
            if (k_e == k_w) {
                total_routes = (total_routes + term * 2) % MOD;
            } else {
                total_routes = (total_routes + term) % MOD;
            }
        }
    }

    cout << total_routes << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    
    precalculate(20);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

