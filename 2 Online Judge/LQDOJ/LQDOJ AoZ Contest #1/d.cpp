#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for(int i=0; i<N; i++) cin >> x[i] >> y[i];
    
    // Sort x and y independently
    vector<int> sorted_x = x;
    vector<int> sorted_y = y;
    sort(sorted_x.begin(), sorted_x.end());
    sort(sorted_y.begin(), sorted_y.end());
    
    // Compute prefix sums
    vector<ll> prefix_sum_x(N+1, 0);
    vector<ll> prefix_sum_y(N+1, 0);
    for(int i=1; i<=N; i++){
        prefix_sum_x[i] = prefix_sum_x[i-1] + (ll)sorted_x[i-1];
        prefix_sum_y[i] = prefix_sum_y[i-1] + (ll)sorted_y[i-1];
    }
    
    int Q;
    cin >> Q;
    while(Q--){
        int cx, cy;
        cin >> cx >> cy;
        
        // For x
        // Number of x_i <= cx
        int cnt_x = upper_bound(sorted_x.begin(), sorted_x.end(), cx) - sorted_x.begin();
        ll sum_x_cost = ( (ll)cx * cnt_x - prefix_sum_x[cnt_x] ) + (prefix_sum_x[N] - prefix_sum_x[cnt_x] - (ll)cx * (N - cnt_x));
        
        // For y
        int cnt_y = upper_bound(sorted_y.begin(), sorted_y.end(), cy) - sorted_y.begin();
        ll sum_y_cost = ( (ll)cy * cnt_y - prefix_sum_y[cnt_y] ) + (prefix_sum_y[N] - prefix_sum_y[cnt_y] - (ll)cy * (N - cnt_y));
        
        // Total time is 2*(sum_x_cost + sum_y_cost)
        ll total_time = 2*(sum_x_cost + sum_y_cost);
        cout << total_time << "\n";
    }
}