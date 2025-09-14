class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string result = "";

        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '('){
                result += '(';
                st.push(result.size() - 1);
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

        if (st.empty()) return result;

        string output = "";
        vector<int> temp;

        while (!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        for (int i = 0; i < result.size(); ++i){
            if (!temp.empty() && i == temp.back()){
                temp.pop_back();
            }
            else {
                output += result[i];
            }
        }
        
        return output;
    }
};