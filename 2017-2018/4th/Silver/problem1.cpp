#include <bits/stdc++.h>
using namespace std;
// Problem Name: Out of Sorts

int main(){
	
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	array<int, 2> arr[n];
	for(int i = 0; i < n; ++i){
		cin >> arr[i][1];
		arr[i][0] = i;
	}
	
	sort(arr, arr + n, [](const array<int, 2>& a, const array<int, 2>& b){
		return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]);
	});
	
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans = max(ans, arr[i][0] - i);
	}
	
	cout << ans + 1 << "\n";
	
	return 0;
	
}
