class Solution {
public:
    int findClosest(int x, int y, int z) {
        int x_distance = abs(x - z);
        int y_distance = abs(y - z);

        if (x_distance == y_distance){
            return 0;
        }

        return x_distance > y_distance ? 2 : 1;
    }
};