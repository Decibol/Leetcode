class Solution:
    def isValid(self, s: str) -> bool:
        charSet = {')' : '(', ']' : '[', '}' : '{'}
        st = []
        for i in range(len(s)):
            if s[i] in charSet:
                if not st or st[-1] != charSet[s[i]]:
                    return False
                st.pop()
            else:
                st.append(s[i])

        return not st 