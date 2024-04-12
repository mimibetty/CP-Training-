    #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef double ld;
    typedef long double lld;
    typedef pair<int,int> pii;
    typedef pair<double,double> pdd;
    typedef pair<long long, long long> pll;

    #define For(i, l, r) for (int i = l; i < r; i++)
    #define REP(i, l, r) for (int i = l; i <= r; i++)
    #define FordE(i, l, r) for (int i = l; i >= r; i--)
    #define Fora(v, a) for (auto v: a)
    #define MS(s, n) memset(s, n, sizeof(s))
    #define All(v) (v).begin(),(v).end()

    #define cntBit __builtin_popcount 
    #define fi first 
    #define se second
    #define pb push_back
    #define precision(x) cout << setprecision(x) << fixed;
    #define EL cout << endl;
    #define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
    #define SQ(a) a*a

    const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
    const long long oo = 1e18 + 7;
    const int MOD = int(1e9)+7;
    const double PI = acos(-1);
    const int limx = 1e6;


    int pos[100005];
    bool check(int vt1, int target, int x, vector<int>&a) {
        if (abs(vt1 - target) >= x) {
            int n = vt1, m = target;
            a[vt1] = a[m];
            a[target] = a[n];
            return 1;  
        } 
        if (vt1 >= x &&  target >= x) {
            
        }  return 1;
        if (a.size() - 1 - vt1 >= x && a.size() - 1 - target >= x) return 1;
        return 0;
    }

    int main() {
        // freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        
        int t;
        cin >> t;
        
        while(t--) {
            vector<int>a,b;
            map<int,int>vt;
            int n,x;
            cin >> n >> x;
            bool done = 1;

            for (int i = 1; i <= n; i++) {
                int d;
                cin >> d;
                a.pb(d);
                b.pb(d);
            }
            sort(All(b));

            for (int i = (n-1); i >= 0; i--) {
                vt[b[i]] = i;
            }
            for (int i = 0; i < n; i++) {
                pos[i] = vt[a[i]];
                vt[a[i]]++;
                // cout <<  pos[i] << ' ';
                if (pos[i] == i) continue;
                if (check(i, pos[i],x, a) == 0) {
                    done = 0;
                    break;
                }  
            }

            if (done == 1) cout << "YES";
            else cout << "NO";
            cout << endl;
            
            vt.clear();
            a.clear();
            b.clear();
            for (int i = 0 ; i <= n ; i++) pos[i] = 0;
        }

        return 0;
    }