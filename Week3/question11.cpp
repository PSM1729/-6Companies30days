// Generate and print all binary numbers with decimal values from 1 to N.  

//CODE

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
void bin(unsigned n, string &a){
    if(n>1)
        bin(n/2,a);

    a+= to_string(n%2);
}
vector<string> generate(int N)
{
	vector<string> te;
	for(int i=1;i<=N;i++){
	    string a="";
	    bin(i,a);
	    te.push_back(a);
	}
	return te;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends