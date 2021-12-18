#include <bits/stdc++.h>
using namespace std;
// Problem Name: Convention II

typedef pair<int, pair<int, int>> cow;

int main(){
	
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	
	int n;
	cin >> n;
	
	cow data[n];
	for(int i = 0; i < n; ++i){
		data[i].first = i;
		cin >> data[i].second.first >> data[i].second.second;
	}
	
	sort(data, data + n, [](cow& a, cow& b){
		return a.second.first < b.second.first;
	});
	
	int ans = 0, leave = data[0].second.first + data[0].second.second;
	
	set<cow> waiting;
	bool added[n];
	memset(added, 0, sizeof(added));
	
	int i = 1;
	while(i < n || waiting.size()){
		
		while (i < n && data[i].second.first <= leave) {
			waiting.insert(data[i]);
			++i;
		}
		
		if (waiting.empty() && i < n) {
			leave = data[i].second.first + data[i].second.second;
			++i;
		}else if (waiting.size()) {
			ans = max(ans, leave - waiting.begin()->second.first);
			leave = leave + waiting.begin()->second.second;
			waiting.erase(waiting.begin());
		}
		
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
