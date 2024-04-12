#include<bits/stdc++.h>
using namespace std;

int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;


// Usage:
// Compressor<int> comp;
// Adding an element                : comp.add(value)
// After having all                 : comp.compress()
// Find index of value v            : comp.find(v) (1-based index)
// Get the original value of index i: comp.orig[i] (1-based index) 

template <class T>
struct Compressor {
    vector<T> values, orig;
    void add(T x) {
        values.push_back(x);
    }

    void compress() {
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        orig.resize(values.size() + 1);

        for (int i = 0; i < values.size(); i++) {
            orig[i + 1] = values[i];
        }
    }

    // return index of value (lower_bound)
    T find(T x) {
        return lower_bound(values.begin(), values.end(), x) - values.begin() + 1;
    }
};
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
     int n;
        cin >> n ;
        Compressor<int> comp;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            comp.add(a[i]);  
        }
        comp.compress();

        int maxcs = 0;
        for (int i = n; i >= 1; i--) {
            a[i] = comp.find(a[i]);
            maxcs = max(maxcs, a[i]);
            // last_pos[a[i]].push_back(i);
        }
    
    return 0;
}