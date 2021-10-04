#include <bits/stdc++.h>
using namespace std;
constexpr int N_SZ = 100001, K_SZ = 200001;
//Problem Name: Dance Mooves
int n, k;
int a[K_SZ], b[K_SZ];
int p[N_SZ];
vector<int> s[N_SZ];
int from[N_SZ];
int cnt[N_SZ];
int unique_pos = 0;

//add in S_node
void add(int node){
	for (int x : s[node]){
		if (cnt[x]==0)
			++unique_pos;
		++cnt[x];
	}
}

//remove S_node
void remove(int node){
	for (int x : s[node]){
		if (cnt[x]==1)
			--unique_pos;
		--cnt[x];
	}
}

bool vis[N_SZ];
queue<int> q;

void dfs(int node){
	vis[node] = true;
	add(node);
	q.push(node);
	if(!vis[p[node]])
		dfs(p[node]);
}

int main(){
	
	//input
	cin >> n >> k;
	for(int i = 0; i < k; ++i)
		cin >> a[i] >> b[i];
	
	for(int i = 1; i <= n; ++i){
		from[i] = i;
		s[i].push_back(i);
	}
	
	//simulate first k swaps
	for(int i = 0; i < k; ++i){
		s[from[a[i]]].push_back(b[i]);
        s[from[b[i]]].push_back(a[i]);
        swap(from[a[i]],from[b[i]]);
	}
	
	//record last postion of the cow
	for(int i = 1; i <= n; ++i)
		p[from[i]] = i;
	
	//find answer
	int ans[N_SZ];
	for(int i = 1; i <= n; ++i){
		if (!vis[i]){
			dfs(i);
			int temp_ans = unique_pos; //the answer 
			//assign the answer for all nodes in the cycle, which we've stored in this queue
			while (!q.empty()){
				remove(q.front());
				ans[q.front()] = temp_ans;
				q.pop();
			}
		}
	}
	
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << "\n";
	
	return 0;
	
}
