#include <iostream>
#include <vector>
#include <memory>

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    std::vector<std::shared_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode() : children(ALPHABET_SIZE), isEndOfWord(false) {
        for (auto &child : children) {
            child = nullptr;
        }
    }
};

class Trie {
private:
    std::shared_ptr<TrieNode> root;

    void collectAllWords(std::shared_ptr<TrieNode> node, std::string currentPrefix, std::vector<std::string>& results) {
        if (node->isEndOfWord) {
            results.push_back(currentPrefix);
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i] != nullptr) {
                char nextChar = 'a' + i;
                collectAllWords(node->children[i], currentPrefix + nextChar, results);
            }
        }
    }

public:
    Trie() {
        root = std::make_shared<TrieNode>();
    }

    void insert(const std::string &key) {
        std::shared_ptr<TrieNode> pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = std::make_shared<TrieNode>();
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(const std::string &key) {
        std::shared_ptr<TrieNode> pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) {
                return false;
            }
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }

    std::vector<std::string> autoComplete(const std::string &prefix) {
        std::vector<std::string> results;
        std::shared_ptr<TrieNode> pCrawl = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index]) {
                return results; // Trả về danh sách rỗng nếu tiền tố không tồn tại
            }
            pCrawl = pCrawl->children[index];
        }
        // Thu thập tất cả các từ bắt đầu với tiền tố này
        collectAllWords(pCrawl, prefix, results);
        return results;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("helium");
    trie.insert("hexagon");
    trie.insert("hero");
    trie.insert("her");

    auto completions = trie.autoComplete("he");
    std::cout << "Auto-complete for 'he':\n";
    return 0;
}