#include <bits/stdc++.h>
using namespace std;
//Problem Name: Maze Tac Toe
int n, pwd3[10];
bool used[25][25][19683];
char maze[25][25][3];
set<int> ans;

bool test_maze(int b){
    
    int cells[3][3];
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++) {
            cells[i][j] = b%3;
            b /= 3;
        }
    }
        
    for (int r=0; r<3; r++) {
        if (cells[r][0] == 1 && cells[r][1] == 2 && cells[r][2] == 2) return true;
        if (cells[r][0] == 2 && cells[r][1] == 2 && cells[r][2] == 1) return true;
    }
    
    for (int c=0; c<3; c++) {
        if (cells[0][c] == 1 && cells[1][c] == 2 && cells[2][c] == 2) return true;
        if (cells[0][c] == 2 && cells[1][c] == 2 && cells[2][c] == 1) return true;
    }
    
    if (cells[0][0] == 1 && cells[1][1] == 2 && cells[2][2] == 2) return true;
    if (cells[0][0] == 2 && cells[1][1] == 2 && cells[2][2] == 1) return true;
    if (cells[2][0] == 1 && cells[1][1] == 2 && cells[0][2] == 2) return true;
    if (cells[2][0] == 2 && cells[1][1] == 2 && cells[0][2] == 1) return true;
    
    return false;
    
}

void dfs(int i, int j, int b){
    if(used[i][j][b]) return;
    used[i][j][b] = true;
    if(maze[i][j][0] == 'M' || maze[i][j][0] == 'O'){
        int r = maze[i][j][1] - '1', c = maze[i][j][2] - '1', idx = 3 * r + c;
        int cur_char = (b / pwd3[idx]) % 3;
        if(cur_char == 0){
            int new_char = maze[i][j][0] == 'M' ? 1 : 2;
            b = (b % pwd3[idx]) + new_char * pwd3[idx] + (b - b % pwd3[idx+1]);
            if(!used[i][j][b] && test_maze(b)) {ans.insert(b); return;};
            used[i][j][b] = true;
        }
    }
    
    if(maze[i+1][j][0] != '#') dfs(i+1, j, b);
    if(maze[i-1][j][0] != '#') dfs(i-1, j, b);
    if(maze[i][j+1][0] != '#') dfs(i, j+1, b);
    if(maze[i][j-1][0] != '#') dfs(i, j-1, b);
    
}

int main(){
    
    pwd3[0] = 1;
    for(int i = 1; i < 10; i++) pwd3[i] = pwd3[i-1] * 3;
    
    scanf("%d", &n);
    int bess_i, bess_j;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c%c%c", &maze[i][j][0], &maze[i][j][1], &maze[i][j][2]);
            if(maze[i][j][0] == 'B') bess_i = i, bess_j = j;
        }
    }
    dfs(bess_i, bess_j, 0);
    printf("%d\n", (int)ans.size());
    
    return 0;
    
}
