// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int n){

	
	
	int currscore = 0, sum =0 ;
	for(int i=0;i<n;i++){
	    currscore += A[i]*i; 
	    sum += A[i];
	}
	
	int ans=currscore;
	for(int i=1;i<n;i++){
	    int nextscore = currscore - (sum-A[i-1]) + (n-1)*A[i-1];
	    ans = max(ans, nextscore);
	    currscore = nextscore;
	}
    
    return ans;
}