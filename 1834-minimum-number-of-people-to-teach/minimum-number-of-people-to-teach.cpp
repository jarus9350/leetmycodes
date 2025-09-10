class Solution {
public:
    set<int> nonComm;
    void hasCommon(vector<vector<int>>& languages,int& p1, int& p2, vector<int>& langVotes){

        for (auto l1: languages[p1-1]){
            for (auto l2 : languages[p2-1]){
                if (l1 == l2) return;
            }
        }

        nonComm.insert(p1);
        nonComm.insert(p2);

        return;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<int> langVotes(n+1,0);
        
        
        for (auto friendship : friendships){
            int f1 = friendship[0];
            int f2 = friendship[1];

            hasCommon(languages, f1, f2, langVotes);
        }
        
        int count = 0;
        for (auto nc : nonComm){
            bool found = false;
            for (auto l: languages[nc - 1]){
                langVotes[l]++;
                count = max(count,langVotes[l]);
            }

        }

        return nonComm.size() - count;



    }
};