// #define int long long
const long long MOD = 1e9 + 7;
const long long INF = 2e9;
#define ff first
#define ss second
#define endl "\n"
#define ll long long
#define pii pair<int,int>

class Solution {
public:
vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
	
	int n = nums.size();

	unordered_map<char,int> mp;
	for(int i=0;i<10;i++){
		mp['0'+i] = mapping[i];
	}

	auto val=[&](int x){
		string num = to_string(x);
		string newnum;
		for(char ch:num){
			newnum += to_string(mp[ch]);
		}
		return stoi(newnum);
	};

	vector<pii> vec(n);
	for(int i=0;i<n;i++){
		vec[i].ff = val(nums[i]);
		vec[i].ss = i;
	}
	
	sort(vec.begin(), vec.end());
	
	vector<int> ans;
	for(auto &x:vec)
		ans.push_back(nums[x.second]);

	return ans;
}
};