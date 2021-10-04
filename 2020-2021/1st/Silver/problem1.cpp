#include <bits/stdc++.h>
using namespace std;
//Problem Name: Cowntagion

int main(){
    
    int n, a, b;
    cin >> n;
    int d[n];
    memset(d, 0, sizeof(d));
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        d[a-1]++, d[b-1]++;
    }
    
    int ans = n - 1;
    for(int i = 0; i < n; i++){
        if(d[i] > 1 || i == 0){
            if(i != 0) d[i]--;
            int pow = 1;
            while(pow < d[i] + 1)
                ++ans, pow <<= 1;
        }
    }
    
    cout << ans << "\n";

}
