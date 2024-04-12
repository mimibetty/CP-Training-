#include<bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<pair<int,int>>event;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
    	int l,r;
    	cin >> l >> r;
    	event.push_back({l,r});
    } 

    sort(event.begin(),event.end());
    
   /* for (int i = 0 ; i< n; i++) {
    	cout << event[i].first << ' ' << event[i].second << endl;
    }*/
    int res = 0;
    int endtime = 0;
    for (int i = 0; i < n; i++) {
    	if (endtime <= event[i].first) {
    		res++;
    		endtime = event[i].second;
    	}
    	else if (endtime > event[i].second) endtime = event[i].second;
    	//cout << event[i].first << ' ' << event[i].second <<' '<< res <<  endl;	
    }
    
    cout << res;
    return 0;
}