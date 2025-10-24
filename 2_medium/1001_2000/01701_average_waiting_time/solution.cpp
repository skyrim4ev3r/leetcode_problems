class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        long long curr_time = 0;
        long long total_waiting = 0;
        int customers_len = customers.size();

        for (auto &customer: customers) {

            long long arrive_time = customer[0];
            long long order_time = customer[1];

            if (arrive_time >= curr_time) {
                total_waiting += order_time;
                curr_time = arrive_time + order_time;
            } else {
                long long waiting_time = curr_time - arrive_time;
                total_waiting +=  waiting_time + order_time;
                curr_time += order_time;
            }
        }

        return (double) total_waiting / customers_len;
    }
};
