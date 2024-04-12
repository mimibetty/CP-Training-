/*
link submit: 
Note: tạo cạnh từ i đến ai 
với mỗi đỉnh thì tạo ra 2 vector
scareBy những thời sợ i  x -> i
scare: những thằng i sợ  i -> x

việc còn lại là for và tìm những thằng mà size scareBy = 0 

khi xét 1 đỉnh i (chỉ xét khi số đỉnh sợ ai = 0)
thêm ai  1 queue, giảm đi số thằng sợ ai

scare[i] các đỉnh i sợ 
scared[i] đỉnh sợ i 
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

int n;
// nối từ i -> ai
int a[100005];
int c[100005];
int num[100005]; // số đỉnh sợ i        x -> i
int adj[100005];// adj là đỉnh mà i sợ  i -> adj

void resett() {
    for (int i = 1;i i <= n; i++)
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }    
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<int>res;
    vector<int>f;
    for (int i = 1; i <= n; i++) {
        if (num[a[i]])

    }
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
    cin >> t;

    while (t--)    
    solve();
    
    return 0;
}