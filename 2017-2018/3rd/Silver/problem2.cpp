#include <bits/stdc++.h>
using namespace std;
// Problem Name: Snow Boots

struct boot{

	int s;
	int d;
	
	friend istream & operator >> (istream& in, boot& b);
	
};

istream & operator >> (istream& in, boot& b){
	in >> b.s >> b.d;
	return in;
}

int solve(int& n, int& b_size, vector<int>& f, vector<boot>& b){
	
	bool vis_state[n][b_size];
	memset(vis_state, 0, sizeof(vis_state));
	
	for(int bi = 0; bi < b_size; ++bi){
		for(int i = 0; i < n; ++i){
			
			if(f[i] > b[bi].s) continue;
			
			if(bi + i == 0) vis_state[i][bi] = true;
			
			for(int i2 = 0; i2 < i; ++i2)
				if(vis_state[i2][bi] && i2 + b[bi].d >= i)
					vis_state[i][bi] = true;
			
			for(int bi2 = 0; bi2 < bi; ++bi2)
				if(vis_state[i][bi2])
					vis_state[i][bi] = true;
			
			if(i == n - 1 && vis_state[i][bi])
				return bi;
			
		}
	}
	
	return -1;
	
}

int main(){
	
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	
	int n, b_size;
	cin >> n >> b_size;
	
	vector<int> f(n);
	vector<boot> b(b_size);
	
	for(int& x : f) cin >> x;
	for(boot& x : b) cin >> x;
	
	cout << solve(n, b_size, f, b) << "\n";
	
}
