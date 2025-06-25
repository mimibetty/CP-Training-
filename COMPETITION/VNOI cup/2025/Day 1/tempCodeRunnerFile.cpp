#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long MOD = 1e9 + 7;

// Helper to ensure result is in [0, MOD-1]
long long normalize(long long val) {
    return (val % MOD + MOD) % MOD;
}

vector<long long> actual_shares_val; // Stores actual number of shares (not modulo)

struct SegmentTree {
    struct Node {
        long long sum_shares = 0;  // Sum of (shares_val[i] % MOD) in the range
        long long sum_balances = 0; // Sum of (balance[i] % MOD) in the range
        long long lazy_multiplier = 0; // Accumulates x_event factors for dividends
    };

    vector<Node> st;
    int n_elements; // Number of shareholders

    SegmentTree(int n) : n_elements(n) {
        st.resize(4 * n_elements + 5); // +5 for safety with 1-based indexing
    }

    void merge(Node& res_node, const Node& left_child, const Node& right_child) {
        res_node.sum_shares = normalize(left_child.sum_shares + right_child.sum_shares);
        res_node.sum_balances = normalize(left_child.sum_balances + right_child.sum_balances);
        // lazy_multiplier of res_node is not affected by merge, it's managed by down/update
    }

    void build(int id, int l, int r) { // Builds for shareholders 1 to n_elements
        st[id].lazy_multiplier = 0;
        if (l == r) {
            // actual_shares_val is initialized to 0 globally or in main
            st[id].sum_shares = normalize(actual_shares_val[l]); 
            st[id].sum_balances = 0; // Initial balance is 0
            return;
        }

        int mid = l + (r - l) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void push_lazy(int id, int l, int r) { // Renamed from 'down' to avoid conflict if user has 'down' globally
        if (st[id].lazy_multiplier == 0 || l == r) { // No lazy or is a leaf
            return;
        }

        long long x_factor = st[id].lazy_multiplier;
        int left_child_idx = id * 2;
        int right_child_idx = id * 2 + 1;

        // Apply to left child
        st[left_child_idx].sum_balances = normalize(st[left_child_idx].sum_balances + (st[left_child_idx].sum_shares * x_factor) % MOD);
        st[left_child_idx].lazy_multiplier = normalize(st[left_child_idx].lazy_multiplier + x_factor);

        // Apply to right child
        st[right_child_idx].sum_balances = normalize(st[right_child_idx].sum_balances + (st[right_child_idx].sum_shares * x_factor) % MOD);
        st[right_child_idx].lazy_multiplier = normalize(st[right_child_idx].lazy_multiplier + x_factor);

        st[id].lazy_multiplier = 0; // Reset current node's lazy tag
    }

    // Point update for a shareholder's share count
    void update_share_count_point(int id, int l, int r, int target_shareholder_idx, long long new_total_shares_for_idx_mod) {
        push_lazy(id, l, r); 
        if (l == r) { // Leaf node
            st[id].sum_shares = normalize(new_total_shares_for_idx_mod);
            // sum_balances is not directly changed by share count update
            return;
        }
        int mid = l + (r - l) / 2;
        if (target_shareholder_idx <= mid) {
            update_share_count_point(id * 2, l, mid, target_shareholder_idx, new_total_shares_for_idx_mod);
        } else {
            update_share_count_point(id * 2 + 1, mid + 1, r, target_shareholder_idx, new_total_shares_for_idx_mod);
        }
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }
    
    // Point update for a shareholder's balance
    void update_balance_point(int id, int l, int r, int target_shareholder_idx, long long new_balance_for_idx_mod) {
        push_lazy(id, l, r);
        if (l == r) { // Leaf node
            st[id].sum_balances = normalize(new_balance_for_idx_mod);
            return;
        }
        int mid = l + (r - l) / 2;
        if (target_shareholder_idx <= mid) {
            update_balance_point(id * 2, l, mid, target_shareholder_idx, new_balance_for_idx_mod);
        } else {
            update_balance_point(id * 2 + 1, mid + 1, r, target_shareholder_idx, new_balance_for_idx_mod);
        }
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }


    // Query for a single shareholder's data (Node)
    Node query_shareholder_data_point(int id, int l, int r, int target_shareholder_idx) {
        push_lazy(id, l, r);
        if (l == r) {
            return st[id];
        }
        int mid = l + (r - l) / 2;
        if (target_shareholder_idx <= mid) {
            return query_shareholder_data_point(id * 2, l, mid, target_shareholder_idx);
        } else {
            return query_shareholder_data_point(id * 2 + 1, mid + 1, r, target_shareholder_idx);
        }
    }
    
    // Convenience method for Type 2 Dividend Event
    void apply_dividend_to_all(long long x_event_mod) {
        if (st[1].sum_shares == 0 && x_event_mod == 0) return; // Optimization

        st[1].sum_balances = normalize(st[1].sum_balances + (st[1].sum_shares * x_event_mod) % MOD);
        st[1].lazy_multiplier = normalize(st[1].lazy_multiplier + x_event_mod);
    }
};


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    
    ios::sync_with_stdio(0);
    cin.tie(NULL);
   
    int N_shareholders, Q_events;
    cin >> N_shareholders >> Q_events;

    actual_shares_val.assign(N_shareholders + 1, 0); // 1-indexed

    SegmentTree seg_tree(N_shareholders);
    seg_tree.build(1, 1, N_shareholders); // Build with initial 0 shares

    for (int q_idx = 0; q_idx < Q_events; ++q_idx) {
        int type;
        cin >> type;
        if (type == 1) {
            int shareholder_id;
            long long k_shares_change;
            cin >> shareholder_id >> k_shares_change;
            
            actual_shares_val[shareholder_id] += k_shares_change;
            // Ensure actual_shares_val[shareholder_id] does not go negative per problem statement guarantee
            // "It is guaranteed that after each of these events, no shareholder will have a negative number of shares."

            seg_tree.update_share_count_point(1, 1, N_shareholders, shareholder_id, normalize(actual_shares_val[shareholder_id]));

        } else if (type == 2) {
            long long x_dividend_factor;
            cin >> x_dividend_factor;
            seg_tree.apply_dividend_to_all(normalize(x_dividend_factor));

        } else { // type == 3
            int shareholder_id;
            cin >> shareholder_id;
            
            SegmentTree::Node data = seg_tree.query_shareholder_data_point(1, 1, N_shareholders, shareholder_id);
            cout << data.sum_balances << endl;
            
            seg_tree.update_balance_point(1, 1, N_shareholders, shareholder_id, 0); // Set balance to 0
        }
    }

    return 0;
} 