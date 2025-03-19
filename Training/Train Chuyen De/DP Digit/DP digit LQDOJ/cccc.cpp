#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

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
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<ll> T(N);
    for (int i = 0; i < N; i++){
        cin >> T[i];
    }
    
    // Group stalls by product type (products are numbered 1..M)
    // For each product p, we store two vectors:
    //    pos[p]: the positions (1-indexed) of stalls selling product p.
    //    purchase[p]: the time required to purchase at that stall.
    vector<vector<int>> pos(M + 1);
    vector<vector<ll>> purchase(M + 1);
    
    for (int i = 0; i < N; i++){
        int prod = A[i];
        pos[prod].push_back(i + 1); // using 1-indexed positions.
        purchase[prod].push_back(T[i]);
    }
    
    // Although the input order (i from 1 to N) is ascending,
    // we sort each group by its stall positions to be safe.
    for (int p = 1; p <= M; p++){
        int sz = pos[p].size();
        vector<pair<int, ll>> temp(sz);
        for (int i = 0; i < sz; i++){
            temp[i] = {pos[p][i], purchase[p][i]};
        }
        sort(temp.begin(), temp.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
        for (int i = 0; i < sz; i++){
            pos[p][i] = temp[i].first;
            purchase[p][i] = temp[i].second;
        }
    }
    
    // dp[p] will store the minimum time required to purchase products 1..p 
    // ending at the corresponding stall (which sells product p).
    // For product 1, we simply take the purchase time.
    vector<vector<ll>> dp(M + 1);
    dp[1].resize(pos[1].size());
    for (size_t i = 0; i < pos[1].size(); i++){
        dp[1][i] = purchase[1][i];
    }
    
    // Transition from product p to product p+1.
    for (int p = 1; p < M; p++){
        int szCurrent = pos[p].size();
        int szNext = pos[p+1].size();
 
        // Precompute two helper arrays for the current product group.
        // leftMin[j] = min_{i=0..j} { dp[p][i] - pos[p][i] }
        // rightMin[j] = min_{i=j..szCurrent-1} { dp[p][i] + pos[p][i] }
        vector<ll> leftMin(szCurrent, INF), rightMin(szCurrent, INF);
        leftMin[0] = dp[p][0] - pos[p][0];
        for (int i = 1; i < szCurrent; i++){
            leftMin[i] = min(leftMin[i - 1], dp[p][i] - pos[p][i]);
        }
        rightMin[szCurrent - 1] = dp[p][szCurrent - 1] + pos[p][szCurrent - 1];
        for (int i = szCurrent - 2; i >= 0; i--){
            rightMin[i] = min(rightMin[i + 1], dp[p][i] + pos[p][i]);
        }
 
        // Now compute dp for product p+1.
        dp[p+1].resize(szNext, INF);
        for (int j = 0; j < szNext; j++){
            int currPos = pos[p+1][j];
            ll best = INF;
 
            // 1) Binary search for the largest index i in group p such that pos[p][i] <= currPos.
            int lo = 0, hi = szCurrent - 1, idx = -1;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                if(pos[p][mid] <= currPos){
                    idx = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if(idx != -1)
                best = min(best, leftMin[idx] + currPos);
 
            // 2) Binary search for the smallest index i in group p such that pos[p][i] >= currPos.
            lo = 0, hi = szCurrent - 1;
            idx = -1;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                if(pos[p][mid] >= currPos){
                    idx = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if(idx != -1)
                best = min(best, rightMin[idx] - currPos);
 
            dp[p+1][j] = purchase[p+1][j] + best;
        }
    }
    
    // The answer is the minimum dp value in group M.
    ll answer = INF;
    for (ll v : dp[M])
        answer = min(answer, v);
    
    cout << answer << "\n";
    return 0;
}
for (int val = 1; val <= m; val++) {
    for (auto vtnew : pos[val]) {
        for (auto vtold: pos[val-1] ) {
            dp[val][vtnew] = min(dp[val-1][vtold] + T[vtnew] + abs(vtnew - vtold))
        }
    }
}

1 2 3 4 5 