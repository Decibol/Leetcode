class Solution {
public:
    void backtrack(int open, int close, int n, string s, vector<string>& result){
        if (open == close && open == n){
            result.push_back(s);
            return;
        }

        if (open < n){
            backtrack(open + 1, close, n, s + "(", result);
        }

        if (close < open){
            backtrack(open, close + 1, n, s + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        int open = 0;
        int close = 0;

        backtrack(open, close, n, s, result);

        return result;
    }
};