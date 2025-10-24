class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int rains_len = rains.size();

        unordered_map<int, int> map_lake_to_last_rainy_day;
        set<int> none_rainy_days;

        vector<int> res{};
        res.reserve(rains_len);

        for (int day{0}; day < rains_len; ++day) {
            if (rains[day] == 0) {
                res.push_back(1);
                none_rainy_days.insert(day);
            } else {
                res.push_back(-1);
                int lake = rains[day];
                auto lakes_it = map_lake_to_last_rainy_day.find(lake);
                if (lakes_it == map_lake_to_last_rainy_day.end()) {
                    map_lake_to_last_rainy_day[lake] =  day;
                } else  {
                    int last_rainy_day_on_this_lake = lakes_it->second;

                    auto avaiable_none_rainy_day_iterator = none_rainy_days.lower_bound(last_rainy_day_on_this_lake);

                    if (avaiable_none_rainy_day_iterator == none_rainy_days.end()) {
                        return vector<int> {};
                    }

                    int avaiable_none_rainy_day = *avaiable_none_rainy_day_iterator;

                    res[avaiable_none_rainy_day] = lake;
                    none_rainy_days.erase(avaiable_none_rainy_day_iterator);

                    lakes_it->second = day;
                }
            }
        }

        return res;
    }
};
