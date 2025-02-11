class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            size_t part_ind = s.find(part);
            s = s.substr(0, part_ind) + s.substr(part_ind+part.length());
        }
        return s;
    }
};