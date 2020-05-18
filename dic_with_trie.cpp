/*
Dictionary implementation using trie
*/class WordDictionary {
public:
    struct TrieNode {
        char c;
        std::vector<TrieNode*> children;
        bool end_of_word;
        TrieNode(char _c)
            : c(_c)
            , end_of_word(false)
        {
            children = std::vector<TrieNode*>(26, nullptr);
        }
    };
    /** Initialize your data structure here. */
    WordDictionary()
        : m_root('-')
    {
    }

    /** Adds a word into the data structure. */
    void addWord(std::string word) {
        TrieNode* node = &m_root;
        for (size_t i = 0; i < word.length(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                TrieNode* child = new TrieNode(ch);
                node->children[index] = child;
            }
            node = node->children[index];
        }
        node->end_of_word = true;

    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(std::string word) {
        TrieNode* node = &m_root;
        return search_helper(node, word, 0);
    }

    bool search_helper(TrieNode* node, const std::string& word, size_t index) {
        if (index == word.length()) {
            return false;
        }
        if (node == nullptr) {
            return false;
        }
        char ch = word[index];
        //std::cout<< ch << std::endl;
        if (ch != '.') {
            int i = ch - 'a';
            TrieNode* child = node->children[i];
            if (child == nullptr) {
                return false;
            }
            else if (index == word.length() - 1 && child->end_of_word) {
                return true;
            }
            else {
                return search_helper(child, word, index + 1);
            }
        }
        else {
            for (int i = 0; i < node->children.size(); i++) {
                TrieNode* child = node->children[i];
                if (child == nullptr) {
                    continue;
                }
                else if (index == word.length() - 1 && child->end_of_word) {
                    return true;
                }
                else if (search_helper(child, word, index + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    TrieNode m_root;
};
