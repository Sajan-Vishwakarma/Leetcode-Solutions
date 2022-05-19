// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B){
        //code here.
        
        vector<int> mp(1024,0);
        for(char ch:A) mp[ch]++;
        for(char ch:B) mp[ch]--;
        
        for(int cnt:mp) 
            if(cnt != 0) 
                return -1;
        
        int l=A.size()-1;
        int r=B.size()-1;
        
        int count = 0;
        while( l >= 0 && r >= 0){
            if( A[l] == B[r]){
                r--;
            } 
            else{
                count++;
            }
            l--;
        }
        return count;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends