#include <iostream>
#define INF 1000000001
using namespace std;
//Problem Name: Stuck in a Rut

struct Cow{
    int x, y;
    char dir;
    int stopped;
};

Cow cow[50];
int n;

int hit(int i, int j, int cur_time){
    
    Cow I = cow[i], J = cow[j];
    if (I.dir == J.dir) return INF;
    if (I.dir == 'E') {
        swap (I.x, I.y);
        swap (J.x, J.y); 
    }
    if (J.y <= I.y) return INF;
    if (J.stopped == INF) {
        if (I.x < J.x - cur_time || I.x >= J.x + J.y - I.y) return INF;
    } else {
        if (I.x > J.x || I.x < J.x - J.stopped) return INF;
    } 
    return cur_time + J.y - I.y;
    
}

int advance_to_next_event(int cur_time){
    
    int t[50], minT = INF;
 
    for (int i=0; i < n; i++) {
        t[i] = INF;
        if (cow[i].stopped == INF) {
            for (int j=0; j < n; j++) {
                t[i] = min(hit(i, j, cur_time), t[i]);
            }
            minT = min(minT, t[i]);
        }
    }
  
    if (minT == INF) return INF;

    for (int i=0; i<n; i++) {
        if (cow[i].stopped == INF){
            if (cow[i].dir == 'N') cow[i].y += (minT - cur_time);
            else cow[i].x += (minT - cur_time);
            
            if (t[i] == minT) cow[i].stopped = minT;
        }
    }

    return minT;
    
}

int main(){
    
    freopen("console.txt", "r", stdin);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> cow[i].dir >> cow[i].x >> cow[i].y;
        cow[i].stopped = INF;
    }
    
    int cur_time = 0;
    do{cur_time = advance_to_next_event(cur_time);}
    while(cur_time != INF);
    
    for(int i = 0; i < n; i++){
        if(cow[i].stopped == INF) cout << "Infinity\n";
        else cout << cow[i].stopped << "\n";
    }
    
}
