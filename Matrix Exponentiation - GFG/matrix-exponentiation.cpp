// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int mod = 1e9 + 7;
   vector<vector<vector<long long>>> exponents;
   
   vector<vector<long long>> multiply(vector<vector<long long>> matrix1, vector<vector<long long>> matrix2) {
    vector<vector<long long>> result(matrix1[0].size(), vector<long long>(matrix2.size()));
    for (int i = 0; i < matrix1.size(); i++) {
     for (int j = 0; j < matrix2[0].size(); j++) {
      for (int k = 0; k < matrix1[i].size(); k++) {
       result[i][j] += (matrix1[i][k] * matrix2[k][j]) % mod;
      }
     }
    }
    return result;
   }
   
   vector<vector<long long>> binaryExponentiation(long long n) {
    vector<vector<long long>> result = {{1, 0}, {0, 1}};
    for (int i = 31; i >= 0; i--) {
     if ((n & (1 << i)) != 0) {
      result = multiply(result, exponents[i]);
     }
    }
    return result;
   }
   
   vector<vector<long long>> square(vector<vector<long long>> matrix) {
    return multiply(matrix, matrix);
   }
   
   long long fib(long long n) {
    if (n == 0 || n == 1) {
     return 1;
    } else {
     vector<vector<long long>> matrix = binaryExponentiation(n - 1);
     return (matrix[0][0] + matrix[0][1]) % mod;
    }
   }


   int FindNthTerm(long long int n) {
       // Code here
       exponents.resize(64, vector<vector<long long>>(2,vector<long long>(2)));
       exponents[0] = {{1, 1}, {1, 0}};
    for (int i = 1; i < exponents.size(); i++) {
     exponents[i] = square(exponents[i - 1]);
    }
   
   return fib(n) % mod;
   }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends