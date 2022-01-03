#include <bits/stdc++.h>
using namespace std;
// Problem Name: Milk Measurement

// I was not expecting this to work first try
// I was expecting an edge or something (lmao)

using entry = pair<int, pair<int, int>>;

int main(){
	
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	
	int n, g;
	cin >> n >> g;
	// g is beyond useless in my implementation
	
	vector<entry> e(n);
	
	for(auto& x : e)
		cin >> x.first >> x.second.first >> x.second.second;
	
	sort(e.begin(), e.end());
	
	map<int, int> freq;
	
	freq[0] = 100001;
	set<int> cows_list;
	cows_list.insert(0);
	
	unordered_map<int, int> cows;
	
	int ans = 0;
	
	for(auto& [time, x] : e){
		
		auto& [id, change] = x;
		
		bool prev_is_max = (cows[id] == *cows_list.rbegin());
		int prev_entry = freq[*cows_list.rbegin()];
		
		if(freq[cows[id]] == 1){
			cows_list.erase(cows[id]);
		}
		--freq[cows[id]];
		cows[id] += change;
		++freq[cows[id]];
		
		cows_list.insert(cows[id]);
		
		bool is_max = (cows[id] == *cows_list.rbegin());
		int _entry = freq[*cows_list.rbegin()];
		
		ans += (prev_is_max != is_max || prev_entry != _entry);
		
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
