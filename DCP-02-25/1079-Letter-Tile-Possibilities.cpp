class Solution {
public:
    void backtrack(unordered_map<char, int>& count, int& res) {
        for (auto& [tile, freq] : count) {
            if (freq > 0) {
                // Choose the tile
                res++;
                count[tile]--;

                // Explore further sequences
                backtrack(count, res);

                // Undo the choice (backtrack)
                count[tile]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        for (char tile : tiles) count[tile]++;

        int res = 0;
        backtrack(count, res);
        return res;
    }
};
