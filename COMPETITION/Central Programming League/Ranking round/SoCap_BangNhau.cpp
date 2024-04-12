#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
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
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int a[500005];
int cnt[500005];
int res[500005];

struct Query {
    int l, r, ind;
};

const int S = 700; // (n / sqrt(q))
bool cmp(const Query &a, const Query &b) {
    if (a.l / S == b.l / S) {
        if ((a.l / S) % 2 == 0) return a.r < b.r;
        else return a.r > b.r;
    }
    return a.l / S < b.l / S;
}

int val = 0;
void add(int x) {
    cnt[x]++;
    if (cnt[x] == 2) val++;
    if (cnt[x] == 3) val--;  
}

void del(int x) {
    cnt[x]--;
    if (cnt[x] == 2) val++;
    if (cnt[x] == 1) val--;
}


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
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);


    int n, q;
    cin >> n >> q;

    Compressor<int> comp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        comp.add(a[i]);  
    }
    comp.compress();

    for (int i = n; i >= 1; i--) {
        a[i] = comp.find(a[i]);
    }


    vector<Query> queries;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }

    sort(queries.begin(), queries.end(), cmp);

    int l = 1;
    int r = 0;
    for (auto qr: queries) {
        while (r < qr.r) {
            r++;
            add(a[r]);
        }
        while (l < qr.l) {
            del(a[l]);
            l++;
        }
        while (l > qr.l) {
            l--;
            add(a[l]);
        }
        while (r > qr.r) {
            del(a[r]);
            r--;
        }
        res[qr.ind] = val;
    }

    for (int i = 1; i <= q; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}

