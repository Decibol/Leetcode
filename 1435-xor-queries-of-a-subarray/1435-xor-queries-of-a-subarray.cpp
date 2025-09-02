class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixXOR(arr.size(), 0);
        prefixXOR[0] = arr[0];

        for (int i = 1; i < arr.size(); ++i){
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        }

        vector<int> result;

        for (int i = 0; i < queries.size(); ++i){
            int idxToXOR = queries[i][0] - 1;
        
            int xorResult = idxToXOR > -1 ? prefixXOR[queries[i][1]] ^ prefixXOR[idxToXOR] : prefixXOR[queries[i][1]];

            result.push_back(xorResult);  
        }
        
        for (int num : prefixXOR) cout << num << ' ';

        return result;
    }
};