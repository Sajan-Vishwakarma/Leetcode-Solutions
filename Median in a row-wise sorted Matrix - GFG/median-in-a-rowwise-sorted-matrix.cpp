// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int Count(int mid,int r,int c,vector<vector<int>> &matrix)
    {
       int cnt=0;
       for(int i=0;i<r;i++)
       {
           cnt+=lower_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
       }
       return cnt;
   }
   
    int median(vector<vector<int>> &mat, int n, int m){
            // getting min and max value present in matrix;
    
    int low = 1, high = 2000;    
    while( low < high ){
        int mid = low + (high-low)/2;

        int countsmall = 0;
        for( int i=0;i<n;i++){
            countsmall += upper_bound(mat[i].begin(), mat[i].end(),mid) - mat[i].begin();
        }

        if( countsmall < ((n*m)+1)/2 ){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends