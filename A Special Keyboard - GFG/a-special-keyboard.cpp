// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        
        map<char,int> mp;
        for(int i=0;i<S1.size();i++) 
            mp[S1[i]] = i;
            
        int ans=0, curr = 0;
        for(char ch:S2){
            ans += abs(mp[ch]-curr);
            curr = mp[ch];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends