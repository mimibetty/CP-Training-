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
 
int main(){
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(auto &x: a) cin >> x;
        ll S=0;
        for(auto x: a) S +=x;
        if(S % n !=0){
            cout << "NO" << endl;
            continue;
        }
        ll t_val = S /n;
        int M = (n +1)/2;
        ll sum1=0, sum2=0;
        for(int i=0;i<n;i++){
            if( (i%2)==0 ) sum1 +=a[i];
            else sum2 +=a[i];
        }
      
        if(sum1 == (ll)M * t_val && sum2 == (ll)(n -M)* t_val){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}



a2 + a3 = 10^5 
sum + a2*2 + a3 *6 % 9 = 0 
