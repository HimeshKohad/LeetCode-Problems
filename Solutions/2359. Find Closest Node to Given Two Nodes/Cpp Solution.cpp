class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>adj[n];
        for(int i = 0; i<n; i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        } 
        unordered_map<int,int>dis1,dis2;
        queue<int>q1,q2;
        vector<bool>v1(n,false), v2(n,false);

        //BFS1
        q1.push(node1);
        v1[node1] = true;
        dis1[node1] = 0;
        while(!q1.empty()){
            int curr = q1.front(); q1.pop();
            for(auto neighbour : adj[curr]){
                if(!v1[neighbour]){
                    dis1[neighbour] = dis1[curr]+1;
                    v1[neighbour] = true;
                    q1.push(neighbour);
                }
            }
        }

        //BFS2
        q2.push(node2);
        v2[node2] = true;
        dis2[node2] = 0;
        while(!q2.empty()){
            int curr = q2.front(); q2.pop();
            for(auto neighbour : adj[curr]){
                if(!v2[neighbour]){
                    dis2[neighbour] = dis2[curr]+1;
                    v2[neighbour] = true;
                    q2.push(neighbour);
                }
            }
        }

        int maxDis = INT_MAX , ans = -1;
        for(auto it : dis1){
            int ele = it.first;
            if(dis2.find(ele) != dis2.end()){
                int currDis = max(dis1[ele], dis2[ele]);
                if(currDis < maxDis){
                    maxDis = currDis;
                    ans = ele;
                }
                else if(currDis == maxDis && ans > ele){
                    ans = ele;
                }
            }
        }
        return ans;

    }
};
