class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string result = "";
        int i = 0;

        for (int j = 0; j <= s.size(); ++j){
            if (j == s.size() || s[j] == ' '){
                if (i < j){
                    string sub = s.substr(i, j - i);
                    st.push(sub);
                }
                
                i = j + 1;
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
            if (!st.empty()) result += " ";
        }

        return result;
    }
};