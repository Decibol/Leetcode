class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int count = 0;

        while (!q.empty() && wordSet.count(endWord)){
            int size = q.size();

            for (int i = 0; i < size; ++i){
                string s = q.front();
                q.pop();
                string copy = s;
                wordSet.erase(s);

                for (char c = 'a'; c <= 'z'; ++c){
                    for (int i = 0; i < copy.size(); ++i){
                        copy[i] = c;

                        if (wordSet.count(copy)){
                            q.push(copy);
                        }
                        
                        copy = s;
                    }
                }
            }

            ++count;
        }

        return wordSet.count(endWord) ? 0 : count;
    }
};