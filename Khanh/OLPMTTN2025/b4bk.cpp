#include <bits/stdc++.h>
using namespace std;
 
// --- Modulo arithmetic ---
 
// modulo constant
const int MOD = 998244353;
 
// safe multiplication mod MOD using __int128 for safety
inline int modMul (int a, int b) {
    __int128 t = a;
    t = t * b % MOD;
    return (int)t;
}
 
// modular addition (ensuring result is in [0,MOD))
inline int modAdd(int a, int b){
    int s = a + b;
    if(s >= MOD) s -= MOD;
    return s;
}
 
// modular subtraction
inline int modSub(int a, int b){
    int s = a - b;
    if(s < 0) s += MOD;
    return s;
}
 
// --- Data Structures ---
// A Hero holds combat strength P (as 64-bit) and skill code Q (to be compressed).
struct Hero {
    int64_t P;
    int Q;
};
 
// A structure to hold aggregated values from a range query.
struct SumData {
    int cnt;
    int s1;
    int s2;
    int s3;
};
 
// --- Main ---
int main(){
    // if(fopen("input.txt", "r")) {
    //      freopen("input.txt","r",stdin);
    //      // freopen("output.txt","w",stdout);
    //  }
 
     ios::sync_with_stdio(0);
     cin.tie(NULL);
  
    int n; 
    cin >> n;
    vector<Hero> heroes(n);
    vector<int> qVals(n);
    for (int i = 0; i < n; i++){
        int64_t p;
        int q;
        cin >> p >> q;
        heroes[i].P = p;
        heroes[i].Q = q; // will compress later
        qVals[i] = q;
    }
 
    // Compress skill code values.
    vector<int> comp = qVals;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 0; i < n; i++){
        int pos = int(lower_bound(comp.begin(), comp.end(), heroes[i].Q) - comp.begin());
        heroes[i].Q = pos;
    }
 
    // Sort heroes by combat strength P (non-decreasing).
    sort(heroes.begin(), heroes.end(), [](const Hero &a, const Hero &b){
        return a.P < b.P;
    });
 
    // Precompute for each hero the values:
    // G0 = 1, G1 = P mod MOD, G2 = (P^2) mod MOD, G3 = (P^3) mod MOD.
    vector<int> G0(n, 1);
    vector<int> G1(n, 0), G2(n, 0), G3(n, 0);
    for (int i = 0; i < n; i++){
        int pmod = (int)(heroes[i].P % MOD);
        if(pmod < 0) pmod += MOD;
        G1[i] = pmod;
        G2[i] = modMul(pmod, pmod);
        G3[i] = modMul(G2[i], pmod);
    }
 
    // Build global prefix arrays PG0, PG1, PG2, PG3.
    vector<int> PG0(n), PG1(n), PG2(n), PG3(n);
    PG0[0] = G0[0];
    PG1[0] = G1[0];
    PG2[0] = G2[0];
    PG3[0] = G3[0];
    for (int i = 1; i < n; i++){
        PG0[i] = modAdd(PG0[i-1], G0[i]);
        PG1[i] = modAdd(PG1[i-1], G1[i]);
        PG2[i] = modAdd(PG2[i-1], G2[i]);
        PG3[i] = modAdd(PG3[i-1], G3[i]);
    }
 
    // Lambda: query global prefix for indices [L,R] (inclusive)
    auto queryGlobal = [&](int L, int R) -> SumData {
        SumData ret;
        if(L > R){
            ret.cnt = 0; ret.s1 = 0; ret.s2 = 0; ret.s3 = 0;
            return ret;
        }
        ret.cnt = (L == 0 ? PG0[R] : modSub(PG0[R], PG0[L-1]));
        ret.s1  = (L == 0 ? PG1[R] : modSub(PG1[R], PG1[L-1]));
        ret.s2  = (L == 0 ? PG2[R] : modSub(PG2[R], PG2[L-1]));
        ret.s3  = (L == 0 ? PG3[R] : modSub(PG3[R], PG3[L-1]));
        return ret;
    };
 
    // Build “bucket” arrays for each distinct skill–code.
    int nbuckets = comp.size();
    vector<vector<int>> bucketIndices(nbuckets);
    // For each hero in sorted order, add its global index to the appropriate bucket.
    for (int i = 0; i < n; i++){
        int b = heroes[i].Q;
        bucketIndices[b].push_back(i);
    }
    // For each bucket, build prefix arrays (bucketPG0, bucketPG1, bucketPG2, bucketPG3)
    vector<vector<int>> bucketPG0(nbuckets), bucketPG1(nbuckets), bucketPG2(nbuckets), bucketPG3(nbuckets);
    for (int b = 0; b < nbuckets; b++){
        int sz = bucketIndices[b].size();
        if(sz == 0) continue;
        bucketPG0[b].resize(sz);
        bucketPG1[b].resize(sz);
        bucketPG2[b].resize(sz);
        bucketPG3[b].resize(sz);
        for (int j = 0; j < sz; j++){
            int idx = bucketIndices[b][j];  // global index
            if(j == 0){
                bucketPG0[b][j] = 1;
                bucketPG1[b][j] = G1[idx];
                bucketPG2[b][j] = G2[idx];
                bucketPG3[b][j] = G3[idx];
            } else {
                bucketPG0[b][j] = modAdd(bucketPG0[b][j-1], 1);
                bucketPG1[b][j] = modAdd(bucketPG1[b][j-1], G1[idx]);
                bucketPG2[b][j] = modAdd(bucketPG2[b][j-1], G2[idx]);
                bucketPG3[b][j] = modAdd(bucketPG3[b][j-1], G3[idx]);
            }
        }
    }
 
    // Lambda: query bucket for skill bucket 'b' over global indices [L,R] (inclusive)
    auto queryBucket = [&](int b, int L, int R) -> SumData {
        SumData ret;
        ret.cnt = 0; ret.s1 = 0; ret.s2 = 0; ret.s3 = 0;
        auto &vec = bucketIndices[b];
        if(vec.size() == 0) return ret;
        int lo = int(lower_bound(vec.begin(), vec.end(), L) - vec.begin());
        int hi = int(upper_bound(vec.begin(), vec.end(), R) - vec.begin()) - 1;
        if(lo > hi) return ret;
        ret.cnt = (lo == 0 ? bucketPG0[b][hi] : modSub(bucketPG0[b][hi], bucketPG0[b][lo-1]));
        ret.s1  = (lo == 0 ? bucketPG1[b][hi] : modSub(bucketPG1[b][hi], bucketPG1[b][lo-1]));
        ret.s2  = (lo == 0 ? bucketPG2[b][hi] : modSub(bucketPG2[b][hi], bucketPG2[b][lo-1]));
        ret.s3  = (lo == 0 ? bucketPG3[b][hi] : modSub(bucketPG3[b][hi], bucketPG3[b][lo-1]));
        return ret;
    };
 
    // --- Main double-loop: Process each valid triple ---
    // For each triple (i,j,k) with i < j < k and with P[i]+P[j] > P[k]
    long long answer = 0; // will be computed mod MOD
    for (int k = 2; k < n; k++){
        // Use the actual (64-bit) combat strengths for the validity (triangle–inequality) test.
        int64_t Pk = heroes[k].P;
        int L = 0, R = k - 1;  // two–pointers on indices in [0, k-1]
        while(L < R){
            if( heroes[L].P + heroes[R].P > Pk ){
                // If valid then for fixed R and all i in [L, R-1] the team (i, R, k) is valid.
                // We set a constant C = P[R] + P[k] (we work in mod arithmetic now).
                int C = (int)(( (heroes[R].P % MOD) + (Pk % MOD) ) % MOD);
                int C2 = modMul(C, C);
                int C3 = modMul(C2, C);
 
                // Query global prefix over indices [L, R-1].
                SumData globalSeg = queryGlobal(L, R-1);
 
                int qR = heroes[R].Q, qk = heroes[k].Q;
                int blockContribution = 0;
                if(qR == qk){
                    // Case 1.
                    // Group A: i with Q[i]==qk → exponent D = 1 so add (P[i]+C)
                    SumData groupA = queryBucket(qk, L, R-1);
                    int partA = modAdd(groupA.s1, modMul(groupA.cnt, C));
                    // Group B: the others (with Q[i]!=qk) → exponent D = 2 and their contribution is (P[i]+C)^2.
                    int cntB = modSub(globalSeg.cnt, groupA.cnt);
                    int s1B  = modSub(globalSeg.s1, groupA.s1);
                    int s2B  = modSub(globalSeg.s2, groupA.s2);
                    int partB = modAdd( modAdd(s2B, modMul((2 * C) % MOD, s1B)),
                                        modMul(cntB, C2) );
                    blockContribution = modAdd(partA, partB);
                } else {
                    // Case 2: qR != qk.
                    // Group B: those i with Q[i] == qR or Q[i]==qk → exponent D=2.
                    SumData buck1 = queryBucket(qR, L, R-1);
                    SumData buck2 = queryBucket(qk, L, R-1);
                    int cntB = modAdd(buck1.cnt, buck2.cnt);
                    int s1B  = modAdd(buck1.s1, buck2.s1);
                    int s2B  = modAdd(buck1.s2, buck2.s2);
                    int partB = modAdd( modAdd(s2B, modMul((2 * C) % MOD, s1B)),
                                        modMul(cntB, C2) );
                    // Group C: the remaining i with neither Q[i]==qR nor Q[i]==qk → exponent D=3.
                    int cntB_total = globalSeg.cnt;
                    int cntC = modSub(cntB_total, cntB);
                    int s1C  = modSub(globalSeg.s1, modAdd(buck1.s1, buck2.s1));
                    int s2C  = modSub(globalSeg.s2, modAdd(buck1.s2, buck2.s2));
                    int s3C  = modSub(globalSeg.s3, modAdd(buck1.s3, buck2.s3));
                    int partC = modAdd( modAdd(s3C, modMul( (3 * C) % MOD, s2C ) ),
                                        modAdd(modMul((3 * C2) % MOD, s1C), modMul(cntC, C3)) );
 
                    blockContribution = modAdd(partB, partC);
                }
                blockContribution %= MOD;
                answer = (answer + blockContribution) % MOD;
 
                // After processing this block (all i in [L, R-1] with partner R) we move R--
                R--;
            } else {
                L++;
            }
        }
    }
 
    cout << answer % MOD << "\n";
 
    return 0;
}