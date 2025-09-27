class Solution {
public:
    void evaluate(int ind, string& num, long long sum, long prev, int& target, string test, vector<string>& ans){
        if(ind > num.size()) return ;
        if(ind == num.size() && sum == target){
            ans.push_back(test);
            return ;
        }

        for(int i=ind;i<num.size();i++){
            if(i!=ind && num[ind] == '0') break;

            string curr = num.substr(ind, i-ind+1);
            long no = stol(curr);
            
            if(ind == 0)
                evaluate(i+1, num, no, no, target, curr, ans);
            else{
                evaluate(i+1, num, sum + no, no, target,  test +"+"+ curr, ans);
                evaluate(i+1, num, sum - no, -no, target, test + "-" + curr, ans);
                evaluate(i+1, num, sum - prev + prev * no, prev*no, target, test + "*" + curr, ans);
            }
        }
        
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        evaluate(0, num, 0LL, 0LL, target, "", ans);

        return ans;
    }
};