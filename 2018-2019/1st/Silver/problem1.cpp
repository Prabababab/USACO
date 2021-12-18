#include <bits/stdc++.h>
using namespace std;
//Problem Name: Convention

int n, m, c;
int cows[100000];

bool pos(int T){
	
	int buses = 1;
	int c_ind = 0, c_arr = cows[0];
	
	for(int i = 1; i < n; ++i){
		
		if(cows[i] - c_arr > T || i + 1 - c_ind > c){
			++buses;
			c_ind = i, c_arr = cows[i];
		}
		
	}
	
	return (buses <= m);
	
}

int bin_search(int low, int high){
	
	if(low == high)
		return low;
	else if(low + 1 == high)
		return ((pos(low)) ? low : high);
	
	int mid = (low + high) / 2;
	
	if(pos(mid))
		return bin_search(low, mid);
	else
		return bin_search(mid + 1, high);
	
}

int main(){
	
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	
	cin >> n >> m >> c;
	
	for(int i = 0; i < n; ++i)
		cin >> cows[i];
	
	sort(cows, cows + n);
	
	cout << bin_search(0, 1000000000) << "\n";
	
}
