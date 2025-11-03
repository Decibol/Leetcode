class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string str : tokens) {
            if (str != "+" && str != "-" && str != "*" && str != "/") {
                st.push(stoi(str));
            } else {
                int operand2 = st.top(); st.pop();
                int operand1 = st.top(); st.pop();
                int result = 0;

                if (str == "+") {
                    result = operand1 + operand2;
                } else if (str == "-") {
                    result = operand1 - operand2;
                } else if (str == "*") {
                    result = operand1 * operand2;
                } else if (str == "/") {
                    result = operand1 / operand2;
                }

                st.push(result);
            }
        }

        return st.top();
    }
};
