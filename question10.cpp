//Find max 10 numbers in a list having 10M entries.

//CODE

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    priority_queue<ll> pq;
    for(int i=0;i<100;i++){
        int n;
        cin>>n;
        pq.push(n);
    }
    int k=0;
    while(k!=10){
        cout<<pq.top();
        pq.pop();
        k++;
    }
}