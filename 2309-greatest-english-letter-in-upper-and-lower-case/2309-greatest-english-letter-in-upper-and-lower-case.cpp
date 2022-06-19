class Solution {
public:
    string greatestLetter(string s) {
        
       vector<bool> small(27,false), capital(27,false);
        for(char ch:s){
            if(ch <='z' && ch >='a'){
                small[ch-'a'] = true;
            }
            else{
                capital[ch-'A'] = true;
            }
        }
        
        for(int i=25;i>=0;i--){
            // cout<<small[i]<<" "<<capital[i]<<endl;
            if(small[i] && capital[i]){
                string ans = "";
                ans += ('A'+i);
                return ans;
            }
                // return "" + to_string('A'+i);
        }
        
        return "";
    }
};