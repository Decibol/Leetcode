class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        result += num[0];

        int maxInteger = -1;

        for (int i = 1; i < num.size(); ++i){
            if (num[i] == num[i - 1]){
                result += num[i];
            }
            else{
                result = num[i];
            }

            if (result.size() == 3){
                int integer = stoi(result);
                maxInteger = max(maxInteger, integer);
            }
        }

        if (maxInteger == 0){
            return "000";
        }

        if (maxInteger == -1){
            return "";
        }

        return to_string(maxInteger);
    }
};