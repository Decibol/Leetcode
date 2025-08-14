class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> substrings = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

        for (string str : substrings){
            if (num.find(str) != string::npos){
                return str;
            }
        }

        return "";
    }
};