class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought_stock_price = INT_MAX;
        int max_profit = 0; // not gonna sell for loss

        for(auto stock_price : prices)
        {
            bought_stock_price = min(stock_price, bought_stock_price);
            int that_day_profit = stock_price - bought_stock_price;
            max_profit = max(that_day_profit, max_profit);
        }

        return max_profit;
        /*
        Time: O(n)
        Space: O(1)
        */
    }
};