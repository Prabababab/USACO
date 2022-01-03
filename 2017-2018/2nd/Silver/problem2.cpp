#include <bits/stdc++.h>
using namespace std;
// Problem Name: Rental Service

int main(){
	
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	
	int n, m, r;
	cin >> n >> m >> r;
	
	long long cows[n];
	array<long long, 2> stores[m];
	long long farmers[r];
	
	for(long long& x : cows)
		cin >> x;
	for(array<long long, 2>& x : stores)
		cin >> x[0] >> x[1];
	for(long long& x : farmers)
		cin >> x;
	
	sort(cows, cows + n, greater<long long>());
	sort(stores, stores + m, [](const array<long long, 2>& a, const array<long long, 2>& b){
		return a[1] > b[1];
	});
	sort(farmers, farmers + r, greater<long long>());
	
	long long ans = accumulate(farmers, farmers + min(n, r), 0LL);
	
	int i = 0, index = 0, f_index = min(n, r) - 1;;
	for(; i < n - r; ++i){
		
		while(index < m && cows[i] > 0){
			
			ans += stores[index][1] * min(stores[index][0], cows[i]);
			
			if(cows[i] > stores[index][0]){
				cows[i] -= stores[index][0];
				++index;
			}else{
				stores[index][0] -= cows[i];
				cows[i] = 0;
			}
			
		}
		
	}
	
	long long temp = ans;
	
	for(; i < n; ++i){
		
		temp -= farmers[f_index--];
		
		while(index < m && cows[i] > 0){
			
			temp += stores[index][1] * min(stores[index][0], cows[i]);
		
			if(cows[i] > stores[index][0]){
				cows[i] -= stores[index][0];
				++index;
			}else{
				stores[index][0] -= cows[i];
				cows[i] = 0;
			}
			
		}
		
		ans = max(ans, temp);
		
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
