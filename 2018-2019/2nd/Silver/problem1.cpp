#include <bits/stdc++.h>
using namespace std;
// Problem Name: Grass Planting

int main(){
	
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int d[n];
	memset(d, 0, sizeof(d));
	
	for(int i = 1; i < n; ++i){
		int a, b;
		cin >> a >> b;
		--a, --b;
		++d[a], ++d[b];
	}
	
	int ans = 0;
	for(int& x : d)
		ans = max(x + 1, ans);
	
	cout << ans << "\n";
	
	return 0;
	
}
