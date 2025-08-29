class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_map<int,vector<int>> mp;
        int cnt = 0;
        int v=0,c=0; 

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') v++;
            else        c++;

            if(v==c && (v*c)%k==0) cnt++; 
            auto it=mp.find(v-c);
            if(it!=mp.end())   
            {
                vector<int> vec=it->second;
                for(auto ind:vec)
                {
                    int num = (i-ind+1)/2;
                    if((num*num)%k==0)  cnt++;
                }
            }
            mp[v-c].push_back(i);

        }            
        return cnt;
    }
};