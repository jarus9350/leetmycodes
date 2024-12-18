class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        
        int i = 0 ;
        for (; i < n ; i++){
            int first = prices[i];

            bool found = false;
            for (int j = i + 1 ; j < n ; j++){
                int second = prices[j];
                if (second <= first){
                    ans.push_back(first - second);
                    found = true;
                    break;
                } 
            }

            if (!found) ans.push_back(prices[i]);
        }

        return ans;

    }
};