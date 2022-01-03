#include <bits/stdc++.h>
using namespace std;
// Problem Name: Lifeguards

struct cow_time{
	
	int time;
	bool depart;
	int index;
	
	friend bool operator < (const cow_time& a, const cow_time& b);
	
};

bool operator < (cow_time& a, cow_time& b){
	return a.time < b.time;
}

int main(){
	
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	
	int n;
	cin >> n;
	
	cow_time ts[2 * n];
	
	for(int i = 0; i < n; ++i){
		
		cin >> ts[2 * i].time >> ts[2 * i + 1].time;
		ts[2 * i].depart = 0, ts[2 * i + 1].depart = 1;
		ts[2 * i].index = ts[2 * i + 1].index = i;
		
	}
	
	sort(ts, ts + 2 * n);
	
	set<int> active;
	int total_time = 0;
	int time_spent[n];
	memset(time_spent, 0, sizeof(time_spent));
	
	for(int i = 0; i < 2 * n; ++i){
		
		if(active.size())
			total_time += ts[i].time - ts[i-1].time;
		
		if(active.size() == 1)
			time_spent[*active.begin()] += ts[i].time - ts[i-1].time;
		
		if(ts[i].depart)
			active.erase(ts[i].index);
		else
			active.insert(ts[i].index);
		
	}
	
	int ans = total_time - *min_element(time_spent, time_spent + n);
	
	cout << ans << "\n";
	
	return 0;
	
}
