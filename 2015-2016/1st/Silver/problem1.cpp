#include <bits/stdc++.h>
using namespace std;
// Problem Name: Switching on the Lights

int bfs(map<pair<int, int>, vector<array<int, 2>>>& switch_list, int n, vector<vector<bool>>& lit){
	
	queue<pair<int, int>> to_visit;
	bool vis[n][n];
	memset(vis, 0, sizeof(vis));
	vis[0][0] = true;
	to_visit.push({0, 0});
	
	int amount_lit = 0;
	
	while(!to_visit.empty()){
		
		auto& [x, y] = to_visit.front();
		to_visit.pop();
		
// 		cout << x << " " << y << " " << switch_list[{x, y}].size() << "\n";
		
		for(array<int, 2>& v : switch_list[{x, y}]){
			
			amount_lit += (!lit[v[0]][v[1]]);
			lit[v[0]][v[1]] = true;
			
		}
		
		if(x + 1 < n && !vis[x+1][y] && lit[x+1][y]){
			to_visit.push({x+1, y});
			vis[x+1][y] = true;
		}
		
		if(x - 1 >= 0 && !vis[x-1][y] && lit[x-1][y]){
			to_visit.push({x-1, y});
			vis[x+1][y] = true;
		}
		
		if(y + 1 < n && !vis[x][y+1] && lit[x][y+1]){
			to_visit.push({x, y+1});
			vis[x][y+1] = true;
		}
			
		if(y - 1 >= 0 && !vis[x][y-1] && lit[x][y-1]){
			to_visit.push({x, y-1});
			vis[x][y-1] = true;
		}
			
	}
	
	return amount_lit;
	
}

int main(){
	
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	map<pair<int, int>, vector<array<int, 2>>> switch_list;
	vector<vector<bool>> lit(n, vector<bool>(n, 0));
	
	set<pair<int, int>> poss;
	
	for(int i = 0; i < m; ++i){
		
		pair<int, int> p;
		cin >> p.first >> p.second;
		
		array<int, 2> a;
		cin >> a[0] >> a[1];
		
		--p.first, --p.second, --a[0], --a[1];
		switch_list[p].push_back(a);
		poss.insert({a[0], a[1]});
		
	}
	
	lit[0][0] = true;
	
	int ans = 1;
	
	while(ans < m){
		
		int temp = bfs(switch_list, n, lit);
		if(temp == 0){
			break;
		}
		ans += temp;
		
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
