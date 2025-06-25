#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int total = n + m + 1;
    
    vector<long long> a(total), b(total);
    for (int i = 0; i < total; i++) cin >> a[i];
    for (int i = 0; i < total; i++) cin >> b[i];
    
    // Simulate hiring all n+m+1 candidates
    vector<int> type(total); // 0 = programmer, 1 = tester
    int prog_hired = 0, test_hired = 0;
    long long base_skill = 0;
    int bad = -1; // first candidate hired for suboptimal role
    
    for (int i = 0; i < total; i++) {
        bool prefers_prog = a[i] > b[i];
        
        if (prefers_prog && prog_hired < n) {
            // Hire as programmer (optimal)
            type[i] = 0;
            prog_hired++;
            base_skill += a[i];
        } else if (!prefers_prog && test_hired < m) {
            // Hire as tester (optimal)
            type[i] = 1;
            test_hired++;
            base_skill += b[i];
        } else if (prog_hired < n) {
            // Hire as programmer (suboptimal for tester-preferring candidate)
            type[i] = 0;
            prog_hired++;
            base_skill += a[i];
            if (bad == -1) bad = i;
        } else {
            // Hire as tester (suboptimal for programmer-preferring candidate)
            type[i] = 1;
            test_hired++;
            base_skill += b[i];
            if (bad == -1) bad = i;
        }
    }
    
    // Calculate answer for each excluded candidate
    for (int i = 0; i < total; i++) {
        long long answer = base_skill;
        
        if (i < bad && type[i] != type[bad]) {
            // Case 1: bad candidate can take optimal role
            if (type[i] == 0) {
                // i was programmer, bad becomes programmer, last becomes tester
                answer += (a[bad] - a[i]) + (b[total-1] - b[bad]);
            } else {
                // i was tester, bad becomes tester, last becomes programmer  
                answer += (b[bad] - b[i]) + (a[total-1] - a[bad]);
            }
        } else {
            // Case 2: only last candidate changes role
            if (type[i] == 0) {
                // i was programmer, last becomes programmer
                answer += (a[total-1] - a[i]);
            } else {
                // i was tester, last becomes tester
                answer += (b[total-1] - b[i]);
            }
        }
        
        cout << answer << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
    }
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 


xi + yi = ai -> ai = yi && xi = 0  ||    ai = xi && yi = 0

(xi−s)⋅(yi−s)≥0   xi >= s && yi >= s  ||   xi <= s && yi >= s  

F=(a1⋅x2) + (y2⋅x3+y3⋅x4+…+yn−2⋅xn−1) + (yn−1⋅an).
ai = yi && xi = 0  ||    ai = xi && yi = 0
y2⋅x3   + y3⋅x4 +  y4 x5

xi , yi =  tồn tại 1 thằng = 0 
20 