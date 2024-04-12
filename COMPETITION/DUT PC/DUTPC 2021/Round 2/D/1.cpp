#include<bits/stdc++.h>
#define maxn 11
#define maxm 1005
using namespace std;
int n, m, k;
struct data{
    int team, step;
    data(int _team, int _step) : team(_team), step(_step){};
    data(){};
};
struct data1{
    int team, x, y;
    bool operator < (const data1 Data1) const{
        return (team < Data1.team);
    }
    data1(int _team, int _x, int _y) : team(_team), x(_x), y(_y){};
    data1(){}; 
};
data dp[maxm][maxm];
int a[maxn],res[maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<data1> check;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int cnt = n * m;
    for (int i = 1; i <= k;i++){
        cin >> a[i];
    }
    for (int i = 0; i <= n + 1;i++){
        dp[i][0].team = -1;
        dp[i][m + 1].team = -1;
    }
    for (int i = 0; i <= m + 1;i++){
        dp[0][i].team = -1;
        dp[n + 1][i].team = -1;
    }
    for (int i = 1; i <= n;i++){
        string s;
        cin>>s;
        for (int j = 1; j <= m;j++){
            if(s[j-1]=='.'){
                dp[i][j].team = 0;
            }
            else
            if(s[j-1]=='#'){
                dp[i][j].team = -1;
                cnt--;
            }
            else{
                cnt--;
                dp[i][j].team = s[j - 1] - '0';
                dp[i][j].step = 0;
                check.push_back(data1(s[j - 1] - '0', i, j));
            }
        }
    }
    sort(check.begin(), check.end());
    queue<data1> find[maxn];
    for (int i = 0; i < check.size();i++){
        int teams = check[i].team;
        find[teams].push(data1(teams, check[i].x, check[i].y));
    }
        while(cnt){
            int checklast=0;
            for (int i = 1; i <= k;i++){
                if(find[i].empty()){
                    checklast++;
                }
                if(cnt==0){
                    break;
                }
                while(!find[i].empty()){
                    int u = find[i].front().x, v = find[i].front().y;
                    find[i].pop();
                    if(cnt==0){
                        break;
                    }
                    if(dp[u][v].step==a[i]){
                        queue<data1> checklast;
                        dp[u][v].step = 0;
                        checklast.push(data1(i, u, v));
                        while(!find[i].empty()){
                            int uu = find[i].front().x, vv = find[i].front().y;
                            dp[uu][vv].step = 0;
                            checklast.push(data1(i, uu, vv));
                            find[i].pop();
                        }
                        while(!checklast.empty()){
                            find[i].push(checklast.front());
                            checklast.pop();
                        }
                        break;
                    }
                    for (int j = 0; j < 4;j++){
                        int id1 = u + dx[j];
                        int id2 = v + dy[j];
                        if(dp[id1][id2].team==0){
                            dp[id1][id2].team=i;
                            dp[id1][id2].step = dp[u][v].step + 1;
                            find[i].push(data1(i, id1, id2));
                            cnt--;
                        }
                    }
                }
            }
            if(checklast==k){
                break;
            }
        }
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                if(dp[i][j].team>=1)
                res[dp[i][j].team]++;
            }
        }
        for (int i = 1; i <= k;i++){
            cout << res[i] << ' ';
        }
            return 0;
}