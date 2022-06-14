class Solution {
public:
    int nextBeautifulNumber(int n) {
        
        string number = to_string(n);
        vector<int> v{1,2,3,4,5,6,7};
        int ans = 1224444;
        for(int mask=1;mask < (1<<7);mask++){
            string s="";
            for(int i=0;i<v.size();i++){
                if(mask&(1<<i)){
                    int num = v[i];
                    while(num--){
                        s.push_back('0'+v[i]);
                    }
                }
            }
            if(s.size() < number.size() || s.size() > number.size() + 1)
                continue;
            do{
                if( stoi(s) > n)
                    ans = min(ans, stoi(s));
            }while(next_permutation(s.begin(), s.end()));
        }

        return ans;
        // cout<<ans<<endl;
    }
};