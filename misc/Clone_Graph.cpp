/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node) return NULL;
        
        unordered_map<int, Node*> m;
        
        unordered_set<int> vis;
        queue<Node*> q;
        
        q.push(node);
        
        //bfs
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            vis.insert(top->val);
            for(auto x: top->neighbors){
                if(vis.find(x->val) == vis.end()) q.push(x);
            }
        }
        
        for(auto it: vis){
            m[it] = new Node(it);
        }
        
        //q.clear();
        vis.clear();
        
        
        q.push(node);
        vis.insert(node->val);
        
        //bfs
        while(!q.empty()){
            Node* top = q.front();
            for(auto x: top->neighbors) m[top->val]->neighbors.push_back(m[x->val]);
            q.pop();
            for(auto x: top->neighbors){
                if(vis.find(x->val) == vis.end()){q.push(x); vis.insert(x->val);}
            }
        }
        
        
        return m[node->val];
        
        
    }
};