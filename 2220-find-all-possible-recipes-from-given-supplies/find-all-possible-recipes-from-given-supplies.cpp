class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        //first creat indegree and adjecency list
        int n=recipes.size();
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;
       
        for(int i=0;i<n;i++)
        {
            indegree[recipes[i]]=ingredients[i].size();
            for(auto it: ingredients[i])
            {
                adj[it].push_back(recipes[i]);
            }
        }
        queue<string> q;
        for(auto it: supplies)
        {
            q.push(it);
        }
        vector<string> ans;
        while(!q.empty())
        {
            string supply=q.front();
            q.pop();

            for(auto it:adj[supply])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};