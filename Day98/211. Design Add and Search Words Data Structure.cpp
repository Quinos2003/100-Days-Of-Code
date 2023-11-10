class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &it : child) it = nullptr;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            int curr = word[i] - 'a';
            if (node->child[curr] == NULL) {
                node->child[curr] = new TrieNode();
            }
            node = node->child[curr];
        }
        
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return searchInNode(word, 0, node);
    }
private:
    TrieNode* root;
    
    bool searchInNode(string& word, int i, TrieNode* node) {
        if (node == NULL) {
            return false;
        }
        if (i == word.size()) {
            return node->isWord;
        }
        if (word[i] != '.') {
            return searchInNode(word, i + 1, node->child[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++) {
            if (searchInNode(word, i + 1, node->child[j])) {
                return true;
            }
        }
        return false;
    }
};

// /**
//  * Your WordDictionary object will be instantiated and called as such:
//  * WordDictionary* obj = new WordDictionary();
//  * obj->addWord(word);
//  * bool param_2 = obj->search(word);
//  */

// class WordDictionary
// {
//      unordered_map<int, vector<string>> words;

//      bool isEqual(string word1, string word2)
//      {
//           for (int i = 0; i < word1.size(); i++)
//           {
//                if (word2[i] == '.')
//                     continue;
//                if (word1[i] != word2[i])
//                     return false;
//           }
//           return true;
//      }

// public:
//      WordDictionary() {}

//      void addWord(string word)
//      {
//           words[word.size()].push_back(word);
//      }

//      bool search(string word)
//      {
//           for (auto &&s : words[word.size()])
//                if (isEqual(s, word))
//                     return true;
//           return false;
//      }
// };