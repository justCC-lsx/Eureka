/*
 @ 0xCCCCCCCC
*/

#if defined(_MSC_VER)
#pragma once
#endif

#ifndef TRIE_FOR_DICT_TRIE_H_
#define TRIE_FOR_DICT_TRIE_H_

#include <string>
#include <vector>

struct TrieNode;

class Trie {
public:
    Trie();

    ~Trie();

    // Consider copy and move semantics later.

    void Insert(const std::string& word);

    bool Contains(const std::string& word) const;

    std::vector<std::string> Search(const std::string& prefix) const;

private:
    TrieNode* header_;
};

#endif  // TRIE_FOR_DICT_TRIE_H_