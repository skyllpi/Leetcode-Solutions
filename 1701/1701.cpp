class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int current_time = 0;
        double sum = 0;

        for(int i = 0; i < n; i++) {
            // If the current time is less than the customer's arrival time, update current time to customer's arrival time
            if(current_time < customers[i][0]) {
                current_time = customers[i][0];
            }
            // Calculate the finish time of the current customer
            current_time += customers[i][1];
            // Calculate the waiting time for the current customer and add it to sum
            sum += current_time - customers[i][0];
        }
        return sum / n;
    }
};