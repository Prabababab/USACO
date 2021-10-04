#include <bits/stdc++.h>
using namespace std;
//Problem Name: Comfortable Cows
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool present[3000][3000];

int main(){
    
    int n;
    cin >> n;
    
    int tc = 0;
    queue<pair<int, int>> cow_add;
    
    //adds cows if need be
    auto reevaluate = [&](int x, int y){
        if(!present[x][y]) return;
        
        int adj = 0;
        for(int i = 0; i < 4; i++)
            adj += (present[x + dx[i]][y + dy[i]]);
        
        if(adj == 3)
            for(int i = 0; i < 4; i++)
                if(!present[x + dx[i]][y + dy[i]])
                    cow_add.push({x + dx[i], y + dy[i]});
    };
    
    //initial cows adding
    for(int ic = 1; ic <= n; ic++){
        int cx, cy;
        cin >> cx >> cy;
        cx += 1000, cy += 1000;
        cow_add.push({cx, cy});
        //adding things to the queue
        while(!cow_add.empty()){
            auto& [x, y] = cow_add.front();
            cow_add.pop();
            if(present[x][y]) continue;
            ++tc, present[x][y] = 1;
            reevaluate(x, y);
            for(int i = 0; i < 4; i++)
                reevaluate(x + dx[i], y + dy[i]);
        }
        cout << tc - ic << "\n";
    }
    
}
