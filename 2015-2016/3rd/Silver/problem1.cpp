#include <bits/stdc++.h>
using namespace std;
// Problem Name: Circular Barn

int main(){
	
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	
	int n;
	cin >> n;
	
	long long rooms[n], temp = 0, c = 0, index = 0;
	for(int i = 0; i < n; ++i){
		cin >> rooms[i];
		temp += rooms[i] - 1;
		if(temp < c)
			c = temp, index = i;
	}
	
	rotate(rooms, rooms + ((index + 1) % n), rooms + n);
	
	long long ans = 0;
	queue<int> cows;
	for(int i = 0; i < n; ++i){
		
		while(rooms[i]){
			cows.push(i);
			--rooms[i];
		}
		
		int cow = cows.front();
		cows.pop();
		
		ans += pow(i - cow, 2);
		
	}
	
	cout << ans << "\n";
	
	return 0;
	
}
