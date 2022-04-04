class Solution {
public:
	int fun(int p,vector<int> &mp, vector<int> &nums, map<int, map<vector<int>,int>> &dp){

		if(p == nums.size())
			return 0;

		if( dp[p].find(mp) != dp[p].end())
			return dp[p][mp];

		int ans = 0;
		for(int slot=1;slot<mp.size();slot++){
			if(mp[slot] == 0) continue;
			mp[slot]--;
			ans = max(ans, fun(p+1,mp,nums,dp) + (nums[p]&slot));
			mp[slot]++;
		}
		return dp[p][mp] = ans;
	}


    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> mp(numSlots+1);
        for(int i=1;i<=numSlots;i++)
        	mp[i]+=2;

        map<int,map<vector<int>,int>> dp; 
        int ans = fun(0,mp,nums,dp);
        return ans;
    }
};