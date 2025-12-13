class Solution {
public:
    bool isValidCode(string s){
        return all_of(s.begin(), s.end(), [](unsigned char c){
            return isalnum(c) || c == '_'; 
        });
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        set<string> category = {"electronics", "grocery", "pharmacy", "restaurant"};
        vector<pair<string, string>> result;

        for (int i = 0; i < code.size(); ++i){
            if (!code[i].empty() && !businessLine[i].empty() && isValidCode(code[i]) && category.count(businessLine[i]) && isActive[i]){
                result.push_back({businessLine[i], code[i]});
            }
        }

        sort(result.begin(), result.end());
        vector<string> ans;

        for (int i = 0; i < result.size(); ++i){
            ans.push_back(result[i].second);    
        }

        return ans;
    }
};