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

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    long long N;
    cin>>N;
    vector<string>a;
    a.resize(N);
    for (int i=0;i<N;++i) {
        cin >> a[i];
        // int b;
        // cin >> b;
        // a.push_back(b);
    }
    cout << endl;
    for (int i = 0; i < N; i++) cout << a[i] << ' ';
    cout << endl;
    for (auto i : a) cout <<i << ' ';
    cout << endl;
    for (string i : a) cout <<i << ' ';
    cout << endl;
    
    string s = "abc";
    int zz = 123;
    auto m = 1234;
    cout << m << endl;
    return 0;


    x = 123
    x = "123"
}