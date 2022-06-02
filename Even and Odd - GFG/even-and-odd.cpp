// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

bool odd(int num){
    return num%2;
}
bool even(int num){
    return num%2==0;
}

class Solution {
  public:
    void reArrange(int arr[], int N) {
        // code here
        int evenidx= 0, oddidx = 1;
        while(true){
            
            if( evenidx < N && arr[evenidx]%2 == 0) evenidx +=2;
            if( oddidx < N && arr[oddidx]%2 == 1) oddidx += 2;
            
            if( evenidx < N && oddidx < N)
                swap(arr[evenidx],arr[oddidx]);
            else
                break;
        }
    }
};

// { Driver Code Starts.

int check(int arr[], int n)
{
    int flag = 1;
    int c=0, d=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(arr[i]%2)
            {
                flag = 0;
                break;
            }
            else
                c++;
        }
        else
        {
            if(arr[i]%2==0)
            {
                flag = 0;
                break;
            }
            else
                d++;
        }
    }
    if(c!=d)
        flag = 0;
        
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        ob.reArrange(arr,N);
        
        cout<<check(arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends