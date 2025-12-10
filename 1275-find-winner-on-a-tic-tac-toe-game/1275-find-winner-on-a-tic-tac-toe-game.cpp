class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int i = moves.size() - 1;
        int row = moves[i][0];
        int col = moves[i][1];
        int r = 2;
        int c = 2;
        int d = 3 - static_cast<int>(row == col);
        int ad = 3 - static_cast<int>(row + col == 2);
        for(i = i - 2; i >= 0; i -= 2){
            r -= static_cast<int>(moves[i][0] == row);
            c -= static_cast<int>(moves[i][1] == col);
            d -= static_cast<int>(moves[i][0] == moves[i][1]);
            ad -= static_cast<int>(moves[i][0] + moves[i][1] == 2);
            if (!(r && c && d && ad)){
                return moves.size() % 2 == 1 ? "A" : "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }

};