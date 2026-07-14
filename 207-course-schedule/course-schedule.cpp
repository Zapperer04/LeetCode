class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto edge : prerequisites){
            int course = edge[0];
            int prereq = edge[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return count == numCourses;
    }
};