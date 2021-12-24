#include <bits/stdc++.h>
using namespace std;
// Problem Name: Sleepy Cow Herding

int find_min(int* cows, int& n){
	
	if (cows[n-2] - cows[0] == n - 2 && cows[n-1] - cows[n-2] > 2) return 2;
	if (cows[n-1] - cows[1] == n - 2 && cows[1] - cows[0] > 2) return 2;
	
	int j = 0, best = 0;
	for (int i = 0; i < n; ++i) {
		while (j < n - 1 && cows[j + 1] - cows[i] <= n - 1) ++j;
		best = max(best, j - i + 1);
	}
	
	return n - best;
	
}

int main(){
	
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	
	int n;
	cin >> n;
	
	int cows[n];
	for(int& x : cows)
		cin >> x;
	
	sort(cows, cows + n);
	
	//Find the minimum
	int ans_min = find_min(cows, n);
	
	//Find the maximum
	int ans_max = max(cows[n-1] - cows[1], cows[n-2] - cows[0]) - (n - 2);
	
	cout << ans_min << "\n" << ans_max << "\n";
	
	return 0;
	
}
