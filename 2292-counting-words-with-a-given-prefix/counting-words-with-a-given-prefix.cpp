class TrieNode {
    public: 

    vector<TrieNode*> children;
    int times;
    bool end;


    TrieNode (){
        children.resize(26,nullptr);
        times = 0;
        end = false;
    }
};

struct Trie {
    TrieNode* children[26];
    int times = 0;
    bool end = false;

};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        TrieNode* root = new TrieNode();

        for (auto word : words){
            add(word,root);
        }

        int noTimes = search(pref,root);
        // cout<<noTimes<<endl;

        return noTimes;
        
    }

    void add(string s, TrieNode* root){
        TrieNode* temp = root;
        for (int i = 0 ; i < s.length() ; i++){
            char c = s[i];

            int index = c - 'a';

            if (temp->children[index] == nullptr) {
                TrieNode* nn = new TrieNode();
                temp->children[index] = nn;
            }

            temp = temp->children[index];
            temp->times++;
        }

    }

    int search(string s, TrieNode* root){
        auto temp = root;
        int times = 0;
        for (int i = 0 ; i < s.length() ; i++){
            auto ch = s[i];
            int index = ch - 'a';

            if (temp->children[index] == nullptr) {
                return 0;
            } 
            temp = temp->children[index];
        }

        return temp->times;
    }



};