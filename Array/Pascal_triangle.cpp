class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.reserve(numRows);

        for(int rows = 0; rows < numRows; rows++){
            /* We make a vector array with rows+1 number of elements
because 0th row contains 1 element, 1st row contains 2 elements, and so on. Then we initialize all these elements with 1. */
            vector<int> curr(rows+1, 1); 
            
            /* The following loop ensures that the logic is applied only to the appropriate elements and the edge elements are excluded. */
            for(int j = 1; j < rows; j++){
                curr[j] = triangle[rows-1][j] + triangle[rows-1][j-1];
            }
            triangle.push_back(move(curr));
        }                                  
        return triangle;     
    }
};