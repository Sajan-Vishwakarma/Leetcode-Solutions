class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        long long sum = 0;
        for(int &i:beans){
        	sum += i;
        }

        sort(beans.begin(), beans.end());
        long long ans = 1e15, smaller = 0, n = beans.size();
        for(int i=0;i<n;i++){
        	ans = min(ans, sum-(n-i)*beans[i] + smaller);
        	smaller += beans[i];
        	sum -= beans[i];
        }

        return ans;
    }	
};