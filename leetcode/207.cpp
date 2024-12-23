/*
207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // convert to adjList
        unordered_map<int,vector<int>> adjList;
        vector<int> visited(numCourses);

        for(auto vec:prerequisites){
            adjList[vec[0]].push_back(vec[1]);
        }


        // start from a node and check for cyclic 
        // if cyclic then return false
        // else we're good to go

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(__cyclic__(adjList,visited,i))
                    return false;
            }
        }
        return true;

    }

    // cyclic check
    // 0: not been explored
    // 1: in state of exploration
    // 2: this and connected nodes are explored

    bool __cyclic__(unordered_map<int,vector<int>> &adjList,vector<int> &visited, int node){
        visited[node]=1;

        for(int current:adjList[node]){
            if(visited[current]==1){
                return true;
            }
            if(!visited[current]){
                if(__cyclic__(adjList,visited,current)){
                    return true;
                }
            }
        }
        visited[node]=2;
        return false;

    }
};