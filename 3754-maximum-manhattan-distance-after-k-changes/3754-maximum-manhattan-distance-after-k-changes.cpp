class Solution {
public:
    int maxDistance(string s, int k) {
        int n=0, se=0, w=0, e=0;
            
        int d1=0;
        int d2=0;

        int ans=0;
            
        for(int i=0;i<s.size();i++){
            if(s[i]=='N'){
                n++;
                d1++;
            }
            else if(s[i]=='S'){
                se++;
                d1--;
            }
            
            else if(s[i]=='W'){
                d2++;
                w++;
            }
            else if(s[i]=='E'){
                d2--;
                e++;
            }
            int x=abs(d1);
            int y=abs(d2);

            int dist=x+y;
            int add=k;

            dist+=min(add,min(se,n))+min(add,min(se,n));
            add-=min(add,min(se,n));

            dist+=min(add,min(w,e))+min(add,min(w,e));

            ans=max(ans,dist);
        }
        return ans; 
    }   
};