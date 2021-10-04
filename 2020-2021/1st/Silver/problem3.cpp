#include <bits/stdc++.h>
using namespace std;
//Problem Name: Stuck in a Rut
int xc[1000], yc[1000];

bool north(const int& a, const int& b){
    return xc[a] < xc[b];
}
bool east(const int& a, const int& b){
    return yc[a] < yc[b];
}

int main(){
    
    int n;
    cin >> n;
    
    vector<int> ec, nc;
    for(int i = 0; i < n; i++){
        char d;
        cin >> d;
        vector<int>& temp = (d == 'E' ? ec : nc);
        temp.push_back(i);
        cin >> xc[i] >> yc[i];
    }
    
    sort(ec.begin(), ec.end(), east);
    sort(nc.begin(), nc.end(), north);
    
    bool s[n];
    int ans[n];
    memset(s, 0, sizeof(s));
    memset(ans, 0, sizeof(ans));
    
    for(int i : ec){
        for(int j : nc){
            if(!s[i] && !s[j] && xc[j] > xc[i] && yc[i] > yc[j]){
                if(xc[j] - xc[i] > yc[i] - yc[j]){
                    s[i] = 1;
                    ans[j] += 1 + ans[i];
                }else if(xc[j] - xc[i] < yc[i] - yc[j]){
                    s[j] = 1;
                    ans[i] += 1 + ans[j];
                }
            }
        }
    }
    
    for(int& x : ans) cout << x << "\n"; 
    
}
