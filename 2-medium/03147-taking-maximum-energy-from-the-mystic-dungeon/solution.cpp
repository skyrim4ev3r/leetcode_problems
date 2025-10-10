class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int max_energy_absorb = INT_MIN;
        int len = energy.size();

        for (int i{0}; i < k; ++i) {
            int sum = 0;

            for (int j{i}; j < len; j += k) {
                if (sum < 0) {
                    sum = 0;
                }
                sum += energy[j];
            }

            max_energy_absorb = max(max_energy_absorb, sum);
        }

        return max_energy_absorb;
    }
};
