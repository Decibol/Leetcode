class Solution {
public:
    int strToInt(string s){
        int n = 0;

        for (int i = 0; i < s.size(); ++i){
            n *= 10;
            n += s[i] - '0';
        }

        return n;
    }

    static bool cmp(const vector<string>& a, const vector<string>& b){
        int t1 = stoi(a[1]);
        int t2 = stoi(b[1]);

        if (t1 == t2){
            return a[0] > b[0]; 
        }

        return t1 < t2;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        sort(events.begin(), events.end(), cmp);
        unordered_map<string, int> times;

        for (auto const& e : events){
            if (e[0] == "MESSAGE"){
                if (e[2] == "ALL"){
                    for (int i = 0; i < mentions.size(); ++i){
                        ++mentions[i];
                    }
                }
                else if (e[2] == "HERE"){
                    for (int i = 0; i < numberOfUsers; ++i){
                        string id = "id" + to_string(i);

                        if (times[id] <= stoi(e[1])) {
                            ++mentions[i];
                        }
                    }
                }
                else {
                    int id = -1;
                    int idx = 0;

                    while (idx < e[2].size()){
                        if (e[2][idx] == 'i' || e[2][idx] == 'd'){
                            ++idx;
                            continue;
                        }
                        else {
                            string s = "";

                            while (idx < e[2].size() && e[2][idx] != ' '){
                                s += e[2][idx];
                                ++idx;
                            }

                            if (idx == e[2].size()){
                                int index = strToInt(s);
                                ++mentions[index];
                                break;
                            }
                            
                            int index = strToInt(s);
                            ++mentions[index];
                            ++idx;
                        }
                    }
                }
            }
            else if (e[0] == "OFFLINE"){
                string id = "id" + e[2]; 
                times[id] = stoi(e[1]) + 60;
            }
        }

        return mentions;
    }
};