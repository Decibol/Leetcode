class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found_x = false, found_y = false, found_z = false;

        for (auto triplet : triplets){
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                if (triplet[0] == target[0]) found_x = true;
                if (triplet[1] == target[1]) found_y = true;
                if (triplet[2] == target[2]) found_z = true;
            }
        }

        return found_x && found_y && found_z;
    }
};