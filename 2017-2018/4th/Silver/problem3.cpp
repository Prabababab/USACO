#include <bits/stdc++.h>
using namespace std;
// Problem Name: Multiplayer Moo
// Please Note: This will TLE on some testcases :(
//              This is a work in progress
int n;
vector<vector<bool>> vis;
vector<vector<int>> grid;

struct graph_node{
	
	int id;
	int area;
	unordered_set <graph_node*> adj_nodes;
	
};
vector<vector<graph_node*>> large_node;
map<int, unordered_set<graph_node*>> cow_land;

int bfs(int& i, int& j){
	
	graph_node* g = new graph_node;
	g->id = grid[i][j];
	
	int id = grid[i][j], area = 0;
	vis[i][j] = true;
	queue<pair<int, int>> q;
	q.push({i, j});
	
	while(!q.empty()){
		
		auto [i, j] = q.front();
		q.pop();
		
		++area;
		
		if(i + 1 < n  && vis[i+1][j] == false && grid[i+1][j] == id){
			vis[i+1][j] = true;
			q.push({i+1, j});
		}else if(i + 1 < n && large_node[i+1][j] != nullptr && grid[i+1][j] != id){
			g->adj_nodes.insert(large_node[i+1][j]);
			large_node[i+1][j]->adj_nodes.insert(g);
		}
		
		if(j + 1 < n && vis[i][j+1] == false && grid[i][j+1] == id){
			vis[i][j+1] = true;
			q.push({i, j+1});
		}else if(j + 1 < n && large_node[i][j+1] != nullptr && grid[i][j+1] != id){
			g->adj_nodes.insert(large_node[i][j+1]);
			large_node[i][j+1]->adj_nodes.insert(g);
		}
		
		if(i - 1 >= 0 && vis[i-1][j] == false && grid[i-1][j] == id){
			vis[i-1][j] = true;
			q.push({i-1, j});
		}else if(i - 1 >= 0 && large_node[i-1][j] != nullptr && grid[i-1][j] != id){
			g->adj_nodes.insert(large_node[i-1][j]);
			large_node[i-1][j]->adj_nodes.insert(g);
		}
		
		if(j - 1 >= 0 && vis[i][j-1] == false && grid[i][j-1] == id){
			vis[i][j-1] = true;
			q.push({i, j-1});
		}else if(j - 1 >= 0 && large_node[i][j-1] != nullptr && grid[i][j-1] != id){
			g->adj_nodes.insert(large_node[i][j-1]);
			large_node[i][j-1]->adj_nodes.insert(g);
		}
		
		large_node[i][j] = g;
		
	}
	
	g->area = area;
	g->id = id;
	
	cow_land[id].insert(g);
	
	return area;
	
}

int max_val_graph(int a, int b){
	
	set<graph_node*> valid;
	
	valid.insert(cow_land[a].begin(), cow_land[a].end());
	valid.insert(cow_land[b].begin(), cow_land[b].end());
	
	queue<graph_node*> q;
	
	int ans = 0;
	
	while(!valid.empty()){
		
		int area = 0;
		q.push((*valid.begin()));
		valid.erase(q.front());
		
		while(!q.empty()){
			
			graph_node* g = q.front();
			q.pop();
			
			area += g->area;
			
			for(auto x : g->adj_nodes){
				if(valid.find(x) != valid.end()){
					valid.erase(x);
					q.push(x);
				}
			}
			
		}
		
		ans = max(ans, area);
		
	}
	
	return ans;
	
}


int main(){
	
// 	freopen("multimoo.in", "r", stdin);
// 	freopen("multimoo.out", "w", stdout);
	
	cin >> n;
	
	grid.resize(n, vector<int>(n));
	large_node.resize(n, vector<graph_node*>(n, nullptr));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> grid[i][j];
	
	vis.resize(n, vector<bool>(n, 0));
	
	//Part 1
	
	int max_area = 0;
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(!vis[i][j])
				max_area = max(bfs(i, j), max_area);
	
	cout << max_area << "\n";
	
	//Part 2
	
	int max_area_comb = 0;
	
	for(auto itr = cow_land.begin(); itr != cow_land.end(); ++itr){
		
		for(auto jtr = next(itr, 1); jtr != cow_land.end(); ++jtr){
			
			max_area_comb = max(max_area_comb, max_val_graph(itr->first, jtr->first));
			
		}
		
	}
	
	cout << max_area_comb << "\n";
	
}
