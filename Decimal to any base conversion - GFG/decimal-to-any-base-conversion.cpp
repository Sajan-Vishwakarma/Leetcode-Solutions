// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    string getNumber(int B, int N)
    {
        // Write Your Code here
        vector<char> vec{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        
        string res ="";
        while( N > 0){
            int rem = N%B;
            N /= B;
            res.push_back(vec[rem]);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int B,N;
        cin>>B>>N;
        Solution ob;
        string ans  = ob.getNumber(B,N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends