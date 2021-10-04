#include <bits/stdc++.h>
using namespace std;
//Problem Name: No Time to Paint

void build_sol(string fence, int* sol){
	int n = fence.size();
	stack<char> active_colors;
	for(int i = 0; i <= n; ++i){
		sol[i+1] = sol[i];
		while(!active_colors.empty() && active_colors.top() > fence[i])
			active_colors.pop();
		if (active_colors.empty() || active_colors.top() < fence[i]) { 
			active_colors.push(fence[i]); 
			sol[i+1]++;
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	string fence;
	cin >> fence;
	
	int pf_sol[n+1], sf_sol[n+1];
	memset(pf_sol, 0, sizeof(pf_sol));
	memset(sf_sol, 0, sizeof(sf_sol));
	
	build_sol(fence, pf_sol);
	reverse(fence.begin(), fence.end());
	build_sol(fence, sf_sol);
	
	while(q--){
		int i, j;
		cin >> i >> j;
		cout << pf_sol[i-1] + sf_sol[n-j] << "\n"; 
	}
	
	return 0;
	
}
