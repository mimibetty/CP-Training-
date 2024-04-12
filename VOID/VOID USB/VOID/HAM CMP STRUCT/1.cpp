
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