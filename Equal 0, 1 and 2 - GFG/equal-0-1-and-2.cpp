// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        
        map<array<int,3>,int> mp;
        mp[{0,0,0}] = 1;
        
        int ans = 0;
        int c0 = 0, c1 = 0, c2 = 0;
        for(int i=0;i<str.size();i++){
            c0 += str[i] == '0';
            c1 += str[i] == '1';
            c2 += str[i] == '2';
            
            int mn = min({c0,c1,c2});
            int nc0 = c0-mn, nc1 =c1-mn, nc2 = c2-mn;
            ans += mp[{nc0,nc1,nc2}]++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends