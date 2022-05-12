class ATM {
public:
    
    vector<long long> banknotes{500,200,100,50,20};
    map<int,long long> bank;
    
    ATM() {
        bank[500] = 0;    
        bank[200] = 0;    
        bank[100] = 0;    
        bank[50] = 0;    
        bank[20] = 0;    
    }
    
    void deposit(vector<int> banknotesCount) {
        bank[500] += banknotesCount[4];   
        bank[200] += banknotesCount[3];   
        bank[100] += banknotesCount[2];   
        bank[50] += banknotesCount[1];   
        bank[20] += banknotesCount[0];   
    }
    
    bool possible(int amount){
        // cout<<amount<<" \n";
        for(long long money:banknotes){
            long long notes = amount/money;
            int mn = min(notes,bank[money]);
            amount -= money*mn;            
            // cout<<amount<<" "<<money<<" "<<notes<<":\n";
        }
        return amount == 0;
    }
    
    vector<int> getnotes(int amount){
        vector<int> ans(5,0);
        // cout<<amount<<" \n";
        for(long long money:banknotes){
            long long notes = amount/money;
            long long mn = min(notes,bank[money]);
            amount -= money*mn;
            bank[money] -= mn;
            // cout<<amount<<" "<<money<<" "<<notes<<":\n";
            if(money == 500) ans[4] += mn;
            if(money == 200) ans[3] += mn;
            if(money == 100) ans[2] += mn;
            if(money == 50) ans[1] += mn;
            if(money == 20) ans[0] += mn;
        }
        return ans;
    }
    
    vector<int> withdraw(int amount) {
        if( possible(amount)){
            return getnotes(amount);
        }
        return vector<int>{-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */