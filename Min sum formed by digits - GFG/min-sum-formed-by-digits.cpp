// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n){
        
        sort(arr,arr+n);
        long long int sum = 0, carry = 0, tz = 0;
        for(int i=n-1;i>=0;i-=2){
            int s = arr[i]+carry;
            if(i-1 >= 0) s += arr[i-1];
            carry = s/10;
            s %= 10;
            sum = sum*10 + s;
            if(sum == 0 && s==0){
                tz += 1;
            }
        }
        if(carry) sum = sum*10 + carry;
        
        long long int ans = 0;
        while(sum > 0){
            ans = ans*10 + (sum%10);
            sum /= 10;
        }
        while(tz--) ans *= 10;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends