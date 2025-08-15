class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ct, ans;
    StockSpanner() {
        ct = 0;
        ans = 0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        if(st.empty()){
            ans = ct+1;
        } else {
            ans = ct - st.top().second;
        }

        st.push({price, ct++});

        return ans; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */