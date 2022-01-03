#include <bits/stdc++.h>
using namespace std;
// Problem Name: The Bovine Shuffle

int main(){
	
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	
	int n;
	cin >> n;
	
	int a[n], freq[n];
	memset(freq, 0, sizeof(freq));
	for(int& x : a){
		cin >> x;
		--x;
		++freq[x];
	}
	
	int ans = n;
	queue<int> q;
	
	for(int i = 0; i < n; ++i){
		if(freq[i] == 0){
			q.push(a[i]);
			--ans;
		}
	}
	
	while(q.size()){
		int i = q.front();
		q.pop();
		if(--freq[i] == 0){
			q.push(a[i]);
			--ans;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
