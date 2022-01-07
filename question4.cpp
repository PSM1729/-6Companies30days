//Brackets in Matrix Chain Multiplication 

//CODE:

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    pair<int, string> dp[30][30];
    bool isSet[30][30];
    
    pair<int, string> helper(int arr[], int i, int j){
        if(i == j) 
            return {0, string(1, i-1 + 'A')};
        
        if(isSet[i][j]) 
            return dp[i][j];
        
        isSet[i][j] = true;
        
        int mn = INT_MAX;
        string st;
        for(int k = i; k < j; k++){
            auto p1 = helper(arr, i, k), p2 = helper(arr, k+1, j);
            if(p1.first + p2.first + arr[i-1] * arr[k] * arr[j] < mn){
                mn = p1.first + p2.first + arr[i-1] * arr[k] * arr[j];
                st = p1.second + p2.second;
            }
        }
        
        return dp[i][j] = {mn, "(" + st + ")"};
    }
    string matrixChainOrder(int arr[], int N){
        memset(isSet, false, sizeof(isSet));
        return helper(arr, 1, N-1).second;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends