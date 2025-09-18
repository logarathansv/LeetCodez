class TaskManager {
    priority_queue<pair<int, int>> tasks;
    unordered_map<int, int> tp;
    unordered_map<int, int> to;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        tasks.push({priority, taskId});
        tp[taskId] = priority;
        to[taskId] = userId;
    }

    void edit(int taskId, int newPriority) {
        tasks.push({newPriority, taskId});
        tp[taskId] = newPriority;
    }

    void rmv(int taskId) { tp[taskId] = -1; }

    int execTop() {
        while (!tasks.empty()) {
            const auto task = tasks.top();
            tasks.pop();
            if (task.first == tp[task.second]) {
                tp[task.second] = -1;
                return to[task.second];
            }
        }
        return -1;
    }
};