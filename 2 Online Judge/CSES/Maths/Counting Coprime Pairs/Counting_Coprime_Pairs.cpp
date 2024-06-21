/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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

int a[100005];
vector<pii>p[100005];
vector<int>divs[100005];
int min_prime[1000005];
int cnt[1000005];
void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (min_prime[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
        }
    }
}

void find_div(int indexx, int multi, int pos) {
    if (pos == p[indexx].size()) {
        divs[indexx].pb(multi);
        return;
    }

    find_div(indexx, multi, pos + 1);
    long long new_multi = multi;
    for (int i = 1; i <= p[indexx][pos].se; i++) {
        new_multi *= p[indexx][pos].fi;
        find_div(indexx, new_multi, pos + 1);
    }

    return;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    sieve(1000000);
    map<int,int>d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n ; i++) {
        int tmp = a[i];
        while (tmp > 1) {
            int cnt = 0;
            int x = min_prime[tmp];
            while (tmp % x == 0) {
                cnt++;
                tmp /= x;
            }
            p[i].pb({x, cnt});
        } 
        if (tmp > 1) {
            p[i].pb({tmp, 1});
        }
    }


    for (int i = 1; i <= n; i++) {
        find_div(i, 1, 0);
    }

    for (int i = 1; i <= n; i++) {
        cout << "assdasd   " << a[i] << endl;
        for (auto j : divs[i]) cout << j << ' ';
        cout << endl;
    }
    return 0;


}


