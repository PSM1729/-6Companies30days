// Unit Area of largest region of 1's 

//CODE

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1){
            return 0;
        }
        grid[i][j]=2;
        int u=dfs(grid,i-1,j);
        int d=dfs(grid,i+1,j);
        int l=dfs(grid,i,j-1);
        int r=dfs(grid,i,j+1);
        int ul=dfs(grid,i-1,j-1);
        int ur=dfs(grid,i-1,j+1);
        int dl=dfs(grid,i+1,j-1);
        int dr=dfs(grid,i+1,j+1);
        return 1+u+d+l+r+ul+ur+dl+dr;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int mx=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    mx=max(mx,dfs(grid,i,j));
            }
        }
        return mx;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends