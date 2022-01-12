#include <bits/stdc++.h>
using namespace std;
// Problem Name: Subsequences Summing to Seven

int main(){
	
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	
	int n;
	cin >> n;
	
	int pref = 0, temp;
	int first[7], last[7];
	for(int i = 0; i < 7; ++i)
		first[i] = INT_MAX, last[i] = 1;
	
	for(int i = 0; i < n; ++i){
		cin >> temp;
		pref = (pref + temp) % 7;
		first[pref] = min(first[pref], i);
		last[pref] = i;
	}
	
	int ans = INT_MIN;
	for(int i = 0; i < 7; ++i)
		if(first[i] <= n)
			ans = max(ans, last[i] - first[i]);
	
	
	cout << ans << "\n";
	
	return 0;
	
}
