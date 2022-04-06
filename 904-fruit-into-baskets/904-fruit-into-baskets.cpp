class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        set<int> st;
        map<int,int> mp;
        int n= fruits.size();
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int j = i;
            while( j < n ){
                st.insert(fruits[j]);
                mp[fruits[j]] = j;
                
                if(st.size() == 3)
                    break;
                j++;
            }
            ans = max(ans,j-i);
            if( st.size() <= 2){
                break;
            }
            
            int next = mp[fruits[i]], next2 = 0, second = 0;            
            for(auto x:st){
                if( x == fruits[i] || x == fruits[j]) continue;
                next2 = mp[x];
                second = x;
            }
            
            if(next2 < next){
                st.erase(second);
                i = next2;
            }
            else{
                st.erase(fruits[i]);
                i = next;
            }
        }
        
        return ans;
    }
};