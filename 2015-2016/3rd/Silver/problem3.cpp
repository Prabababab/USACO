#include <bits/stdc++.h>
using namespace std;
// Problem Name: Milk Pails

int main(){
	
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	
	int x, y, k, m;
	cin >> x >> y >> k >> m;
	
	bool can[x+1][y+1];
	memset(can, 0, sizeof(can));
	
	can[0][0] = true;
	
	for(int o = 0; o < k; ++o){
		
		bool next[x+1][y+1];
		memset(next, 0, sizeof(next));
		
		for(int i = 0; i < x + 1; ++i){
			for(int j = 0; j < y + 1; ++j){
				if(!can[i][j]) continue;
				
				next[i][j] = true;
				next[0][j] = true;
				next[i][0] = true;
				next[i][y] = true;
				next[x][j] = true;
				
				int min_right = min(j, x - i);
				next[i + min_right][j - min_right] = true;
				
				int min_left = min(i, y - j);
				next[i - min_left][j + min_left] = true;
				
			}
		}
		memcpy(can, next, sizeof(next));
		
	}
	
	int ans = INT_MAX;
	for(int i = 0; i <= x; ++i)
		for(int j = 0; j<= y; ++j)
			if(can[i][j])
				ans = min(ans, abs(i + j - m));
	
	cout << ans << "\n";
	
	return 0;
	
}
