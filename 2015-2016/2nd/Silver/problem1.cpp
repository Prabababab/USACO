#include <bits/stdc++.h>
using namespace std;
// Problem Name: Angry Cows

// Binary Search because log_2 (1000000000) = ~30 which is not a bad constant factor
// Make a check method that will take O(n) time or something and you should be fine

vector<int> arr;

bool check (int rad, int k){
	
	int prev = arr[0];
	int res_k = 1;
	
	for(int i = 1; i < arr.size(); ++i){
		
		if(prev + 2 * rad < arr[i]){
			++res_k;
			prev = arr[i];
		}
		
		if(res_k > k)
			return false;
		
	}
	
	return true;
	
}

int main(){
	
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	arr.resize(n);
	for(int& x : arr)
		cin >> x;
	
	sort(arr.begin(), arr.end());
	
	int l = 0, r = arr.back();
	while(l <= r){
		
		int mid = (l + r) / 2;
		
		if(check(mid, k))
			r = mid - 1;
		else
			l = mid + 1;
		
	}
	
	cout << l << "\n";
	
	return 0;
	
}
