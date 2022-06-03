// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
    // Code here
    int n = matrix.size(), m = matrix[0].size();
    for(int i=n-2;i >= 0; i--){
        for(int j=0;j<m;j++){
            if( matrix[i][j] == -1) continue;
            int mx = 0;
            if(j-1 >=0 ) mx = max(mx, matrix[i+1][j-1]);
            mx = max(mx, matrix[i+1][j]);
            if(j+1 < m ) mx = max(mx, matrix[i+1][j+1]);
            matrix[i][j] += mx;
        }
    }
    
    return max(0,*max_element(matrix[0].begin(),matrix[0].end()));
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends