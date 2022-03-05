class Trie {
    struct Node{
        unordered_map<char,Node*> charMap;
        bool isEnd;
        Node(bool end){
            isEnd = end;
        }
    };
    unordered_map<char, Node*> entry;
public:
    Trie() {
    }
    
    void insert(string word) {
        Node* curr;
        int i = 0;
        if(entry.find(word[i]) == entry.end()) entry[word[i]] = new Node(word.size()==1);
        else entry[word[i]]->isEnd = word.size()==1;
        curr  = entry[word[i]];
        i++;
        while(i<word.size()){
            if(curr->charMap.find(word[i]) == curr->charMap.end()) curr->charMap[word[i]] = new Node(word.size()==i+1);
            else curr->charMap[word[i]]->isEnd = curr->charMap[word[i]]->isEnd or word.size()==i+1;
            curr = curr->charMap[word[i]];
            i++;
        }
        
    }
    
    int searchResult(string word){
        Node* curr;
        int i = 0;
        if(entry.find(word[i]) == entry.end()) return 0;
        else curr  = entry[word[i]];
        i++;
        while(i<word.size()){
            if(curr->charMap.find(word[i]) == curr->charMap.end()) return 0;
            else curr = curr->charMap[word[i]];
            i++;
        }
        if(curr->isEnd) return 1;
        else return 2;
    }
    
    bool search(string word) {
        return searchResult(word) == 1;
    }
    
    bool startsWith(string prefix) {
        return searchResult(prefix) > 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */