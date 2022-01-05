//UGLY NUMBERS

//CODE


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    vector<ull> ans;
	    ans.push_back(1);
	    ull i=0,j=0,k=0;
	    for(int l=1;l<n;l++){
	        ull temp= min(2*ans[i],min(3*ans[j],5*ans[k]));
	        ans.push_back(temp);
	        
	        if(temp==2*ans[i])
	            i++;
	        if(temp==3*ans[j])
	            j++;
	        if(temp==5*ans[k])
	            k++;
	    }
	    return ans[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends