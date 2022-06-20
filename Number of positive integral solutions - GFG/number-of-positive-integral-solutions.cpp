// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
#include<bits/stdc++.h>
class Solution{
public:
    
    long dp[26][11];
    
    int fun(int target,int varused){
        
        if(target == 0 && varused == 0) return 1;
        if(target <= 0 || varused <= 0) return 0;
        
        if(dp[target][varused] != -1)
            return dp[target][varused];
        
        long combination = 0;
        for(int candidate=1;candidate<=target;candidate++){
            combination += fun(target-candidate,varused-1);
        }
        return dp[target][varused] = combination;
    }

    long posIntSol(string s){
        
        int var = 0, t = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]<='z' && s[i] >='a') var++;
            if(s[i] == '='){
                t = stoi(s.substr(i+1));
                break;
            }
        }
        // cout<<var<<" "<<t<<endl;
        memset(dp,-1,sizeof(dp));
        return fun(t,var);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends