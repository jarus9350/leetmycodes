class Solution {
public:
    struct compare{
        bool operator()(const pair<int,int> &p1,const pair<int,int> & p2) {
            if (p1.first == p2.first){
                return p1.second > p2.second;
            }
            return p1.first > p2.first;
        }
    };

    long long findScore(vector<int>& nums) {
        int s = nums.size();
        // vector<pair<int,int>> ni;
        set<int> indices;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for (int i = 0 ; i <  nums.size() ; i++){
            // ni.push_back({nums[i],i});
            indices.insert(i);
            pq.push({nums[i],i});
        }



        // sort(ni.begin(),ni.end(),compare());

        // for (auto n: ni){
        //     cout<<n.first<<" "<<n.second<<endl;
        // }

        long long score = 0;

        while (indices.size()){
            auto top = pq.top();
            pq.pop();

            int num = top.first;
            int index = top.second;

            // cout<<num<<" "<<index<<endl;

            if (indices.find(index) == indices.end()){
                continue;
            }

            score += num;
            indices.erase(index);

            if (index - 1 >=0 ){
                indices.erase(index-1);
            }

            if (index + 1 < s){
                indices.erase(index+1);
            }

            // cout<<score<<endl;

        }

        return score;
    }
};