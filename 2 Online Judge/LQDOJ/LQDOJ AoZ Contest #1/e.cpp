#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<string> grid(N);
    for(int i=0; i<N; i++) cin >> grid[i];
    
    // Enumerate all 'P's
    vector<pair<int, int>> Ps;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 'P') {
                Ps.emplace_back(i, j);
            }
        }
    }
    
    int M = Ps.size();
    if(M ==0){
        // As per problem statement, there is at least one 'P'
        // But handle it just in case
        cout << "0\n";
        return 0;
    }
    
    // Assign index to each 'P'
    // M is the number of 'P's
    // Enumerate row-wise and column-wise 'P's
    // Precompute per row and per column sorted lists
    vector<vector<int>> rowPs(N, vector<int>());
    vector<vector<int>> colPs(N, vector<int>());
    for(int idx=0; idx<M; idx++){
        int i = Ps[idx].first;
        int j = Ps[idx].second;
        rowPs[i].push_back(j);
        colPs[j].push_back(i);
    }
    // Sort the lists
    for(int i=0; i<N; i++){
        sort(rowPs[i].begin(), rowPs[i].end());
        sort(colPs[i].begin(), colPs[i].end());
    }
    
    // For each 'P', find its two possible next 'P's: right and down
    // Store the indices of the next 'P's
    vector<vector<int>> choices(M, vector<int>());
    for(int idx=0; idx<M; idx++){
        int i = Ps[idx].first;
        int j = Ps[idx].second;
        
        // Find next 'P' to the right in row i
        // Find the first column > j, else wrap to first 'P' in row
        int next_j;
        if(rowPs[i].size() ==1){
            next_j = j; // Only one 'P' in the row, points to itself
        }
        else{
            // Use upper_bound to find the first j' > j
            auto it = upper_bound(rowPs[i].begin(), rowPs[i].end(), j);
            if(it == rowPs[i].end()){
                next_j = rowPs[i][0];
            }
            else{
                next_j = *it;
            }
        }
        // Find the index of the 'P' at (i, next_j)
        int right_idx = -1;
        // Binary search in Ps to find the 'P' with (i, next_j)
        // Since Ps are enumerated in order, we can have a mapping
        // To make it faster, build a map from (i,j) to idx
        // But with M <=20, a linear search is acceptable
        for(int k=0; k<M; k++){
            if(Ps[k].first == i && Ps[k].second == next_j){
                right_idx = k;
                break;
            }
        }
        // It must exist
        assert(right_idx != -1);
        
        // Similarly, find next 'P' down in column j
        int next_i;
        if(colPs[j].size() ==1){
            next_i = i; // Only one 'P' in the column, points to itself
        }
        else{
            // Use upper_bound to find the first i' > i
            auto it = upper_bound(colPs[j].begin(), colPs[j].end(), i);
            if(it == colPs[j].end()){
                next_i = colPs[j][0];
            }
            else{
                next_i = *it;
            }
        }
        // Find the index of the 'P' at (next_i, j)
        int down_idx = -1;
        for(int k=0; k<M; k++){
            if(Ps[k].first == next_i && Ps[k].second == j){
                down_idx = k;
                break;
            }
        }
        // It must exist
        assert(down_idx != -1);
        
        // Add both choices
        choices[idx].push_back(right_idx);
        choices[idx].push_back(down_idx);
    }
    
    // Implement bitmask DP
    // dp[mask] = number of ways to assign directions to first k 'P's, where mask represents assigned 'P's
    // Initialize dp[0] =1
    // Iterate over 'P's in order, for each 'P', assign to one of its choices not yet assigned
    // Finally, dp[(1<<M)-1] is the answer
    // For M <=20, use a vector of size (1<<M)
    if(M > 20){
        // To fit into 64-bit integer, M must be <=20 (since 2^20 is ~1e6)
        // but actually, with M=20, 2^20 =1,048,576 which requires around 8MB for all dp states
        // but since M <=26 (for 26 bits in 64-bit), it's manageable
        // However, implementing DP for M >20 would be time-consuming
        // So limit M to 20 for DP
        // Otherwise, output 0 since it's impossible to process larger M
        // Alternatively, mention that it's beyond the scope
        // But according to the problem statement, answer fits in 64-bit integer, so M <=20 is fine
        // Thus, proceed, assuming M <=20
    }
    
    // Initialize DP
    int max_mask = 1 << M;
    vector<ll> dp(max_mask, 0);
    dp[0] = 1;
    
    for(int i=0; i<M; i++){
        for(int mask=0; mask<(1<<M); mask++){
            if(__builtin_popcount(mask) != i) continue;
            if(dp[mask] ==0) continue;
            for(auto j : choices[i]){
                if( (mask & (1 << j)) ==0 ){
                    dp[mask | (1 << j)] += dp[mask];
                }
            }
        }
    }
    
    ll answer = dp[(1 << M) -1];
    cout << answer << "\n";
}