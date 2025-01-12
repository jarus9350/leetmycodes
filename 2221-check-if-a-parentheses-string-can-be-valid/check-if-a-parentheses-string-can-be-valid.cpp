class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 ) return false;
        stack<int> lockedStack;
        stack<int> unlockedStack;

        for (int i = 0 ; i < s.length() ; i++){
            if (locked[i] == '0'){
                unlockedStack.push(i);
            } else if (s[i] == '('){
                lockedStack.push(i);
            } else {
                if (lockedStack.size()) {
                    lockedStack.pop();
                } else if (unlockedStack.size()){
                    unlockedStack.pop();
                } else {
                    return false;
                }
            }
        }

        while (lockedStack.size() && unlockedStack.size() && lockedStack.top() < unlockedStack.top()) {
            lockedStack.pop();
            unlockedStack.pop();
        }


        if (lockedStack.size()) return false;
        return true;
        
    }
};