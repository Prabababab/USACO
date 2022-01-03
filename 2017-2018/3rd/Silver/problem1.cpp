#include <bits/stdc++.h>
using namespace std;
// Problem Name: Rest Stops

int main(){
	
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	
	int L, n;
	long long rf, rb;
	cin >> L >> n >> rf >> rb;
	
	array<long long, 2> stops[n];
	for(array<long long, 2>& s : stops)
		cin >> s[0] >> s[1];
	
	sort(stops, stops + n, [](const array<long long, 2>& a, const array<long long, 2>& b){
		if(a[1] != b[1]) 
			return a[1] < b[1];
		return a[0] < b[0];
	});
	
	long long last_pos = 0, i = n - 1;
	long long ans = 0;
	while(i >= 0){
		if(stops[i][0] < last_pos){
			--i;
			continue;
		}
		ans += (rf - rb) * (stops[i][0] - last_pos) * stops[i][1];
		last_pos = stops[i][0];
		--i;
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
