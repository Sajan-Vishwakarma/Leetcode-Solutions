// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        
        vector<vector<long long>> dp(n,vector<long long>(n,1e9));
        vector<vector<int>> bracket(n,vector<int>(n));

        for(int i=0;i<n;i++) dp[i][i] = p[i];

        for(int len = 2;len<=n;len++){
            for(int i=1;i<n;i++){
                int j = i+len-1; 
                if(j >= n) break;
                
                for(int k=i;k<j;k++){
                    long long cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                    if( cost < dp[i][j]){
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        
        char ch = 'A';
        string order="";
        function<void(int,int)> pop = [&](int i,int j){
            
            if(i == j){
                order += ch++;
                return;
            }
            
            order+="(";
            pop(i,bracket[i][j]);
            pop(bracket[i][j]+1,j);
            order+=")";
        };
        
        pop(1,n-1);
        
        return order;
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