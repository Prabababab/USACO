#include <bits/stdc++.h>
using namespace std;
int n;
int g[500][500];
//Problem Name: Just Green Enough

long long valid_sub_grids(int m){
    
    //typical prefix sums
    int ones[n][n];
    memset(ones, 0, sizeof(ones));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ones[i][j] = (j == 0 ? 0 : ones[i][j-1]) + (g[i][j] >= m); //total number of ones from 0 to j in the i part of the 2d array
        }
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = -1; j < i; j++){
            int run = 0;
            for(int k = 0; k < n; k++){
                if(ones[k][i] - (j == -1 ? 0 : ones[k][j]) == i - j) ans += ++run; //if the amount of ones in the segment is equal to the total number of cells, then we know that all the cells are made up of ones
                else run = 0;
            }
        }
    }
    
    return ans;
    
}

int main(){
    
    cin >> n;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    
    cout << valid_sub_grids(100) - valid_sub_grids(101) << "\n";
    
}
