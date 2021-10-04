#include <bits/stdc++.h>
using namespace std;
//Problem Name: Spaced Out

int main(){
	
	int n;
	cin >> n;
	
	long long grid[n][n];
	for(int i = 0; i < n; ++i)
		for(int j=  0; j < n; ++j)
			cin >> grid[i][j];
	
	long long hor_alt_ans = 0, ver_alt_ans = 0;
	
	for(int i = 0; i < n; ++i){
		long long sums[2];
		sums[0] = sums[1] = 0;
		for(int j = 0; j < n; ++j){
			sums[j % 2] += grid[i][j];
		}
		hor_alt_ans += max(sums[0], sums[1]);
	}
	
	for(int j = 0; j < n; ++j){
		long long sums[2];
		sums[0] = sums[1] = 0;
		for(int i = 0; i < n; ++i){
			sums[i % 2] += grid[i][j];
		}
		ver_alt_ans += max(sums[0], sums[1]);
	}
	
	cout << max(ver_alt_ans, hor_alt_ans);
	
}
