#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pll pair<long long,long long>
#define int long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i =a; i<=b; i++)
#define ROF(i,a,b) for(int i =a; i>=b; i--)

const long long MOD = 1e9+7;

using namespace std;

int n,A,B;
vector<int> adj[200005];
int door;
int st[200005];
void rst(){
    for (int i =1; i<=n; i++){
        adj[i].clear();
        st[i]=0;
    }
    door=0;
}

void dfs_cyc(int a, int p){
    if (st[a]) return;
    st[a]=1;
    cout<<a<< "  ";
    for (auto x: adj[a]){
        if (x==p) continue;
        if (st[x]==1){
            st[a]=2;
            st[x]=2;
            door = x;
            continue;
        }
        dfs_cyc(x,a);
        if (st[x]==2 && x!=door){
            st[a]=2;
            // if (a == door) door = 0;
        }
    }

    // door = 0;
    cout << endl << "des  " << a << ' ' << st[a] << ' ' << door << endl;
}


void solve(){
    cin>>n>>A>>B;
    rst();
    for (int i =1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "begin   ";
    dfs_cyc(B,0);
    cout << "END  " << endl << endl;
    cout << door << endl;
    for (int i = 1; i <= n; i++) {
        cout << st[i] << ' ';
    }
    if (B==A){
        cout<<"NO"<<endl;
        return;
    }
    if (st[B]==2){
        cout<<"YES"<<endl;
    }
    else {
        deque<pii> q;
        q.push_back({door,0});
        int disa, disb;
        for (int i =1; i<=n; i++) st[i]=0;
        while(!q.empty()){
            auto [t,dis] = q.front();
            q.pop_front();
            if (st[t]) continue;
            st[t]=1;
            if (t==A) disa = dis;
            if (t==B) disb = dis;
            for (auto x:adj[t]){
                if (st[x]) continue;
                q.push_back({x,dis+1});
            }
        }
        if (disa<=disb){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;  
        }
    }

}

int32_t main(){
     if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t=1;
    while(t--)
        solve();
    return 0;
}