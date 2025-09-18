class TaskManager {
public:
    struct Compare {
        bool operator () (const pair<int,int>& a, const pair<int,int>& b) const{
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };

    unordered_map<int,pair<int,int>> taskUserPriority;

    set<pair<int,int>, Compare> executionList; //priority, taskId
    TaskManager(vector<vector<int>>& tasks) {
        for (auto t : tasks) {
            auto& user = t[0];
            auto& task = t[1];
            auto& priority = t[2];

            taskUserPriority[task] = {user,priority};
            executionList.insert({priority,task});
        }
        
    }
    
    void add(int userId, int taskId, int priority) {
        taskUserPriority[taskId]= {userId,priority};
        executionList.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [user, priority] = taskUserPriority[taskId];

        taskUserPriority.erase(taskId);
        taskUserPriority[taskId] = {user,newPriority};
        executionList.erase({priority ,taskId});
        executionList.insert({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        auto [user, priority] = taskUserPriority[taskId];
        taskUserPriority.erase(taskId);
        executionList.erase({priority,taskId});
    }
    
    int execTop() {
        auto it = executionList.begin();
        if (it == executionList.end()) return -1;

        auto taskId = it->second;
        auto [user, priority] = taskUserPriority[taskId];
        rmv(taskId);

        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */