//Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.

//CODE:


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src){
    int l=1,n=src.length();
    string a;
    for(int i=1;i<n;i++){
        if(src[i-1]==src[i]){
            l++;
        }
        else{
            a+=src[i-1]+to_string(l);
            l=1;
        }
    }
    a+=src[n-1]+to_string(l);
    return a;
}     
 
