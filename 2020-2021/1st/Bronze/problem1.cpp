#include <bits/stdc++.h>
using namespace std;
//Problem Name: Daisy Chains

int main(){
    
    int n;
    cin >> n;
    vector<int> f(n);
    for(int& i : f) cin >> i;
    
    int ans = n;
    for(int i = 0; i < n; i++){
        int sum = f[i];
        set<int> seen;
        seen.insert(f[i]);
        for(int j = i + 1; j < n; j++){
            sum += f[j];
            seen.insert(f[j]);
            int average = sum / (j - i + 1);
            if(average * (j - i + 1) != sum){
                continue;
            }
            if(seen.find(average) != seen.end()){
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
    
}
