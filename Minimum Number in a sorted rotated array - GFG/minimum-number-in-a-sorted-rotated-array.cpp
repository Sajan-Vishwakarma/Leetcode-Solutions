// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high){
        // Your code here
        if( arr[high] > arr[low]){ // no rotation
            return arr[low];
        }
        
        int idx = -1;
        while(low <= high){
            int mid = (low+high)/2;
            
            // cout<<low<<" "<<high<<" "<<mid<<endl;
            if( arr[mid] < arr[0]){
                idx = mid;
                high = mid-1;
            }
            else if(arr[mid] > arr[0]){
                low = mid+1;
            }
            else
                break;
        }
        return arr[idx];
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
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends