// Given a matrix of size r*c. Traverse the matrix in spiral form.

//CODE

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int kr=0,lc=0;
        vector<int> ans;
        while(kr<r && lc<c){
            for(int i=lc;i<=c-1;i++)
                ans.push_back(matrix[kr][i]);
            kr++;
            
            for(int i=kr;i<=r-1;i++)
                ans.push_back(matrix[i][c-1]);
                
            c--;
            if(kr<r){
                for(int i=c-1;i>=lc;--i)
                    ans.push_back(matrix[r-1][i]);
                    
                r--;
            }
            if(lc<c){
                for(int i=r-1;i>=kr;--i)
                    ans.push_back(matrix[i][lc]);
            lc++;
            }
        }
        return ans; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends