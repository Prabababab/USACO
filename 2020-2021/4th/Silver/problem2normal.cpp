#include <bits/stdc++.h>
using namespace std;
//Problem Name: Do You Know Your ABC's

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        int nums[n];
        for(int& x : nums) cin >> x;
        
        int ans = 0;
        set<int> diff;
        for(int& x : nums){
            diff.insert(x);
            for(int& y : nums)
                if(x < y)
                    diff.insert(y - x);
        }
        
        for(const int& a : diff){
            for(const int& b : diff){
                for(const int& c : diff){
                    if(a <= b && b <= c){
                        int arr[7] = {a, b, c, a + b, b + c, a + c, a + b + c};
                        bool poss = true;
                        for(int& x : nums){
                            if(find(arr, arr + 7, x) == arr + 7){
                                poss = false;
                                break;
                            }
                        }
                        ans += poss;
                    }
                }
            }
        }
        
        cout << ans << "\n";
        
    }
    
}
