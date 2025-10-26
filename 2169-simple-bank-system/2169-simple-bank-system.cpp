class Bank {
public:
    unordered_map<int, long long> accounts;

    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); ++i){
            accounts[i + 1] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (accounts.find(account1) == accounts.end() || accounts.find(account2) == accounts.end() || accounts[account1] < money) return false;

        accounts[account1] -= money;
        accounts[account2] += money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        if (accounts.find(account) == accounts.end()) return false;

        accounts[account] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (accounts.find(account) == accounts.end() || accounts[account] < money) return false;

        accounts[account] -= money;

        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */