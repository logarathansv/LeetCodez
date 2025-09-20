class Node{
public:
    Node *links[26];
    bool flag;
    Node(){
        flag = false;
        for(int i=0; i<26; ++i) {
            links[i] = nullptr;
        }
    }
    void put(char ch, Node* nd){
        links[ch - 'a'] = nd;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    bool containsKey(char ch){
        return (links[ch - 'a'] != nullptr);
    }
    void setBool(){
        flag = true;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *nd = root;
        for(char ch:word){
            if(!nd->containsKey(ch)){
                nd->put(ch, new Node());
            }
            nd = nd->get(ch);
        }
        nd->setBool();
    }
    
    bool search(string word) {
        Node* nd = root;

        for(auto ch:word){
            if(!nd->containsKey(ch)) return false;
            nd = nd->get(ch);
        }

        return nd->flag;
    }
    
    bool startsWith(string prefix) {
        Node* nd = root;

        for(auto ch:prefix){
            if(!nd->containsKey(ch)) return false;
            nd = nd->get(ch);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */