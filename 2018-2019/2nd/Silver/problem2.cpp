#include <bits/stdc++.h>
using namespace std;
// Problem Name: Icy Perimeter
vector<array<int, 2>> atop;
int n, m;
vector<string> grid;
vector<vector<bool>> vis;

void bfs(int i, int j){
	
	queue<pair<int, int>> q;
	q.push({i, j});
	
	vis[i][j] = true;
	
	int a = 0, per = 0;
	
	while(!q.empty()){
		
		auto [i, j] = q.front();
		q.pop();
		
		++a;
		
		int per_add = 4;
		
		if(i + 1 < n && grid[i+1][j] == '#' && vis[i+1][j] == false){
			vis[i+1][j] = true;
			q.push({i+1, j});
		}
		
		if(j + 1 < m && grid[i][j+1] == '#' && vis[i][j+1] == false){
			vis[i][j+1] = true;
			q.push({i, j+1});
		}
		
		if(i - 1 >= 0 && grid[i-1][j] == '#' && vis[i-1][j] == false){
			vis[i-1][j] = true;
			q.push({i-1, j});
		}
		
		if(j - 1 >= 0 && grid[i][j-1] == '#' && vis[i][j-1] == false){
			vis[i][j-1] = true;
			q.push({i, j-1});
		}
		
		per_add -= (i + 1 < n && grid[i+1][j] == '#') + (j + 1 < m && grid[i][j+1] == '#') + (i - 1 >= 0 && grid[i-1][j] == '#') + (j - 1 >= 0 && grid[i][j-1] == '#');
		
		per += per_add;
		
	}
	
	atop.push_back({a, per});
	
}

int main(){
	
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	grid.resize(n);
	for(string& x : grid)
		cin >> x;
	
	m = grid[0].size();
	vis.resize(n, vector<bool>(m, 0));
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(grid[i][j] == '#' && !vis[i][j])
				bfs(i, j);
			
	sort(atop.begin(), atop.end(), [](const array<int, 2>& a, const array<int, 2>& b){
		if(a[0] != a[1])
			return a[0] < b[0];
		else
			return a[1] > b[1];
	});
	
	array<int, 2> ans = atop.back();
	int area = ans[0], per = ans[1];
	
	cout << area << " " << per << "\n";
	
}
