#include <bits/stdc++.h>
using namespace std;
// Problem Name: Painting the Barn

int main(){
	
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	int grid[1001][1001] = {};
	
	while(n--){
		
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		for(int i = a; i < c; ++i){
			++grid[i][b];
			--grid[i][d];
		}
		
	}
	
	int ans = 0;
	
	for(int i = 0; i < 1001; ++i){
		for(int j = 0; j < 1001; ++j){
			ans += (grid[i][j] == k);
			grid[i][j+1] += grid[i][j];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
