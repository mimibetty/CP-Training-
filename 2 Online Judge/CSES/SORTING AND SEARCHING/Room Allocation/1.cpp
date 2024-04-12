#include<bits/stdc++.h>
using namespace std;

int room[200005];

struct Event{
	int time;
	bool isOpen;
	int id;
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
		return a.isOpen > b.isOpen;
	}
	else return a.time < b.time;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int n;
	cin >> n;
	set<int>s;
	for (int i = 1; i <= n; i++) s.insert(i);

	vector<Event>events;
	for (int i = 1; i <= n; i++) {
		int m,d;
		cin >> m >> d;
		events.push_back({m,1, i});
		events.push_back({d,0, i});
	} 	   
	sort( events.begin(), events.end(),cmp);
	//	for (auto i : events) cout << i.time << ' ' << i.isOpen <<' '<<i.id << endl;	
	int res = 0, numevent = 0;
	for (auto i : events) {
		if (i.isOpen == 1) {
			numevent++;
			
			int val = *s.begin();
			room[i.id] = val;
		 	s.erase(s.find(val));
		}
		else {
			numevent--;
			s.insert(room[i.id]);
		}			

		res = max(res,numevent);
	}

	cout << res << '\n';
	for (int i = 1; i <= n; i++) {
		cout << room[i] << ' ';
	}

    return 0;
}