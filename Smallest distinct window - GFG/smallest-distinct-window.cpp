// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str){
        // Your code goes here   
        int n = str.size();
        map<char,int> distinct, mp;
        
        for(char ch:str) 
            distinct[ch]++;
        
        int i=0,j=0,ans = 1e8;
        while( j<n ){
            if( j < n && mp.size() < distinct.size()) {
                mp[str[j++]]++;
            }   
            if(mp.size() >= distinct.size()){
                while(mp.size() >= distinct.size()){
                    ans = min(ans, j-i);
                    mp[str[i]]--;
                    if(mp[str[i]] == 0){
                        mp.erase(str[i]);
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends