//
//  main.cpp
//  211. 添加与搜索单词 - 数据结构设计
//
//  Created by SeacenLiu on 2019/4/3.
//  Copyright © 2019 成. All rights reserved.
//

/**
 设计一个支持以下两种操作的数据结构：
 
 void addWord(word)
 bool search(word)
 search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
 
 示例:
 
 addWord("bad")
 addWord("dad")
 addWord("mad")
 search("pad") -> false
 search("bad") -> true
 search(".ad") -> true
 search("b..") -> true
 说明:
 
 你可以假设所有单词都是由小写字母 a-z 组成的。
 */

/**
 - 字典树(TrieTree)
 */

#include <iostream>
#include <vector>
using namespace std;

class WordDictionary {
private:
    struct TrieNode {
        bool isWord;
        TrieNode* children[26];
    };
    
    TrieNode * trieRoot;
    
    bool find(int idx, TrieNode *ptr, string &str) {
        if (ptr == nullptr || str.empty() || idx > str.size())
            return false;
        if (idx == str.size())
            return ptr->isWord;
        if (str[idx] != '.') {
            // 字典搜索
            if (ptr->children[str[idx]-'a'] != nullptr)
                return find(idx+1, ptr->children[str[idx]-'a'], str);
            return false;
        } else {
            // 通配符处理
            for (int i = 0; i < 26; ++i) {
                if (ptr->children[i] != nullptr && find(idx+1, ptr->children[i], str))
                    return true;
            }
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trieRoot = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *ptr = trieRoot;
        for (auto ch : word) {
            if (ptr->children[ch-'a'] == nullptr) {
                ptr->children[ch-'a'] = new TrieNode();
            }
            ptr = ptr->children[ch-'a'];
        }
        ptr->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(0, trieRoot, word);
    }
};

void test(vector<string> adds, vector<string> searchs) {
    cout << "----------------------" << endl;
    WordDictionary dict = WordDictionary();
    for (auto v: adds)
        cout << v << " ";
    cout << endl;
    for (auto v: adds)
        dict.addWord(v);
    for (auto v: searchs)
        cout << v << " " << dict.search(v) << endl;
    cout << "----------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({"bad","dad","mad"}, {"pad","bad",".ad","b.."});
    test({"at","and","an","add","a"}, {".at","bat",".at","an.","a.d.","b.","a.d","."});
    return 0;
}
