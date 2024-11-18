class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        if(k == 0){
            for(int i=0;i<code.size();i++){
                ans.push_back(0);
            }
            return ans;
        }
        else{
            int l=0;
            int md = code.size();
            if(k>0){
                for(int i=0;i<code.size();i++){
                    int temp = 0;
                    for(int j=0;j<k;j++){
                        l = (i+j+1)%md;
                        temp += code[l];
                    }
                    ans.push_back(temp);
                }
            }
            else{
                for(int i=0;i<code.size();i++){
                    int temp = 0;
                    for(int j=0;j<-k;j++){
                        l = ((i-j-1)+md)%md;
                        temp += code[l];
                    }
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};