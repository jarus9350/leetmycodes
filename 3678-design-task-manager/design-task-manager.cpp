class TaskManager {
public:
    struct Compare {
        bool operator () (const pair<int,int>& a, const pair<int,int>& b) const{
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };

    unordered_map<int,unordered_map<int,int>> userTaskPriority;
    unordered_map<int,int> taskUser;

    set<pair<int,int>, Compare> executionList; //priority, taskId
    TaskManager(vector<vector<int>>& tasks) {
        for (auto t : tasks) {
            auto& user = t[0];
            auto& task = t[1];
            auto& priority = t[2];

            taskUser[task] = user;
            userTaskPriority[user][task] = priority;
            executionList.insert({priority,task});
        }
        
    }
    
    void add(int userId, int taskId, int priority) {
        taskUser[taskId] = userId;
        userTaskPriority[userId][taskId] = priority;
        executionList.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto user = taskUser[taskId];
        auto oldPriority = userTaskPriority[user][taskId];
        userTaskPriority[user][taskId] = newPriority;

        executionList.erase({oldPriority,taskId});
        executionList.insert({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        auto userId = taskUser[taskId];
        auto oldPriority = userTaskPriority[userId][taskId];
        userTaskPriority[userId].erase(taskId);

        taskUser.erase(taskId);
        executionList.erase({oldPriority,taskId});
    }
    
    int execTop() {
        auto it = executionList.begin();
        if (it == executionList.end()) return -1;

        auto taskId = it->second;
        auto userId = taskUser[taskId]; 
        rmv(taskId);

        return userId;
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