class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> freq;

        for (int x : hand) freq[x]++;

        while (!freq.empty()){
            int start = freq.begin()->first;
            int count = freq.begin()->second;

            for (int i = 0; i < groupSize; ++i){
                int num = start + i;
                if (freq.find(num) == freq.end()) return false;

                freq[num] -= count;

                if (freq[num] < 0) return false;
                if (freq[num] == 0) freq.erase(num);
            }
        }

        return true;
    }
};