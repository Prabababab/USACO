#include <bits/stdc++.h>
using namespace std;
// Problem Name: Breed Counting

int main(){
	
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	
	int arr[n+1][3];
	memset(arr, 0, sizeof(arr));
	
	for(int i = 1; i <= n; ++i){
		
		int x;
		cin >> x;
		
		arr[i][0] = arr[i-1][0] + (x == 1) + (x == 2);
		arr[i][1] = arr[i-1][1] + (x == 2) + (x == 3);
		arr[i][2] = arr[i-1][2] + (x == 3) + (x == 1);
		
	}
	
	for(int i = 0; i < q; ++i){
		
		int a, b;
		cin >> a >> b;
		--a;
		
		int mid_beg = ((arr[a][0] - arr[a][2]) + arr[a][1]) / 2;
		int mid_end = ((arr[b][0] - arr[b][2]) + arr[b][1]) / 2;
		
		
		
		cout << ((arr[b][0] - mid_end) - (arr[a][0] - mid_beg)) << " " << (mid_end - mid_beg) << " " << ((arr[b][1] - mid_end) - (arr[a][1] - mid_beg)) << "\n";
		
	}
	
}
