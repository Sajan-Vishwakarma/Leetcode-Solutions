class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int ans = 0;
        map<int,int> st;
        int i=0, j =0 , n = fruits.size();
        
        for( ; j < n; j++){
            st[fruits[j]]++;
            while( i <= j && st.size() > 2){
                st[fruits[i]]--;
                if( st[fruits[i]] == 0)
                    st.erase(fruits[i]);
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};