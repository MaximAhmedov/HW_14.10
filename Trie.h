#pragma once
#include <iostream>
#include <memory>
#include <vector>

#define ALPHABET_SIZE 26

class Trie {
public:
	class TrieNode {
	public:
		std::shared_ptr<TrieNode> children[ALPHABET_SIZE];
		bool isEndOfWord;
		int counter;
		TrieNode();
	};
	Trie();
	~Trie();
	
	int i2c(char c);
	void insert(std::string&);
	bool search(std::string&);
	bool searchT9(std::string&);
	std::shared_ptr<TrieNode> searchNode(char arr[], int index);
	std::shared_ptr<TrieNode> getRoot()const;
	std::shared_ptr<TrieNode> remove(std::shared_ptr<TrieNode> root, std::string& key, int depth=0);
	bool isEmpty(std::shared_ptr<TrieNode>);
	void findMinPrefixes(std::shared_ptr<TrieNode> node, char buf[], int index, std::string& res);
	void findWords(std::shared_ptr<TrieNode> node, std::string& variations, std::string& prePart, char buf[], int index);
private:
	std::shared_ptr<TrieNode> root;
	int totalWords;
};
