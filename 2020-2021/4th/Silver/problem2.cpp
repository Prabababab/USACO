#include <bits/stdc++.h>
using namespace std;
//Problem Name: Do You Know Your ABC's
vector<vector<int>> row_templates = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 1, 0}};
bool used[7];
int ans;

bool over_determined(vector<vector<int>> matrix){
    
    return 0;
}

int solve(int n, int a[], int cur, vector<vector<int>> matrix){
    cout << "used: ";
    for(int i = 0; i < 7; i++) cout << used[i] << " ";
    if(cur == n) return !over_determined(matrix);
    int ans = 0;
    for(int i = 0; i < 7; i++){
        if(used[i]) continue;
        matrix[cur] = row_templates[i];
        matrix[cur][3] = a[cur];
        used[i] = true;
        ans += solve(n, a, cur + 1, matrix);
        used[i] = false;
    }
    return ans;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        int a[n];
        for(int& x : a) cin >> x;
        
        int ans = solve(n, a, 0, vector<vector<int>>(n, vector<int>(3, 0)));
        cout << ans << "\n";
        
    }
    
}
