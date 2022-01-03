#include <bits/stdc++.h>
using namespace std;
// Problem Name: Mootube

int n, q;
int vis[5000];
vector<vector<array<int, 2>>> adj_list;

int amount = 0;
void dfs(int cur, int k){
	
	vis[cur] = true;
	++amount;
	
	for(auto& x : adj_list[cur])
		if(!vis[x[1]] && x[0] >= k)
			dfs(x[1], k);
		
}

int main(){
	
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	
	cin >> n >> q;
	
	adj_list.resize(n, vector<array<int, 2>>());
	
	for(int i = 0; i < n - 1; ++i){
		
		int a, b, r;
		cin >> a >> b >> r;
		--a, --b;
		
		adj_list[a].push_back({r, b});
		adj_list[b].push_back({r, a});
		
	}
	
	
	int ans[q];
	
	for(int i = 0; i < q; ++i){
		
		int k, v;
		cin >> k >> v;
		--v;
		
		dfs(v, k);
		
		ans[i] = amount - 1;
		
		amount = 0;
		memset(vis, 0, sizeof(vis));
		
	}
	
	for(int& x : ans)
		cout << x << "\n";
	
	return 0;
	
}
