class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size(); 
        vector<pair<int,int>> nNums;
        for (int i = 0 ; i < size; i++){
            nNums.push_back({nums[i],i});
        }

        sort(nNums.begin(),nNums.end());

        for (int i = 0 ; i < size ; i++){
            auto [number, index] = nNums[i];
            int toFind = target - number;

            // cout<<i<<" i "<<toFind<<" tofind"<<endl;

            int l = i + 1;
            int h = size - 1;

            while (l <= h){
                int mid = (l + h)/2;

                if (nNums[mid].first < toFind){
                    l = mid + 1;
                } else if (nNums[mid].first > toFind){
                    h = mid - 1;
                } else if (nNums[mid].first == toFind){
                    return {index,nNums[mid].second};
                }
            }
        }

        return {};
    }

};