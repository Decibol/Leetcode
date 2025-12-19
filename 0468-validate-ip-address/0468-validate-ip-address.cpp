class Solution {
public:
    string validIPAddress(string queryIP) {
        char delimiter;
        int count = 0;

        for (char c : queryIP){
            if (c == '.' || c == ':'){
                delimiter = c;
                ++count;
            }
        }

        vector<string> parts;
        stringstream ss(queryIP);
        string token;

        while (getline(ss, token, delimiter)){
            parts.push_back(token);
        }

        if (delimiter == '.'){
            if (count != 3 || parts.size() != 4) return "Neither";

            for (string str : parts){
                if (str.size() == 0 || str.size() > 3) return "Neither";
                int num = 0;
                
                for (char c : str){
                    if (!isdigit(c)) return "Neither";
                    num *= 10;
                    num += c - '0';
                }

                if ((num > 0 && str[0] == '0') || (num == 0 && str.size() > 1)) return "Neither";
                if (num > 255) return "Neither";
            }

            return "IPv4";
        }
        else {
            if (count != 7 || parts.size() != 8) return "Neither";
            unordered_set<char> allowed = {'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F'};

            for (string str : parts){
                if (str.size() == 0 || str.size() > 4) return "Neither";

                for (char c : str){
                    if (!isdigit(c) && allowed.find(c) == allowed.end()) return "Neither";
                }
            }

            return "IPv6";
        }

        return "Neither";
    }
};