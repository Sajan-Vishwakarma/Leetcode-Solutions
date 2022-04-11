class Solution {
public:

    int eval(string &s){
        int pos1 = 0, pos2 = 0, pos3 =0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == '(') pos1 = i;
            else if(ch == '+') pos2 = i;
            else if(ch == ')') pos3 = i;
        }

        int first =0, second =0, third =0, fourth = 0;
        for(int i=0;i<pos1;i++){
            first *= 10;
            first += s[i]-'0';
        }
        for(int i=pos1+1;i<pos2;i++){
            second *= 10;
            second += s[i]-'0';
        }
        for(int i=pos2+1;i<pos3;i++){
            third *= 10;
            third += s[i]-'0';
        }
        for(int i=pos3+1;i<s.size();i++){
            fourth *= 10;
            fourth += s[i]-'0';
        }
        int ans = 0;
        if( first == 0 && fourth == 0)
            ans = second+third;
        else if(first == 0){
            ans = (second+third)*fourth;
        }
        else if(fourth == 0){
            ans = first*(second+third);
        }
        else
            ans = first*(second+third)*fourth;
        return ans;
    }

    string minimizeResult(string expression) {

        int i = 0, j = 0, n = expression.size();
        for(int p=0;p<expression.size();p++){
            if(expression[p] == '+'){
                i = p-1;
                j = p+1;
                break;
            }
        }
        int leftsize = i+1, rightsize = n - j;
        int ans = 1e9;
        string finalans = "";
        for(int i=leftsize-1;i>=0;i--){
            for(int p=1;p<=rightsize;p++){
                string temp = expression;
                temp.insert(temp.begin()+i,'(');
                temp.insert(temp.begin()+leftsize+p+2,')');
                int res = eval(temp);
                if(res < ans){
                    ans = res;
                    finalans = temp;
                }
            }
        }

        return finalans;
    }
};