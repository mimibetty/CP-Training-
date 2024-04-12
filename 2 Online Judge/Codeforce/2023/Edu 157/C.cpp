/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}
string s[200005];
long long pre[10][10][300], suff[10][10][300];
const int pl = 100;
long long ps[10];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        int z = 0;
        int lenn = s[i].size();
        for (int j = 0; j < lenn; j++) {
            z += int(s[i][j] - '0');
            ps[j + 1] = ps[j]  + int(s[i][j] - '0') ;
        }

        for (int j = lenn - 1; j >= 0; j--) {
            // pre[j + 1][lenn - j - 1][z]++;
            // z  -=  int(s[i][j] - '0');
            int trai = ps[j+1];
            int phai = ps[lenn] - trai;
            pre[j + 1][lenn - j - 1][trai - phai + pl]++;
            
        }
    }

    for (int i = 1; i <= n; i++) {
        int z = 0;
        int lenn = s[i].size();
        for (int j = 0; j < lenn; j++) {
            z += int(s[i][j] - '0');
            ps[j + 1] = ps[j]  + int(s[i][j] - '0') ;    
        }

        for (int j = 0; j < lenn; j++) {
            // suff[j][lenn - j][z]++;
            // z  -=  int(s[i][j] - '0');
            int trai = ps[j];
            int phai = ps[lenn] - trai;
            suff[j][lenn - j][phai - trai + pl]++;
            
        }
    }


    // for (int i = 1; i <= 5; i++) {
    //     for (int  j = 0; j <= 5; j++) {
    //         for (int z = 0; z <= 90; z++) {
    //             if (pre[i][j][z]) cout << i << ' ' << j << ' ' << z -pl << ' ' <<pre[i][j][z] <<endl; 
    //         }
    //     }
    // }

    //     EL;
    //     EL;
    ll res = 0;
    for (int num = 2; num <= 10; num+=2) {
        for (int l1 = 1; l1 <= 5; l1++) {
            for (int r1 = 0; r1 <= 5; r1++) {
                for (int l2 = 0; l2 <= 5; l2++) {
                    int r2 = num - (l1 + r1 + l2);
                    if (r2 <= 0) continue;

                    if (l1 >= num/2 && r1 + r2 != l1) continue;
                    if (l1 >= num/2 && l2 != 0) continue;
                    if (r2 >= num/2 && r1 != 0) continue;
                    if (r2 >= num/2 && r2 != l1 + l2) continue;
                    if (l2 > 0 && r1 != 0) continue;
                    if (r1 > 0 && l2 != 0) continue;
                    if (l1 + l2 != r1 + r2) continue;
                    
                    for (int sum1 = 0; sum1 <= 300; sum1++) {
                        // if (pre[l1][r1][sum1] *suff[l2][r2][sum1]) {
                        //     cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << sum1 -pl << endl;
                        //     cout << pre[l1][r1][sum1] << "  " << suff[l2][r2][sum1] << endl << endl;
                        // }
                        res+= pre[l1][r1][sum1] *suff[l2][r2][sum1];
                    }
                }
            }
        } 
    }
    cout <<res <<endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    // cin >> t;
    while (t--)    
    solve();
    
    return 0;
}