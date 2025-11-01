class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.erase(beginWord);
        
        if (!wordSet.count(endWord)) return 0;
        if (beginWord == endWord) return 1;

        queue<string> q;
        q.push(beginWord);
        int count = 1;

        while (!q.empty()){
            int size = q.size();

            for (int i = 0; i < size; ++i){
                string s = q.front();
                q.pop();
                string copy = s;

                for (int j = 0; j < copy.size(); ++j){
                    char original = copy[j];

                    for (char c = 'a'; c <= 'z'; ++c){
                        if (c == original) continue;
                        copy[j] = c;

                        if (copy == endWord) return count + 1;

                        if (wordSet.count(copy)){
                            q.push(copy);
                            wordSet.erase(copy);
                        }
                    }
                    
                    copy[j] = original;
                }
            }

            ++count;
        }

        return 0;
    }
};