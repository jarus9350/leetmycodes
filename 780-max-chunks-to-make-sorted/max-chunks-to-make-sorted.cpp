class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> newArr;
        newArr = arr;
        sort(newArr.begin(),newArr.end());

        // for (auto a: newArr){
        //     cout<<a<<" ";
        // }
        // cout<<endl;

        int i = 0;
        int j = 0;

        unordered_map<int,int> mp;
        // unordered_map<int,int> mp2;
        int ans = 0;
        int count = 0;
        while (j < arr.size()){
            mp[arr[j]]++;
            mp[newArr[j]]--;

            if (arr[j] == newArr[j]){
                if (!mp[arr[j]]) count++;
            } else {
                if (!mp[arr[j]]) count++;
                if (!mp[newArr[j]]) count++;
            }
            

            if (j - i + 1 == count){
                // cout<<"entered"<<endl;
                ans++;
                count = 0;
                // mp.clear();
                
                // j++;
                i = j + 1;
            }


            j++;
        }

        cout<<ans<<endl;

        return ans;
    }
};