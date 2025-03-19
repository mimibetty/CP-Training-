#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 vector<ll> a;

// Count number of pairs (i, j) with i < j and a[i] + a[j] <= x
ll countPairs( ll x) {
    int n = a.size();
    ll cnt = 0;
    int i = 0, j = n - 1;
    while(i < j) {
        if(a[i] + a[j] <= x) {
            // For fixed i, all indices from i+1 to j are valid
            cnt += (j - i);
            i++;
        } else {
            j--;
        }
    }
    return cnt;
}
 
// Count number of triples (i, j, k) with i < j < k and a[i] + a[j] + a[k] <= x
ll countTriples( ll x) {
    int n = a.size();
    ll cnt = 0;
    for (int i = 0; i < n-2; i++) {
        ll rem = x - a[i];
        // Now count pairs in subarray a[i+1...n-1] with sum <= rem.
        int l = i + 1, r = n - 1;
        while(l < r) {
            if(a[l] + a[r] <= rem) {
                cnt += (r - l);
                l++;
            } else {
                r--;
            }
        }
    }
    return cnt;
}
 
int main(){
    freopen("KSET.INP", "r", stdin);
    freopen("KSET.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

 
    int n, t;
    ll k;
    cin >> n >> t >> k;
    
    a.resize(n);
    // vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
 
    ll lo, hi;
    if(t == 2) {
        lo = a[0] + a[1];
        hi = a[n-2] + a[n-1];
    } else { // t == 3
        lo = a[0] + a[1] + a[2];
        hi = a[n-1] + a[n-2] + a[n-3];
    }
 
    ll ans = hi;
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll count = 0;
        if(t == 2) {
            count = countPairs( mid);
        } else {
            count = countTriples( mid);
        }
 
        if(count >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
 
    cout << ans << "\n";
    return 0;
}