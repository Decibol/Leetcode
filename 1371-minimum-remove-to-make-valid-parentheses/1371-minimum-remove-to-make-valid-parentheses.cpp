class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string result = "";

        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '('){
                result += '(';
                st.push(s[i]);
            } 
            else if (s[i] == ')'){
                if (st.empty()) continue;

                result += ')';
                st.pop();
            }
            else {
                result += s[i];
            }
        }

        while (!st.empty()){
            int idx = result.find_last_of('(');
            result.erase(idx, 1);
            
            st.pop();
        }
        
        return result;
    }
};