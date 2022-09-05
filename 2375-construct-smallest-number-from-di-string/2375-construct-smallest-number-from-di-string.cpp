class Solution {
public:
    string smallestNumber(string str) {
        string res; 
    vector<int> s;

    for (int i = 0; i <= str.length(); i++){
        s.push_back(i + 1);
    
        if (i == str.length() || str[i] == 'I'){
            while (!s.empty()){
                res += to_string(s.back());
                s.pop_back();
            }
        }
    } 
    return res;
    }
};