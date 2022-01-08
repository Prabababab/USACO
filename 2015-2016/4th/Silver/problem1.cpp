#include <bits/stdc++.h>
using namespace std;
//Problem Name: Field Reduction
int n;

int main(){
	
	freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);
	
	cin >> n;
	
	vector<array<long long, 2>> cows(n);
	int x[n], y[n];
	
	for(int i = 0; i < n; ++i){
		cin >> cows[i][0] >> cows[i][1];
		x[i] = i;
		y[i] = i;
	}
	
	sort(x, x + n, [&](const int& a, const int& b){
		return cows[a][0] < cows[b][0];
	});
	sort(y, y + n, [&](const int& a, const int& b){
		return cows[a][1] < cows[b][1];
	});
	
	long long ans = (cows[x[n-1]][0] - cows[x[0]][0]) * (cows[y[n-1]][1] - cows[y[0]][1]);
	
	int i[3];
	for(i[0] = 0; i[0] < 4; ++i[0]){
		for(i[1] = 0; i[1] < 4; ++i[1]){
			for(i[2] = 0; i[2] < 4; ++i[2]){
				
				unordered_set<int> del;
				
				int state[4] = {};
				state[1] = state[3] = n - 1;
				
				for(int j = 0; j < 3; ++j){
					
					int change = ((i[j] % 2) ? -1 : 1);
					int* ref = ((i[j] < 2) ? x : y);
					
					del.insert(ref[state[i[j]]]);
					
					while(del.find(ref[state[i[j]]]) != del.end()){
						state[i[j]] += change;
					}
					
				}
				
				for(int j = 0; j < 4; ++j){
					
					int change = ((j % 2) ? -1 : 1);
					int* ref = ((j < 2) ? x : y);
					
					while(del.find(ref[state[j]]) != del.end()){
						state[j] += change;
					}
					
				}
				
				ans = min(ans, (cows[x[state[1]]][0] - cows[x[state[0]]][0]) * (cows[y[state[3]]][1] - cows[y[state[2]]][1]));
				
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
