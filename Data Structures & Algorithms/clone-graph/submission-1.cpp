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
    private: Node* visited[101] = {nullptr};
public:
    Node* cloneGraph(Node* node) {

        //if it is null 
        if(node == nullptr) return nullptr;

        // if visited
        if(visited[node->val]!=nullptr)
        return visited[node->val];

        // create a node
        vector<Node*>somthing;
        Node* temp = new Node(node->val , somthing);
        visited[node->val] = temp;
        
        int n = node->neighbors.size();
        
        for (Node* neighbor : node->neighbors) {
            temp->neighbors.push_back(cloneGraph(neighbor));
        }

        return temp;
    }
};
