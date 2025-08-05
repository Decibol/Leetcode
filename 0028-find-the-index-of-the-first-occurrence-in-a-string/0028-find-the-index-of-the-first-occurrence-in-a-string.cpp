class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();

        if (needle.size() == 0) return 0;
        int left = 0;

        while (left <= haystack.size()){
            if (needle[0] == haystack[left]){
                string substring = haystack.substr(left, n);

                if (substring == needle){
                    return left;
                }
            }

            left++;
        }

        return -1;
    }
};