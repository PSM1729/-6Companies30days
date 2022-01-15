//Minimum steps to destination

//CODE

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        long long int t= abs(D);
        long long k=0;
        while(t>0){
            k++;
            t=t-k;
        }
        if(t%2==0)
            return k;
        else
            return k+1+k%2;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends