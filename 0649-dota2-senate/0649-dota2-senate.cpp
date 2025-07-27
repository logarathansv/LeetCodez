class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dq;
        queue<int> rq;

        int n = senate.size();

        for(int i=0;i<n;i++){
            char ch = senate[i];
            
            if(ch == 'R') rq.push(i);
            else dq.push(i);
        }

        while(!rq.empty() && !dq.empty()){
            if(rq.front() < dq.front()) rq.push(n++);
            else dq.push(n++);

            rq.pop();dq.pop();
        }

        return rq.empty() ? "Dire" : "Radiant";
    }
};