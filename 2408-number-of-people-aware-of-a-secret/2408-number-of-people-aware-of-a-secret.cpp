class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        std::vector<long long> learn(n + 2, 0);

        long long sharing = 0; 
        long long knowing = 0; 

        learn[1] = 1;         
        knowing = 1;         

        for (int i = 2; i <= n; ++i) {
            if (i - delay >= 1) {
                sharing = (sharing + learn[i - delay]) % MOD;
            }
            if (i - forget >= 1) {
                sharing = (sharing - learn[i - forget] + MOD) % MOD;
                knowing = (knowing - learn[i - forget] + MOD) % MOD;
            }

            learn[i] = sharing;
            knowing = (knowing + learn[i]) % MOD;
        }

        return (int)(knowing % MOD);
    }
};
