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
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
 
vector<int>a;
int d[105];
int n;

bool isprime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}
// --------- Solution
int lcmm(int a,int b) {
    return a*b/__gcd(a,b);
}
// void solve() {

//     for (int i=1; i<6;i++ ) {
//         cout << "? 1 " << r << endl;
//         cin >> len1;
//         if (len1 == -1) {
//             cout << "! " << r-1 << endl;
//             return;
//         }
 
//         cout << "? " << r << " 1" << endl;
//         cin >> len2;
 
//         if (len1 == len2) {
//             r++;
//         } else {
//             cout << "! " << len1 + len2 << endl;
//             return;
//         }
 
//         i+=2;
//     }
//     assert(false);
// }
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }


    for (int i = 2; i <= 99; i++) {
        if (isprime(i)) {
            d[i] = 1;
            a.pb(i);
        }
    }
    n = a.size();
// 25
    char x;
    int l = 0, r = 24;
    for (int z = 1; z <= 5; z++) {
        while (l < r) {
            int mid = (l + r + 1) / 2;
            cout << "? " << a[mid] <<endl;
            // cout << l << ' ' << r << endl;
            cin >> x;
            if (x == '<') {
                l = mid;
            }
            else r = mid - 1;
            // cout << endl;
        }
    }

    cout << "! " << a[l] << endl;

    // int k = 5;
    // cout << k*k << endl;
    // for (auto i : a) {
    //   cout << lcmm(i,k) << ' ';
    //   // cout << i << ' ';
    // } 

    // cout << "? 2" << endl;
    // char x;
    // cin >> x;
    // if (x == '<') cout << "! "<< x << endl;
    // else cout << "! " << x/2 << endl;

}