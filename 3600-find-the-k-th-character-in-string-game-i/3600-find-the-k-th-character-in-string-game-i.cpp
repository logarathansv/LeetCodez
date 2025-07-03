class Solution {
public:
    char kthCharacter(int k) {
        char w = 'a';
        string str="a";
        for(int i=0;str.size()<k;i++){
            int j=0;
            string t="";
            while(j<str.size()){
                t += (str[j]+1)%122;
                cout<<t;
                j++;
            }
            str += t;
        }
        return str[k-1];
    }
};