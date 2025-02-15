class Solution {
public:
    bool check(string num, int target){
        if(target == 0 && num == "") return true;

        if(target<0) return false;

        for(int i=0;i<num.size();i++){
            string l = num.substr(0, i+1);
            string r = num.substr(i+1);
            if(check(r, target - stoi(l))) return true;
        }

        return false;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            if(check(to_string(i*i), i)){
                sum += i*i;
            }
        }
        return sum + 1;
    }
};
