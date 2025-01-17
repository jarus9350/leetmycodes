class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int size = derived.size();

        int rollingStart0 = 0;
        for (int i = 0 ; i < size ; i++) rollingStart0 = derived[i] ^ rollingStart0;

        if (rollingStart0 == 0) return true;

        int rollingStart1 = 1;
        for (int i = 0 ; i < size ; i++) rollingStart1 = derived[i] ^ rollingStart1;

        if (rollingStart1 == 1) return true;

        return false;
    }
};