class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();      // number of rows
        int n = matrix[0].size();   // number of columns
        bool firstRow=false, firstCol = false;

        /* First, find out if the first row or the first column
        of the matrix contain any 0s */
        for(int j = 0; j<n; j++){
            if(matrix[0][j]==0){
                firstRow = true;
                break; // we break because if even one element is 0, the entire row becomes 0 anyway
            }
        }

        for (int i=0; i<m; i++){
            if(matrix[i][0] == 0){
                firstCol = true;
                break; // same logic as mentioned above
            } 
        }

        /* We use the first row and column as markers. Now, iterate through the matrix (without 
        first row and column cuz we did that above) and check which element is 0. Once we find that, 
        we can mark the respective row and column position in the array as 0 */
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set 0s for rows based on the markers in the first column
        for(int i=1; i<m; i++){
            if(matrix[i][0]==0){
                for(int j=1; j<n; j++){
                    matrix[i][j] = 0;
                }
            } 
        }

        // Set 0s for columns based on the markers in the first row
        for(int j=1; j<n; j++){
            if(matrix[0][j]==0){
                for(int i=1; i<m; i++){
                    matrix[i][j] = 0;
                }
            } 
        }

        // Modify the first row if needed
        if(firstRow){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }

        // Modify the first column if needed
        if(firstCol){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};