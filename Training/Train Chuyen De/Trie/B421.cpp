#include <vector>
#include <algorithm>
using namespace std;

struct XORTrieNode {
    XORTrieNode* children[2];  // chỉ có bit 0 và 1
    
    XORTrieNode() {
        children[0] = children[1] = nullptr;
    }
};


class Solution {
public:
    XORTrieNode* root;
    Solution() {
        root = new XORTrieNode();
    }

    void insert(int num) {
        XORTrieNode* current = root;
        
        // Duyệt từ bit cao nhất (bit 31) xuống bit 0
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            if (current->children[bit] == nullptr) {
                current->children[bit] = new XORTrieNode();
            }
            
            current = current->children[bit];
        }
    }
    
    int findMaxXORWithNum(int num) {
        XORTrieNode* current = root;
        int maxXOR = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            
            // Cố gắng chọn bit ngược lại để maximize XOR
            if (current->children[oppositeBit] != nullptr) {
                maxXOR |= (1 << i);
                current = current->children[oppositeBit];
            } else {
                current = current->children[bit];
            }
        }
        
        return maxXOR;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        // Insert tất cả số vào Trie
        for (auto num : nums) {
            insert(num);
        }
        
        int result = 0;
        // Tìm XOR tối đa với mỗi số
        for (auto num : nums) {
            result = max(result, findMaxXORWithNum(num));
        }
        
        return result;
    }
};