class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;
        int j = 0;
        
        while (j <= n){
            if (j == n || s[j] == ' '){
                if (i < j){
                    string sub = s.substr(i, j - i);
                    st.push(sub);
                }
                
                i = j + 1;
            }

            j++;
        }

        string result = "";

        while (!st.empty()){
            result += st.top();
            st.pop();
            if (!st.empty()) result += " ";
        }

        return result;
    }
};