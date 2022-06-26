// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define sz(x) (int)(x).size()

class Solution
{
public:

    int countDistinctSubarray(int arr[], int n){

        int unique;
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        unique = mp.size();
        mp.clear();
    
        int i = 0, j = 0;
    
        for(  ; j < n ; j++){
            mp[arr[j]]++;
            if(sz(mp) == unique)
                break;
        }
    
        int ans = 0;
        while( j < n && sz(mp) >= unique){
    
            // count subarrays
            ans += n-j; 
    
            // erase first element
            if( --mp[arr[i]] == 0){
                mp.erase(mp.find(arr[i]));
            }
            i++;
    
            if( mp.size() == unique)
                continue;
            for( ++j; j < n; j++){
                mp[arr[j]]++;
                if(sz(mp) == unique)
                    break;
            }
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends