struct info {
    int index;
    int score;
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        vector<info> players(score.size());

        for (int i{0}; i < score.size(); ++i) {
            players[i].index = i;
            players[i].score = score[i];
        }

        sort(players.begin(), players.end(), [](info &a, info &b){
            return a.score > b.score;
        });

        vector<string> res(score.size(), "");

        for (int i{0}; i < std::min(3, (int)score.size()); ++i) {
            if (i == 0) res[players[i].index] = "Gold Medal";
            else if (i == 1) res[players[i].index] = "Silver Medal";
            else if (i == 2) res[players[i].index] = "Bronze Medal";
        }

        for (int i{3}; i < score.size(); ++i) {
            res[players[i].index] = std::to_string(i + 1);
        }

        return res;
    }
};
