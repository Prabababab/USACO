#include <bits/stdc++.h>
using namespace std;
//Problem Name: Diamond Collector

int main(){
	
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	
	long long n, k;
	cin >> n >> k;
	
	long long d[n];
	for(long long& x : d)
		cin >> x;
	
	sort(d, d + n);
	
	long long m[n];
	memset(m, 0, sizeof(m));
	
	int l = 0, r = 0;
	while(l < n){
		
		if(r >= n){
			m[l] = r - l;
			++l;
			continue;
		}
		
		while(r < n && d[l] + k >= d[r])
			++r;
		
		m[l] = r - l;
		
		++l;
		
	}
	
	long long ans = 0;
	
	for(int i = 0; i < n; ++i){
		
		long long test = m[i];
		
		for(int j = i + m[i]; j < n; ++j){
			
			test = max(test, m[i] + m[j]);
			
		}
		
		ans = max(ans, test);
		
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
