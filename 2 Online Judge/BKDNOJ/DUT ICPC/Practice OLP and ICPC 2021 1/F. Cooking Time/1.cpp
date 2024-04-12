#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
int a[100005];
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
vector<int>last_pos[100005];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t; 
    while (t--) {
        set<int>s;
        int res = 0;
        int n,k;
        cin >> n >> k;
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
        for (int i = 1; i <= maxcs; i++) {
            last_pos[i].push_back(100000+i); // diem chot
        }
        for (int i = n; i >= 1; i--) {
            last_pos[a[i]].push_back(i);// vi tri cuoi
        }

        // for (int i = 1; i <= maxcs; i++) {
        //     for (auto j : last_pos[i]) cout << j << ' ' ;
        //         cout << endl;
        // }
        for (int i = 1; i <= n; i++) {
            auto it = s.find(last_pos[a[i]][last_pos[a[i]].size()-1]);
            int vt; 
            if (it != s.end()) { // da xuat hien
                s.erase(last_pos[a[i]][last_pos[a[i]].size()-1]);
                last_pos[a[i]].pop_back();
                vt = last_pos[a[i]][last_pos[a[i]].size()-1];
                s.insert(vt);
            }
            else { // a[i] chua xh 
                if (s.size() < k) { // chua du sl
                    res++;
                    last_pos[a[i]].pop_back();
                    vt = last_pos[a[i]][last_pos[a[i]].size()-1];
                    s.insert(vt);
                }
                else {
                    res++;
                    auto maxVal = *(--s.end()); // số lớn nhất
                    s.erase(maxVal);
                    last_pos[a[i]].pop_back();
                    vt = last_pos[a[i]][last_pos[a[i]].size()-1];
                    s.insert(vt);

                }
            }
            // cout << "STT: " << i <<endl;
            // cout << "VT: ";
            // for (auto j : s) cout << j << ' ';
            // cout << endl;
            // cout << "VAL: ";
            // for (auto j : s) cout << a[j] << ' ';
            // cout << endl;
            // cout << "Res: " << res << endl; 
            // cout << endl;
        }
        s.clear();
        for (int i = 1; i <= maxcs; i++)  last_pos[i].clear();
        cout << res << endl;
    }
    return 0;
}