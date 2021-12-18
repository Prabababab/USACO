#include <bits/stdc++.h>
using namespace std;
// Problem Name: Mooyo Mooyo
typedef vector<array<int, 2>> region;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print_arr(vector<vector<int>>& grid){
	int n = grid.size(), m = grid[0].size();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			cout << grid[i][j];
		cout << "\n";
	}
}

region bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int& n, int& m, int i, int j, int color){
	
	vis[i][j] = true;
	queue<pair<int, int>> q;
	
	bool DEBUG = (color == 1);
	
	region ans;
	
	q.push({i, j});
	ans.push_back({i, j});
	
	while(q.size()){
		
		auto [i, j] = q.front();
		q.pop();
		
		for(int d = 0; d < 4; ++d){
			
			if(i + dx[d] < n && i + dx[d] >= 0 && j + dy[d] < m && j + dy[d] >= 0 && grid[i+dx[d]][j+dy[d]] == color && vis[i+dx[d]][j+dy[d]] == false){
				ans.push_back({i+dx[d], j+dy[d]});
				q.push({i+dx[d], j+dy[d]});
				vis[i+dx[d]][j+dy[d]] = true;
			}
			
		}
		
	}
	
	return ans;
	
}

bool zeroing(int& n, int& m, int& k, vector<vector<int>>& grid){
	
	vector<vector<bool>> vis(n, vector<bool>(n, 0));
	
	vector<vector<int>> copy = grid;
	
	vector<region> poss;
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(grid[i][j] > 0 && vis[i][j] == false)
				poss.push_back(bfs(grid, vis, n, m, i, j, grid[i][j]));
		
	for(region& x : poss)
		if(x.size() >= k)
			for(auto& y : x)
				grid[y[0]][y[1]] = 0;
			
	return copy == grid;
		
}

void gravity(vector<vector<int>>& grid, int& n, int& m){
	
	for(int i = 0; i < m; ++i){
		
		int z = n - 1, nz = n - 1;
		
		while(z >= 0 && nz >= 0){
			
			while(z >= 0 && grid[z][i] != 0){
				--z;
				nz = min(nz, z);
			}
			
			while(nz >= 0 && grid[nz][i] == 0){
				--nz;
			}
			
			while(z >= 0 && nz >= 0 && grid[z][i] == 0 && grid[nz][i] != 0){
				swap(grid[z][i], grid[nz][i]);
				--z, --nz;
			}
		}
		
	}
	
}

int main(){
	
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> k;
	
	vector<string> parse(n);
	for(int i = 0; i < n; ++i)
		cin >> parse[i];
	
	m = parse[0].size();
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			grid[i][j] = parse[i][j] - '0';
		
	while(!zeroing(n, m, k, grid)){
		gravity(grid, n, m);
	}
	
	gravity(grid, n, m);
	print_arr(grid);
	
}
