#include <bits/stdc++.h>
using namespace std;
// Problem Name: My Cow Ate My Homework

int main(){
	
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	
	int n;
	cin >> n;
	
	int freq[10001];
	memset(freq, 0, sizeof(freq));
	
	long long a[n];
	long long sum = 0;
	set<long long> scores;
	
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		scores.insert(a[i]);
		++freq[a[i]];
		sum += a[i];
	}
	
	set<pair<double, int>> answers;
	
	for(int i = 0; i < n - 2; ++i){
		
		--freq[a[i]];
		if(!freq[a[i]])
			scores.erase(a[i]);
		
		sum -= a[i];
		
		answers.insert({(sum - *scores.begin()) / ((double) n - i - 2), i + 1});
		
	}
	
	vector<int> ans;
	double _max = answers.rbegin()->first;
	for(auto e = answers.rbegin(); e != answers.rend() && e->first == _max; ++e)
		ans.push_back(e->second);
	
	for(int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << "\n";
	
	return 0;
	
}
