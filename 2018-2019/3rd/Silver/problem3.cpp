#include <bits/stdc++.h>
using namespace std;
// Problem Name: The Great Revegetation

// The trick is to find out the number of independent cycles since each cycle has 2 ways of being seeded so n cycles yields 2^n seedings

int n, m;
int st[100000];
vector<vector<int>> d_list, s_list;
bool impossible;

void visit(int n, int v){
	
	st[n] = v;
	
	for(int a : d_list[n]){
		if(st[a] == 0)
			visit(a, 3 - v);
		else if(st[a] == v){
			impossible = true;
			return;
		}
	}
	
	for(int a : s_list[n]){
		if(st[a] == 0)
			visit(a, v);
		else if(st[a] == 3 - v){
			impossible = true;
			return;
		}
	}
	
}

int main(){
	
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	cin >> n >> m;
	d_list.resize(n);
	s_list.resize(n);
	
	while(m--){
		
		char s;
		int a, b;
		cin >> s >> a >> b;
		--a, --b;
		
		if(s == 'S'){
			s_list[a].push_back(b);
			s_list[b].push_back(a);
		}else if(s == 'D'){
			d_list[a].push_back(b);
			d_list[b].push_back(a);
		}
		
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(st[i]) continue;
		if(impossible) break;
		if(st[i] == 0)
			visit(i, 1);
		++ans;
	}
	
	if(impossible){
		cout << "0\n";
	}else{
		cout << 1;
		for(int i = 0; i < ans; ++i)
			cout << 0;
		cout << "\n";
	}
	
	return 0;
	
}
