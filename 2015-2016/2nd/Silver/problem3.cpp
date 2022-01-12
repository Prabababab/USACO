#include <bits/stdc++.h>
using namespace std;
// Problem Name: Build Gates

int main(){
	
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);
	
	bool grid[2005][2005] = {};
	
	int tempi = 1002, tempj = 1002;
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		int diri = 0, dirj= 0;
		switch(s[i]){
			case 'N':
				diri = 1;
				break;
			case 'S':
				diri = -1;
				break;
			case 'E':
				dirj = 1;
				break;
			case 'W':
				dirj = -1;
				break;
		}
		for(int a = 0; a < 2; ++a){
			tempi += diri, tempj += dirj;
			grid[tempi][tempj] = true;
		}
	}
	
	int di[4] = {1, -1, 0, 0};
	int dj[4] = {0, 0, 1, -1};
	
	int ans = -1;
	for(int i = 0; i <= 2004; ++i){
		for(int j = 0; j <= 2004; ++j){
			
			if(grid[i][j]) continue;
			
			++ans;
			
			queue<pair<int, int>> q;
			q.push({i, j});
			grid[i][j] = true;
			
			while(q.size()){
				int i = q.front().first, j = q.front().second;
				q.pop();
				for(int k = 0; k < 4; ++k){
					int ni = i + di[k];
					int nj = j + dj[k];
					if(ni <= 2004 && ni >= 0 && nj <= 2004 && nj >= 0 && !grid[ni][nj]){
						grid[ni][nj] = true;
						q.push({ni, nj});
					}
				}
			}
			
		}
	}
	
	cout << ans << "\n";
	
}
