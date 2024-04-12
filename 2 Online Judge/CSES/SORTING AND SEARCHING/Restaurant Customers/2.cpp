#include<bits/stdc++.h>
using namespace std;


struct Event{
	int time;
	bool isOpen;
	// IS OPEN = 1 MO
	// ISOPEN = 0 DONG
};
/*bool cmp(Event a, Event b) {
	if (a.time == b.time) {
		if (a.isOpen == b.isOpen) {
			return a.id < b.id;
		}
		return a.isOpen < b.isOpen;
	}
	return a.time < b.time;
}*/
bool cmp(Event a, Event b) {
	if (a.time == b.time) {
		return a.isOpen < b.isOpen;
	}
	else return a.time < b.time;
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int n;
	cin >> n;

	vector<Event>events;
	for (int i = 1; i <= n; i++) {
		int m,d;
		cin >> m >> d;
		events.push_back({m,1});
		events.push_back({d,0});
	} 	   
	sort( events.begin(), events.end(),cmp);
	int res = 0, numevent = 0;
	for (auto i : events) {
		if (i.isOpen == 1) {
			numevent++;
		}
		else numevent--;
		res = max(res,numevent);
	}
	cout << res;
    return 0;
}