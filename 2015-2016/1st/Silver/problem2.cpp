#include <bits/stdc++.h>
using namespace std;
// Problem Name: High Card Wins

int main(){
	
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	
	int n;
	cin >> n;
	
	bool belongs[2 * n];
	memset(belongs, 0, sizeof(belongs));
	
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		belongs[x-1] = true;
	}
	
	vector<int> players[2];
	for(int i = 0; i < 2 * n; ++i)
		players[belongs[i]].push_back(i);
	
	int ans = 0;
	for(int bi = 0, ei = 0; bi < n && ei < n; ++bi)
		if(players[0][bi] > players[1][ei])
			++ei, ++ans;
	
	cout << ans << "\n";
	
	return 0;
	
}
