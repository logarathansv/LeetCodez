class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = "";
        vector<int> preind; 
        vector<char> presym;

        preind.push_back(-1);
        presym.push_back('L');

        int n = dominoes.size();

        for(int i=0;i<n;i++){
            if(dominoes[i] != '.'){
                preind.push_back(i);
                presym.push_back(dominoes[i]);
            }
        }

        preind.push_back(n);
        presym.push_back('R');

        int m = preind.size();

        for(int i=0;i<m-1;i++){
            int stind = preind[i], edind = preind[i+1];
            char stsym = presym[i], edsym = presym[i+1];
            if(stsym == edsym){
                for(int j = stind+1;j<edind;j++){
                    dominoes[j] = stsym;
                }
            }
            else if(stsym > edsym){
                for(int j = stind+1;j<edind;j++){
                    dominoes[j] = (j - stind == edind - j) ? '.' : (j - stind > edind - j) ? 'L' : 'R';
                }
            }
        }
        
        return dominoes;
    }
};