// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        //code here
        
        vector<int> ans(n,0);
        vector<pair<int,int>> stk;
        
        for(int i=n-1;i>=0;i--){
            
            if( !stk.empty() && stk.back().first < arr[i]){
                int low=0, high = stk.size(), idx = -1;
                while(low <= high){
                    int  mid = (low+high)/2;
                    if( stk[mid].first < arr[i]){
                        idx = stk[mid].second;
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    }
                }
                ans[i] = idx;
                continue;
            }
            ans[i] = -1;
            stk.push_back({arr[i],i});
        }
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends