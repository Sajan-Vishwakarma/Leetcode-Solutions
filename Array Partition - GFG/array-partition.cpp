// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool partitionArray(int n, int k, int m, vector<int> &a){
        // code here
        sort(a.begin(),a.end());
    
        vector<int> dp(n,-1);
        
        function<int(int)> fun=[&](int curr){
            
            if( curr >= n) 
                return 1;
                
            if( dp[curr] != -1)
                return dp[curr];
            
            bool ok = false;
            for(int i=curr+k-1;i<n;i++){
                if(abs(a[i]-a[curr]) > m) break;
                ok |= fun(i+1);
                if(ok) return 1;
            }
            return dp[curr] = ok;
        };
        
        return fun(0);
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends