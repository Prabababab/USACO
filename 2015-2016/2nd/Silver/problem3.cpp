#include <bits/stdc++.h>
using namespace std;
// Problem Name: Closing the Farm

void dfs(vector<bool>& vis, int& cur, vector<vector<int>>& adj_list){
	vis[cur] = true;
	for(int& adj : adj_list[cur])
		if(!vis[adj])
			dfs(vis, adj, adj_list);
	return;
}

int main(){
	
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	bool adj_mat[n][n];
	memset(adj_mat, 0, sizeof(adj_mat));
	for(int i = 0; i < m; ++i){
		
		int a, b;
		cin >> a >> b;
		
		--a, --b;
		adj_mat[a][b] = adj_mat[b][a] = true;
		
	}
	
	vector<int> c(n);
	for(int i = 0; i < n; ++i){
		cin >> c[n-i-1];
		--c[n-i-1];
	}
	
	vector<string> ans(n);
	vector<vector<int>> adj_list(n);
	vector<int> in;
	
	for(int i = 0; i < n; ++i){
		
		vector<bool> vis(n);
		
		int x = c[i];
		
		for(int& j : in){
			if(adj_mat[x][j]){
				adj_list[x].push_back(j);
				adj_list[j].push_back(x);
			}
		}
		
		dfs(vis, x, adj_list);
		in.push_back(x);
		
		int sum = accumulate(vis.begin(), vis.end(), 0);
		
		ans[i] = ((sum == i + 1) ? "YES\n" : "NO\n");
		
	}
	
	for(int i = n - 1; i >= 0; --i)
		cout << ans[i];
	
	return 0;
	
}
