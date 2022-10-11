// # Rotting Oranges

    #include <bits/stdc++.h>
    using namespace std;
    
    int orangesRotting(int grid[3][5]) {
        
        queue<pair<int,int>> q;
        int row = grid.size(), col = grid[0].size();
        int total = 0, rotten = 0, minutes = 0;
        
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()){
            int k = q.size();
            rotten += k;
            
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0 ; i<4 ; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    
                    if(nx<0 || ny<0 || nx>=row || ny>=col || grid[nx][ny] != 1)
                        continue;
                    
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty())
                minutes++;
        }
        return rotten == total ? minutes : -1;
    }
    int main(){
        int R = 3, C = 5;
        int v[R][C] = { { 2, 1, 0, 2, 1 },
                        { 1, 0, 1, 2, 1 },
                        { 1, 0, 0, 2, 1 } };
    
        cout << "Max time incurred: " << orangesRotting(v);
    
        return 0;
    }