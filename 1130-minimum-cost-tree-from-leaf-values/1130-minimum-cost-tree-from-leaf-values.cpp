class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> maximum(n,vector<int>(n));
        vector<vector<int>> product(n,vector<int>(n,1e5));

        int sum = 0;
        for(int i=0;i<n;i++){
            maximum[i][i] = product[i][i] = arr[i];
            sum += arr[i];
        }

        for(int len=2;len<=n;len++){
            for(int i=0;i<n;i++){
                int j = i+len-1;
                if(j >= n) break;

                for(int k=i;k<j;k++){
                    maximum[i][j] = max({maximum[i][j],maximum[i][k],maximum[k+1][j]});
                }
                for(int k=i;k<j;k++){
                    product[i][j] = min(product[i][j],maximum[i][k]*maximum[k+1][j]+product[i][k]+product[k+1][j]);
                }
            }
        }
        return product[0][n-1] - sum;
    }

};