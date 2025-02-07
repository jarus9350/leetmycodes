class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        
        unordered_map<int,int> colorFreq, posColor;

        for (auto q: queries){
            int pos = q[0];
            int color = q[1];

            if (posColor.find(pos) != posColor.end()){
                int oldColor = posColor[pos];
                colorFreq[oldColor]--;
                if (colorFreq[oldColor] == 0){
                    colorFreq.erase(oldColor);
                }
            }
    
            posColor[pos] = color;
            colorFreq[color]++;
        
            ans.push_back(colorFreq.size());
        }

        return ans;
        
    }
};