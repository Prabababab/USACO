#include <bits/stdc++.h>
using namespace std;
// Problem Name: Load Balancing

int main(){
	
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	
	int n;
	cin >> n;
	
	array<int, 2> coord[n];
	
	for(int i = 0; i < n; ++i)
		cin >> coord[i][0] >> coord[i][1];
	
	sort(coord, coord + n, [](array<int, 2>& a, array<int, 2>& b){
		return a[0] < b[0];
	});
	
	int ans = INT_MAX;
	for(int i = 0; i < n; ++i){
		
		vector<array<int, 2>> above, below;
		for(int j = 0; j < n; ++j){
			vector<array<int, 2>>& ref = ((coord[j][1] <= coord[i][1]) ? below : above);
			ref.push_back(coord[j]);
		}
		
		int ai = 0, bi = 0;
		while(ai < above.size() || bi < below.size()){
			
			int x_border = INT_MAX;
			if(ai < above.size())
				x_border = min(x_border, above[ai][0]);
			if(bi < below.size())
				x_border = min(x_border, below[bi][0]);
			
			while(ai < above.size() && above[ai][0] == x_border)
				++ai;
			while(bi < below.size() && below[bi][0] == x_border)
				++bi;
			
			ans = min(ans, max(max(ai, (int) above.size() - ai), max(bi, (int) below.size() - bi)));
			
		}
		
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
