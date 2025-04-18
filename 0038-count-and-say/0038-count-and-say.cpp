class Solution {
public:
    string countString(int n, int ct, string str){
        int count = 1;
        string newstr = "";
        while(ct != n-1){
            for(int i=0;i<str.size();i++){
                if(str[i] != str[i+1]){
                    newstr += to_string(count);
                    newstr += str[i];
                    count = 1;
                }
                else{
                    count++;
                }
            }
            str = newstr;
            newstr = "";
            ct++;
        }
        return str;
    }
    string countAndSay(int n) {
        return countString(n, 0, "1");
    }
};