class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int collisions = 0;

        for (int i = 0; i < directions.size(); ++i){
            if (directions[i] == 'S'){
                while (!st.empty()){
                    if (st.top() == 'R') ++collisions;

                    st.pop();
                }

                st.push('S');
            }
            else if (directions[i] == 'L'){
                if (!st.empty()){
                    if (st.top() == 'R'){
                        collisions += 2;
                        st.pop();
                    }
                    else if (st.top() == 'S'){
                        collisions += 1;
                    }

                    while (!st.empty()){
                        if (st.top() == 'R') ++collisions;

                        st.pop();
                    }

                    st.push('S');
                }
            }

            else {
                st.push('R');
            }
        }

        return collisions;
    }
};