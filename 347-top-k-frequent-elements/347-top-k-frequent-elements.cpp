class Solution {
public:
    
    int partition(int l,int r,vector<int> &nums,int k, map<int,int> &freq){
        int swapindex = l, pivotelement = nums[l];
        swap(nums[l],nums[r]);
        for(int i=l; i <= r; i++){
            if( freq[nums[i]] > freq[pivotelement]){
                swap(nums[i],nums[swapindex]);
                swapindex++;
            }
        }
        swap(nums[swapindex],nums[r]);
        return swapindex;
    }
    
    void quickselect(vector<int> &nums,int k, map<int,int> &freq){
        
        int low = 0, high = nums.size()-1;
        while( low < high){
            int p = partition(low,high,nums,k,freq);
            if( p == k)
                return;
            else if(p < k)
                low = p+1;
            else
                high = p;
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> freq;
        for(int &i:nums) freq[i]++;
        
        vector<int> vec;
        for(auto &x:freq) vec.push_back(x.first);
        quickselect(vec,k,freq);
        
        return vector<int>(vec.begin(),vec.begin()+k);
    }
};