class Solution {
private:
    long long inv;
    vector<int> L;
    vector<int> R;
    set<pair<long long, int>> S;

    long long getVal(int i, const vector<long long>& A) {
        return A[i];
    }

    void add(int i, int N, const vector<long long>& A) {
        if (i >= 0 && i < N) {
            int j = R[i];
            if (j < N) {
                S.insert({A[i] + A[j], i});
                if (A[i] > A[j])
                    inv++;
            }
        }
    }

    void remove(int i, int N, const vector<long long>& A) {
        if (i >= 0 && i < N) {
            int j = R[i];
            if (j < N) {
                auto it = S.find({A[i] + A[j], i});
                if (it != S.end()) {
                    if (A[i] > A[j])
                        inv--;
                    S.erase(it);
                }
            }
        }
    }

public:
    int minimumPairRemoval(vector<int>& nums) {
        int N = nums.size();
        if (N < 2) return 0;

        vector<long long> A(nums.begin(), nums.end());

        inv = 0;
        L.assign(N, 0);
        R.assign(N, 0);
        S.clear();

        for (int i = 0; i < N; ++i) {
            L[i] = i - 1;
            R[i] = i + 1;
        }

        for (int i = 0; i < N - 1; ++i) {
            if (A[i] > A[i + 1]) inv++;
            S.insert({A[i] + A[i + 1], i});
        }

        int op = 0;
        while (inv > 0 && !S.empty()) {
            auto it = S.begin();
            int i = it->second;
            S.erase(it);

            int j = R[i];
            int h = L[i];
            int k = R[j];

            remove(h, N, A);
            if (A[i] > A[j]) inv--;
            remove(j, N, A);

            A[i] += A[j]; 
            
            op++;
            R[i] = k;
            if (k < N) L[k] = i;

            add(h, N, A);
            add(i, N, A);
        }

        return op;
    }
};