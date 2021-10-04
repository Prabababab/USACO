#include <bits/stdc++.h>
using namespace std;
//Problem Name: Mountain View

int main(){
	
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<array<int, 2>> mount(n);
	for(auto& x : mount)
		cin >> x[0] >> x[1];
	
	sort(mount.begin(), mount.end(), [&](const array<int, 2>& a, const array<int, 2>& b){
		if(a[0] - a[1] == b[0] - b[1])
			return a[0] + a[1] > b[0] + b[1];
		return (a[0] - a[1]) < (b[0] - b[1]);
	});
	
	int mx = -1, ans = 0;
	
	for(auto& x : mount){
		if(x[0] + x[1] > mx){
			++ans;
			mx = x[0] + x[1];
		}
	}
	
	cout << ans << "\n";
	
}
