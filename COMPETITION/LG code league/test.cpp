#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);


    
    int n;  if(!(cin >> n)) return 0;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin >> a[i];

    // random 64-bit numbers for each value and residue 1,2
    vector<array<ull,3>> H(n+1);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int v=1; v<=n; ++v){
        H[v][1]=rng(); H[v][2]=rng(); H[v][0]=0ULL;
    }

    vector<char> cnt(n+1,0);                 // counts mod 3
    vector<deque<int>> occ(n+1);             // last up-to-3 indices
    unordered_map<ull, deque<int>> pos;      // hash -> prefix indices
    pos.reserve(n*2);
    
    ull state = 0;
    pos[state].push_back(0);                 // prefix 0
    long long ans = 0;
    int L = 0;

    for(int r=1; r<=n; ++r){
        int v = a[r];
        // update state hash
        state ^= H[v][cnt[v]];               // remove old contribution
        cnt[v] = (cnt[v]+1)%3;
        state ^= H[v][cnt[v]];               // add new contribution

        // maintain at-most-3 occurrences
        occ[v].push_back(r);
        if(occ[v].size()==4){
            L = max(L, occ[v].front());
            occ[v].pop_front();
        }

        auto &dq = pos[state];
        while(!dq.empty() && dq.front() < L) dq.pop_front();
        ans += (long long)dq.size();
        dq.push_back(r);
    }
    cout << ans << '\n';
    return 0;
}