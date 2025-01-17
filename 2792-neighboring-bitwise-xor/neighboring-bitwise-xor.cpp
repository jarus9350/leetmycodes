class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int size = derived.size();

        int rollingStart0 = 0;
        for (int i = 0 ; i < size ; i++){
            int d = derived[i];
            int xorVal = d ^ rollingStart0;
            rollingStart0 = xorVal;
        }

        if (rollingStart0 == 0) return true;

        int rollingStart1 = 1;
        for (int i = 0 ; i < size ; i++){
            int d = derived[i];
            int xorVal = d ^ rollingStart1;
            rollingStart1 = xorVal;
        }

        if (rollingStart1 == 1) return true;

        return false;
    }
};