#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
//------------------------------
// Count number of pairs (i,j), i < j, with a[i] + a[j] <= X.
// (Works because the sorted array has the property that 
// for a fixed left index, if a[l] + a[r] <= X then every index between l+1 and r will work.)
ll countPairs(const vector<ll>& arr, ll X) {
    int n = arr.size();
    ll count = 0;
    int l = 0, r = n - 1;
    while(l < r){
        if(arr[l] + arr[r] <= X){
            count += (r - l);
            l++;
        } else {
            r--;
        }
    }
    return count;
}
 
//------------------------------
// Count number of triplets (i, j, k), i < j < k, with a[i] + a[j] + a[k] <= X.
// (This is the standard two--pointers method over a triple nested structure;
//  acceptable when n is small.)
ll countTriplets(const vector<ll>& arr, ll X) {
    int n = arr.size();
    ll cnt = 0;
    for (int i = 0; i < n-2; i++){
        ll target = X - arr[i];
        int l = i+1, r = n - 1;
        while(l < r){
            if(arr[l] + arr[r] <= target){
                cnt += (r - l);
                l++;
            } else {
                r--;
            }
        }
    }
    return cnt;
}
 
//------------------------------
// For t = 3 and large n (when n > 2000) we use a min-heap merging method.
// For a fixed index i (0 <= i <= n-3) the valid triplets have the form:
//   a[i] + (a[j] + a[k])  with j,k taken from the subarray arr[i+1 ... n-1] (and j < k).
// We represent the pair (j,k) from that subarray in “relative” indices (p,q):
//   j = i+1+p,  k = i+1+q   with 0 <= p < q < (n - i - 1).
// 
// The structure TripletState holds a candidate along with its state (i, p, q).
struct TripletState {
    ll sum;
    int i; // fixed index (first element in global array)
    int p; // relative index (first index in subarray B = arr[i+1..n-1])
    int q; // relative index (second index in subarray)
};
 
// Our min-heap comparator orders by candidate sum.
struct CompareTriplet {
    bool operator()(const TripletState &a, const TripletState &b){
        return a.sum > b.sum;
    }
};
 
// We encode a state (i,p,q) into a 64-bit integer for ensuring uniqueness 
// in our “visited” set. (Assuming n <= 10^5, we use bit–shifts.)
inline ll encodeState(int i, int p, int q) {
    return ( ((ll)i) << 40 ) | (((ll)p) << 20) | ((ll)q);
}
 
//------------------------------
 
int main(){
    freopen("KSET.INP", "r", stdin);
    freopen("KSET.OUT", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, t;
    ll k;
    cin >> n >> t >> k;
    vector<ll> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
 
    if(t == 2){
        // ---------- t == 2 (pair-sums) -----------
        // The smallest pair sum is arr[0]+arr[1] and the largest is arr[n-2]+arr[n-1].
        ll low = arr[0] + arr[1];
        ll high = arr[n-2] + arr[n-1];
        while(low < high){
            ll mid = low + (high - low)/2;
            ll cnt = countPairs(arr, mid);
            if(cnt < k){
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        cout << low << "\n";
    } else { // t == 3
        // ---------- t == 3 (triplet-sums) -----------
        // Use binary search counting when n is not too large.
        if(n <= 2000) {
            ll low = arr[0] + arr[1] + arr[2];
            ll high = arr[n-3] + arr[n-2] + arr[n-1];
            while(low < high){
                ll mid = low + (high - low)/2;
                ll cnt = countTriplets(arr, mid);
                if(cnt < k){
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            cout << low << "\n";
        } else {
            // For larger n we use a min-heap generator.
            // For each valid i (0 <= i <= n-3) we form a generator for triplet–sums:
            // For the subarray B = arr[i+1 ... n-1] (with length m = n - i - 1),
            // every candidate is a triplet: a[i] + B[p] + B[q]  (with 0 <= p < q < m).
            priority_queue<TripletState, vector<TripletState>, CompareTriplet> pq;
            unordered_set<ll> visited;
            visited.reserve(200000);
 
            // Initialize: for every i for which we have at least 2 numbers in the subarray,
            // push the initial candidate (p = 0, q = 1).
            for (int i = 0; i <= n - 3; i++){
                int m = n - i - 1;
                if(m >= 2){
                    TripletState st;
                    st.i = i;
                    st.p = 0;
                    st.q = 1;
                    st.sum = arr[i] + arr[i+1+st.p] + arr[i+1+st.q];
                    ll key = encodeState(i, st.p, st.q);
                    visited.insert(key);
                    pq.push(st);
                }
            }
 
            ll answer = -1;
            ll cnt = 0;
            while(!pq.empty()){
                TripletState cur = pq.top();
                pq.pop();
                cnt++;
                if(cnt == k){
                    answer = cur.sum;
                    break;
                }
                int i = cur.i;
                int p = cur.p, q = cur.q;
                int m = n - i - 1; // size of subarray B
                // Generate neighbors from current state.
                // Option 1: Increase q (the column) if possible.
                if(q + 1 < m) {
                    TripletState nxt;
                    nxt.i = i;
                    nxt.p = p;
                    nxt.q = q + 1;
                    nxt.sum = arr[i] + arr[i+1+nxt.p] + arr[i+1+nxt.q];
                    ll key = encodeState(i, nxt.p, nxt.q);
                    if(visited.find(key) == visited.end()){
                        visited.insert(key);
                        pq.push(nxt);
                    }
                }
                // Option 2: Increase p (the row), but only if p+1 < q (to maintain p < q).
                if(p + 1 < q) {
                    TripletState nxt;
                    nxt.i = i;
                    nxt.p = p + 1;
                    nxt.q = q;
                    nxt.sum = arr[i] + arr[i+1+nxt.p] + arr[i+1+nxt.q];
                    ll key = encodeState(i, nxt.p, nxt.q);
                    if(visited.find(key) == visited.end()){
                        visited.insert(key);
                        pq.push(nxt);
                    }
                }
            }
 
            cout << answer << "\n";
        }
    }
    return 0;
}