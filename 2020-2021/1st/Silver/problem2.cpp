#include <bits/stdc++.h>
using namespace std;
//Problem Name: Rectangular Pature
int ps[2501][2501];

bool y_coordinate(const pair<int, int>& a, const pair<int, int>& b){
    return a.second < b.second;
}

int rsum(int x1, int y1, int x2, int y2)
{
  return ps[x2+1][y2+1] - ps[x2+1][y1] - ps[x1][y2+1] + ps[x1][y1];
}

int main(){
    int n;
    cin >> n;
    pair<int, int> cows[n];
    for(auto& [x, y] : cows) cin >> x >> y;
    
    sort(cows, cows + n);
    for(int i = 0; i < n; i++) cows[i].first = i + 1;
    sort(cows, cows + n, y_coordinate);
    for(int i = 0; i < n; i++) cows[i].second = i + 1;
    
    for(auto& [x, y] : cows) ps[x][y] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int x1 = min(cows[i].first, cows[j].first) - 1, x2 = max(cows[i].first, cows[j].first) - 1;
            ans += rsum(0,i,x1,j) * rsum(x2,i,n-1,j); 
        }
    }
    cout << ans + 1 << "\n";
    
}
