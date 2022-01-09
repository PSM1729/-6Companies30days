// Rotten orange

//CODE
class Solution {
public:
    int x_dir[4]={1,0,-1,0},y_dir[4]={0,1,0,-1};
    bool issafe(vector<vector<int>>& g,int x, int y){
        return (x>=0 && x<g.size() && y>=0 && y<g[0].size() && g[x][y] == 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int time=-1,fresh=0,r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    fresh++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto f=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int x_co=f.first+x_dir[j],y_co=f.second+y_dir[j];
                    //cout<<x_co<<y_co<<"*";
                    if(issafe(grid,x_co,y_co)==true){
                        grid[x_co][y_co]=2;
                        q.push({x_co,y_co});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return (fresh>0)?-1:((time == -1) ? 0 : time);
    }
};