//Find total number of Squares in a N*N chessboard

//CODE

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<< ((n+1)*(2*n+1)*(n))/6<<endl;
    }
}