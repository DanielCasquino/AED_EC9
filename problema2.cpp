#pragma once

#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    struct Trie
    {
        struct TrieNode
        {
            unordered_map<char, TrieNode *> edges;
            bool endsWord;
            TrieNode() : endsWord(false) {}
            ~TrieNode() {}

            void insert(TrieNode *node, string word)
            {
                auto currentNode = node;
                for (const auto c : word)
                {
                    if (currentNode->edges.find(c) == currentNode->edges.end())
                    {
                        currentNode->edges.insert({c, new TrieNode()});
                    }
                    currentNode = currentNode->edges.at(c);
                }
                currentNode->endsWord = true;
            }

            bool find(TrieNode *node, string word)
            {
                auto currentNode = node;
                for (const auto c : word)
                {
                    if (currentNode->edges.find(c) == currentNode->edges.end())
                    {
                        return false;
                    }
                    currentNode = currentNode->edges.at(c);
                }
                return currentNode->endsWord;
            }
        };

        TrieNode *root;
        Trie()
        {
            root = new TrieNode();
        }
        void insert(string word)
        {
            root->insert(root, word);
        }
        bool find(string word)
        {
            return root->find(root, word);
        }
        ~Trie() {}
    };

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        auto t = new Trie();
        for (const auto word : words)
        {
            t->insert(word);
        }
    }
};