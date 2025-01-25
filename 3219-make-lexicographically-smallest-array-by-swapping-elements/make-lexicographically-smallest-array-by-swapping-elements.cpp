class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());

        unordered_map<int,int> mp;

        vector<queue<int>> v;

        int index = 0;
        queue<int> q;
        for (int i = 0 ; i < n ; i++){
            int num = sorted[i];
            if (q.size() == 0){
                q.push(num);
                mp[num] = index;
            } else {
                if (num - sorted[i-1] <= limit) {
                    q.push(num);
                    mp[num] = index;
                } else {
                    v.push_back(q);
    
                    q = queue<int>();
                    index++;
                    q.push(num);
                    mp[num] = index;
                }
            }
        }

        v.push_back(q);

        vector<int> ans;

        for (auto n : nums){
            int index = mp[n];
            int num = v[index].front();
            v[index].pop();
            ans.push_back(num);
        }

     

        cout<<v.size()<<endl;
        return ans;
        
    }
};