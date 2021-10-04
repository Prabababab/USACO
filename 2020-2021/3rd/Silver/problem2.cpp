#include <bits/stdc++.h>
using namespace std;
//Problem Name: Year of the Cow

int main(){
    
    int n, k, b, l = 0;
    cin >> n >> k;
    
    set<int> y;
    vector<int> anc(n);
    
    for(int i = 0; i < n; i++) cin >> b, y.insert((b + 11) / 12);
    int ans = *y.rbegin();
    for(int i = 0; !y.empty(); i++){
        anc[i] = (*y.begin() - l - 1);
        l = *y.begin();
        y.erase(y.begin());
    }
    sort(anc.rbegin(), anc.rend());
    for(int i = 0; i < k-1 && i < anc.size(); i++) ans -= anc[i];
    
    cout << ans * 12 << "\n";
    
}
