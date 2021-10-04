#include <bits/stdc++.h>
using namespace std;
// Problem Name: Lemonade Line

int main(){
	
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> cows(n);
	for(int& x : cows)
		cin >> x;
	
	sort(cows.rbegin(), cows.rend());
	
	int ans = 0;
	for(; ans < n; ++ans)
		if(cows[ans] < ans) 
			break;
	
	cout << ans << "\n";
	
	return 0;
	
}
