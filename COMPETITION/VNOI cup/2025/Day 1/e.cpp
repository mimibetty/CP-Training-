#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

long long MOD = 1e9 + 7;

// Globals to be accessed by the DP function
int N_global_dp;
const vector<int>* A_global_dp_ptr;
int current_fixed_j_dp;
int current_val_target_dp;
const vector<int>* other_A_indices_list_dp_ptr;

map<pair<int, int>, long long> memo_dp;

long long count_valid_assignments_recursive(int k_th_other_idx, int p_options_mask) {
    if (k_th_other_idx == other_A_indices_list_dp_ptr->size()) {
        return 1; // Successfully assigned all other N-1 elements
    }
    
    pair<int, int> state = {k_th_other_idx, p_options_mask};
    if (memo_dp.count(state)) {
        return memo_dp[state];
    }

    long long count = 0;
    int current_a_idx_val = (*other_A_indices_list_dp_ptr)[k_th_other_idx];

    for (int p_val = 0; p_val < N_global_dp; ++p_val) {
        // Check if p_val is available in p_options_mask
        if (!((p_options_mask >> p_val) & 1)) {
            continue;
        }

        bool condition_met = false;
        int b_val = (*A_global_dp_ptr)[current_a_idx_val] & p_val;

        if (current_val_target_dp == 0) {
            // If target max is 0, all B_k (for k != fixed_j) must be 0.
            if (b_val == 0) {
                condition_met = true;
            }
        } else { // current_val_target_dp > 0
            if (current_a_idx_val < current_fixed_j_dp) { // This is A_k where k < j
                if (b_val <= current_val_target_dp) {
                    condition_met = true;
                }
            } else { // This is A_k where k > j (current_a_idx_val must be > current_fixed_j_dp)
                if (b_val < current_val_target_dp) {
                    condition_met = true;
                }
            }
        }
        
        if (condition_met) {
            count = (count + count_valid_assignments_recursive(k_th_other_idx + 1, p_options_mask ^ (1 << p_val))) % MOD;
        }
    }

    return memo_dp[state] = count;
}


void solve_test_case() {
    int n_local, k_bits_local; // N and K for this test case
    cin >> n_local >> k_bits_local;
    
    vector<int> a_local(n_local);
    for (int i = 0; i < n_local; ++i) {
        cin >> a_local[i];
    }

    if (n_local == 0) {
        cout << 0 << endl;
        return;
    }
    
    // Setup globals for DP
    N_global_dp = n_local;
    A_global_dp_ptr = &a_local;
    
    long long total_f_sum = 0;
    vector<int> temp_other_A_indices_list; // To pass to DP
    other_A_indices_list_dp_ptr = &temp_other_A_indices_list;


    for (int j = 0; j < n_local; ++j) { 
        current_fixed_j_dp = j;
        for (int p_val_for_j = 0; p_val_for_j < n_local; ++p_val_for_j) {
            current_val_target_dp = a_local[j] & p_val_for_j;
            
            temp_other_A_indices_list.clear();
            for (int idx = 0; idx < n_local; ++idx) {
                if (idx != j) {
                    temp_other_A_indices_list.push_back(idx);
                }
            }
            // The order of elements in temp_other_A_indices_list is fixed (idx increasing).
            // This order is used by k_th_other_idx in the DP.

            memo_dp.clear(); // Clear memo for each new (j, p_val_for_j) configuration
            
            int initial_p_mask = ((1 << n_local) - 1) ^ (1 << p_val_for_j);
            long long num_configurations_for_others;
            if (n_local == 1) { // Base case if only one element, other_list is empty
                 num_configurations_for_others = 1; // (dp called with k_th_other_idx = 0, size = 0)
            } else {
                 num_configurations_for_others = count_valid_assignments_recursive(0, initial_p_mask);
            }
            
            total_f_sum = (total_f_sum + (long long)j * num_configurations_for_others) % MOD;
        }
    }

    cout << total_f_sum << endl;
}

int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Optional: redirect input for local testing
    // if (fopen("input.txt", "r")) {
    //     freopen("input.txt", "r", stdin);
    // }

    int t;
    cin >> t;
    while (t--) {
        solve_test_case();
    }
    return 0;
}
