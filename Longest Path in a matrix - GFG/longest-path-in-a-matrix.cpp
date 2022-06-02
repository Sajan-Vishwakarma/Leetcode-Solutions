// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        int n=matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        function<int(int,int,int)> dfs=[&](int x,int y,int prev){
            if(x<0 || y <0 || x>=n || y>=m || matrix[x][y] <= prev ) return 0;
            
            
            if(dp[x][y] != -1) return dp[x][y];
            
            int ans = 0;
            ans = max(ans,1 + dfs(x+1,y,matrix[x][y]));
            ans = max(ans,1 + dfs(x-1,y,matrix[x][y]));
            ans = max(ans,1 + dfs(x,y+1,matrix[x][y]));
            ans = max(ans,1 + dfs(x,y-1,matrix[x][y]));
        
            return dp[x][y] = ans;
        };
        
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, dfs(i,j,-1));
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends