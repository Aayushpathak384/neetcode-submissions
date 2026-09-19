class Solution {
    private:
    bool dfs(int child ,int parent, vector<vector<int>>adj , vector<bool>&visited  ){

        visited[child] = true;
        

        int n = adj[child].size();
        

        for(int i = 0 ; i< n;  i++){
            int x = adj[child][i];

            if(!visited[x]){
                if(!dfs(x , child , adj , visited)) return false;
            }
            else{
                
            if(x != parent) return false;


            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);//fix adj;
        
        vector<bool>visited(n , false);

        //make adj list for dfs
            for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        //call dfs
        bool cycleres = dfs( 0 , - 1 , adj , visited );
        if(cycleres == false) return false;

       
        for(int i = 0; i< n; i++){
            if(visited[i]== false) return false;
        }
        
        return true;
        
    }
};
