class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> combinations;
        function<void(int,vector<int>&)> fun=[&](int target,vector<int> &temp){
            
            if(target == 0 && temp.size()==k){
                combinations.push_back(temp);
                return;
            }
            
            if(target <=0 || temp.size() > k)
                return;
            
            int start = 1;
            if(!temp.empty()) start = temp.back()+1;
            for(int candidate=start;candidate<=9;candidate++){
                if(candidate > target) break;
                temp.push_back(candidate);
                fun(target-candidate,temp);
                temp.pop_back();
            }
        };
        
        vector<int> temp;
        fun(n,temp);
        
        return combinations;
    }
};