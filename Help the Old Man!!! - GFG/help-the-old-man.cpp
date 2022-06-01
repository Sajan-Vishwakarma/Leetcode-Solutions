// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int moves;
    vector<int> move;
    
    void fun(int N, int from, int aux, int to,int n){
        if( N == 0) return;
        
        fun(N-1,from,to,aux,n);
        if( ++moves == n){
            move.push_back(from);
            move.push_back(to);
        }
        fun(N-1,aux,from,to,n);
    }

    vector<int> shiftPile(int N, int n){
        // code here
        moves = 0;
        move.clear();
        fun(N,1,2,3,n);
        return move;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends