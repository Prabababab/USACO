#include <bits/stdc++.h>
using namespace std;
//Problem Name: Acowdemia

int main(){
    
    int n, k, l;
    cin >> n >> k >> l;
    
    int p[n];
    for(int& x : p) cin >> x;
    sort(p, p + n, greater<int>());
    
    int left = 0, right = n;
    while(left < right){
        int mid = (left + right + 1) / 2;
        long cost = 0;
        for(int i = 0; i < mid; i++) cost += max(0, mid - p[i]);
        if(cost <= ((long) k) * ((long) l) && p[mid - 1] + k >= mid) left = mid;
        else right = mid - 1;
    }
    
    cout << right << "\n";
    
}
