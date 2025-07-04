class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int lastind = 0;
        long long len = 1;

        int ct = 0;

        for(int i=0;i<operations.size();i++){
            len *= 2;

            if(k <= len) {lastind = i;break;}
        }

        for(int i=lastind;i>=0;i--){
            len /= 2;

            if(k > len){
                k -= len;
                if(operations[i] == 1) ct++;
            }
        }

        return (char)('a' + ct%26);
    }
};