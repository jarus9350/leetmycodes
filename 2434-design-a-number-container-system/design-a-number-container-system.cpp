class NumberContainers {
public:
    unordered_map<int,set<int>> numSet;
    unordered_map<int,int> indexNum;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indexNum.find(index) == indexNum.end()){
            indexNum[index] = number;
            numSet[number].insert(index);
        } else {
            int oldNum = indexNum[index];
            indexNum[index] = number;

            numSet[oldNum].erase(index);
            numSet[number].insert(index);
        }
    }
    
    int find(int number) {
        if (numSet[number].size() == 0) return -1;
        return *numSet[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */