class Solution {
public:
    unordered_map<string, bool> possiblecook;
    unordered_map<string, int> mp;
    bool dfs(vector<string>& recipes, vector<vector<string>>& ingredients, string recipe){
        if(possiblecook.find(recipe) != possiblecook.end()) return possiblecook[recipe];
        if(!mp.count(recipe)) return false;

        possiblecook[recipe] = false;

        for(auto ingre : ingredients[mp[recipe]]){
            if(!dfs(recipes, ingredients, ingre)) return false;
        }

        possiblecook[recipe] = true;

        return possiblecook[recipe];
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;

        for(auto supply:supplies)    possiblecook[supply] = true;
        for(int i=0;i<recipes.size();i++)   mp[recipes[i]] = i;

        for(auto recipe:recipes){
            if(dfs(recipes, ingredients, recipe)) ans.push_back(recipe);
        }

        return ans;
    }
};