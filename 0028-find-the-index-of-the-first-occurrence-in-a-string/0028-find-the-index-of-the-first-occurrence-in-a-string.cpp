class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int left = 0;

        while (left < haystack.size()){
            if (haystack[left] == needle[0]){
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