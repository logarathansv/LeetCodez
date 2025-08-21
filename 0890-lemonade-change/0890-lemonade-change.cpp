class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ct5=0;
        int ct10 = 0;
        for(auto bill : bills){
            if(bill == 5){
                ct5++;
            }
            else if(bill == 10){
                if(ct5>0)    
                    ct5--;
                else return false;
                ct10++;
            }
            else if(bill == 20){
                if(ct10>0){
                    ct10--;
                }
                else if(ct5>1){
                    ct5 = ct5-2;
                }
                else return false;
                if(ct5>0) ct5--;
                else return false;
            }
        }
        return true;
    }
};