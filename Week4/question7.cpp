// .Pots of Gold Game

//CODE

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dp[500][500];
    int solve(int i, int j, vector<int>&A)
    {
        if(i==j)
            return A[i];
        
        if(j-i==1)
            return max(A[i], A[j]);
            
        if(dp[i][j]==-1)
        {
            int ch1= A[i]+ min(solve(i+1, j-1, A), solve(i+2, j, A));
            int ch2= A[j]+ min(solve(i+1, j-1, A), solve(i, j-2, A));
            dp[i][j]= max(ch1, ch2);
        }
        return dp[i][j];
        
    }
    int maxCoins(vector<int>&A,int n)
    {
        memset(dp, -1, sizeof(dp));
	    return solve(0, n-1, A);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends