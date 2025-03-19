        FOR(i, 1, n) cin >> a[i].p >> a[i].q;
        sort(a + 1, a + n + 1, compare);
        FOR(i, 1, n) p[i] = a[i].p;
        pref[0] = 0;
        pref2[0] = 0;
        pref3[0] = 0;
        FOR(i, 1, n) {
            pref[i] = (pref[i - 1] + a[i].p) % mod;
            pref2[i] = (pref2[i - 1] + (a[i].p * a[i].p) % mod) % mod;
            pref3[i] = (pref3[i - 1] + (a[i].p * a[i].p % mod * a[i].p) % mod) % mod;
        }
        FOR(i, 1, n) {
            query[a[i].q].idx.push_back(i);
        }
        for(auto &entry : query) {
            auto &curData = entry.second;
            sort(curData.idx.begin(), curData.idx.end());
            int sz = curData.idx.size();
            curData.pref.resize(sz + 1, 0);
            curData.pref2.resize(sz + 1, 0);
            curData.pref3.resize(sz + 1, 0);
            for (int i = 0; i < sz; i++) {
                int idx = curData.idx[i];
                int val = a[idx].p;
                curData.pref[i + 1] = (curData.pref[i] + val) % mod;
                curData.pref2[i + 1] = (curData.pref2[i] + (val * val) % mod) % mod;
                curData.pref3[i + 1] = (curData.pref3[i] + (val * val % mod * val) % mod) % mod;
            }
        }
        int ans = 0;
        FOR(k, 3, n) {
            FOR(j, 2, k - 1) {
                int threshold = a[k].p - a[j].p + 1;
                auto it = lower_bound(p + 1, p + j, threshold);
                if(it == p + j) continue;
                int L = it - p;
                int valid = j - L;
                if(valid <= 0) continue;
                int C = (a[j].p + a[k].p) % mod;
                int C2 = (C * C) % mod;
                int C3 = (C2 * C) % mod;
                int totalCnt, totalSum1, totalSum2, totalSum3;
                tie(totalCnt, totalSum1, totalSum2, totalSum3) = get(L, j - 1);
                int x = a[j].q, y = a[k].q;
                int contribution = 0;
                if(x == y) {
                    int cntA, sumA, sumA2, sumA3;
                    tie(cntA, sumA, sumA2, sumA3) = getRange(x, L, j - 1);
                    int cntB = totalCnt - cntA;
                    int sumB = (totalSum1 - sumA + mod) % mod;
                    int sumB2 = (totalSum2 - sumA2 + mod) % mod;
                    int contribA = (sumA + cntA * C) % mod;
                    int contribB = (sumB2 + (2 * C % mod) * sumB % mod + cntB * C2) % mod;
                    contribution = (contribA + contribB) % mod;
                } else {
                    int cntX, sumX, sumX2, sumX3;
                    tie(cntX, sumX, sumX2, sumX3) = getRange(x, L, j - 1);
                    int cntY, sumY, sumY2, sumY3;
                    tie(cntY, sumY, sumY2, sumY3) = getRange(y, L, j - 1);
                    int cntA = cntX + cntY;
                    int sumA = (sumX + sumY) % mod;
                    int sumA2 = (sumX2 + sumY2) % mod;
                    int sumA3 = (sumX3 + sumY3) % mod;
                    int contribA = (sumA2 + (2 * C % mod) * sumA % mod + cntA * C2) % mod;
                    int cntB = totalCnt - cntA;
                    int sumB = (totalSum1 - sumA + mod) % mod;
                    int sumB2 = (totalSum2 - sumA2 + mod) % mod;
                    int sumB3 = (totalSum3 - sumA3 + mod) % mod;
                    int contribB = (sumB3 + (3 * C % mod) * sumB2 % mod + (3 * C2 % mod) * sumB % mod + cntB * C3) % mod;
                    contribution = (contribA + contribB) % mod;
                }
                ans = (ans + contribution) % mod;
            }
        }

        cout << ans;