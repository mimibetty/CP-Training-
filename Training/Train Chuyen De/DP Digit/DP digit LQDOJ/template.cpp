#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
 
using ll = long long;
 
struct Stall {
    int pos;
    ll t; // purchase time
};
 
int main(){
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<ll> T_time(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for (int i = 0; i < N; i++){
        cin >> T_time[i];
    }
    
    // Group stalls by product
    vector<vector<Stall>> productStalls(M+1);
    // Note: stalls are numbered from 1 to N, so we add 1 to index.
    for (int i = 0; i < N; i++){
        int prod = A[i];
        productStalls[prod].push_back({i+1, T_time[i]});
    }
    
    // Sort each product's stalls by position
    for (int prod = 1; prod <= M; prod++){
        sort(productStalls[prod].begin(), productStalls[prod].end(), [](const Stall &s1, const Stall &s2){
            return s1.pos < s2.pos;
        });
    }
    
    // For product 1, the dp cost is just the purchase time of that stall.
    int sz = productStalls[1].size();
    vector<ll> prev_dp(sz), prev_pos(sz);
    for (int i = 0; i < sz; i++){
        prev_dp[i] = productStalls[1][i].t;
        prev_pos[i] = productStalls[1][i].pos;
    }
    
    // Process products 2 to M.
    for (int prod = 2; prod <= M; prod++){
        const vector<Stall> &curStalls = productStalls[prod];
        int curSize = curStalls.size();
        vector<ll> cur_dp(curSize, numeric_limits<ll>::max());
        vector<int> cur_pos(curSize);
        for (int i = 0; i < curSize; i++){
            cur_pos[i] = curStalls[i].pos;
        }
        
        // Prepare arrays for previous product:
        int prevSize = prev_dp.size();
        vector<ll> f(prevSize), g(prevSize);
        for (int i = 0; i < prevSize; i++){
            // f[i] = prev_dp[i] - prev_pos[i]
            // g[i] = prev_dp[i] + prev_pos[i]
            f[i] = prev_dp[i] - prev_pos[i];
            g[i] = prev_dp[i] + prev_pos[i];
        }
        
        // Left-to-right pass:
        ll best = numeric_limits<ll>::max();
        int jprev = 0;
        // prev_pos is sorted in increasing order. For each candidate stall in current product,
        // we increase jprev until prev_positions[jprev] <= cur_pos.
        for (int i = 0; i < curSize; i++){
            int x = cur_pos[i];
            while(jprev < prevSize && prev_pos[jprev] <= x){
                best = min(best, f[jprev]);
                jprev++;
            }
            if(best != numeric_limits<ll>::max()){
                cur_dp[i] = min(cur_dp[i], best + x);
            }
        }
        
        // Right-to-left pass:
        best = numeric_limits<ll>::max();
        int jprev2 = prevSize - 1;
        for (int i = curSize - 1; i >= 0; i--){
            int x = cur_pos[i];
            while(jprev2 >= 0 && prev_pos[jprev2] >= x){
                best = min(best, g[jprev2]);
                jprev2--;
            }
            if(best != numeric_limits<ll>::max()){
                cur_dp[i] = min(cur_dp[i], best - x);
            }
        }
        
        // Add the purchase time cost for current stall.
        for (int i = 0; i < curSize; i++){
            cur_dp[i] += curStalls[i].t;
        }
        
        // Prepare for the next round
        prev_dp = cur_dp;
        prev_pos = vector<int>(cur_pos.begin(), cur_pos.end());
    }
    
    // The answer is the minimum dp cost for product M.
    ll ans = numeric_limits<ll>::max();
    for (ll cost : prev_dp)
        ans = min(ans, cost);
    cout << ans << "\n";
    
    return 0;
}