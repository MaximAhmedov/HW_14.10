#include <iostream>
#include "Trie.h"

Trie::TrieNode::TrieNode()
{
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		children[i] = std::shared_ptr<TrieNode>();
	}
	isEndOfWord = false;
	counter = 0;
}

Trie::Trie()
{
	root = std::shared_ptr<TrieNode>
		(new TrieNode());
	totalWords = 0;
}

Trie::~Trie(){}

int Trie::i2c(char c)
{
	return static_cast<int>(c - 'a');
}

void Trie::insert(std::string& key)
{
	std::shared_ptr<TrieNode> current = root;
	for (int i = 0; i < key.size(); i++)
	{
		if (current->children[i2c(key[i])] ==
			std::shared_ptr<TrieNode>(nullptr))
		{
			current->children[i2c(key[i])] =
				std::shared_ptr<TrieNode>(new TrieNode());
		}
		current = (current->children[i2c(key[i])]);
		current->counter++;
	}
	current->isEndOfWord = true;

}

bool Trie::search(std::string& key)
{
	std::shared_ptr<TrieNode> node = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!node->children[index])
			return false;

		node = node->children[index];
	}

	return (node != nullptr && node->isEndOfWord);
}

bool Trie::searchT9(std::string& key)
{
	std::shared_ptr<TrieNode> node = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!node->children[index])
			return false;

		node = node->children[index];
	}

	return (node != nullptr);
}



std::shared_ptr<Trie::TrieNode> Trie::getRoot() const
{
	return root;
}

std::shared_ptr<Trie::TrieNode> Trie::remove(std::shared_ptr<TrieNode> root, std::string& key, int depth)
{
	if (!root)
		return nullptr;
	if (depth == key.size()) {
		if (root->isEndOfWord)
			root->isEndOfWord = false;
		if (isEmpty(root)) {
			root = nullptr;
		}

		return root;
	}
	int index = key[depth] - 'a';
	root->children[index] = remove(root->children[index], key, depth + 1);
	if (isEmpty(root) && root->isEndOfWord == false) {
		root = nullptr;
	}
	return root;
}

bool Trie::isEmpty(std::shared_ptr<TrieNode> node)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (node->children[i])
			return false;
	return true;
}

void Trie::findMinPrefixes(std::shared_ptr<TrieNode> node, char buf[], int index, std::string& res)
{
	if (!node)
		return;
	if (isEmpty(node) && node->isEndOfWord == true) {
		buf[index] = '\0';
		res.append(buf);
		res.push_back(' ');
		return;
	}
	if (node->counter == 1)
	{
		buf[index] = '\0';
		res.append(buf);
		res.push_back(' ');
		return;
	}
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (node->children[i]) {
			buf[index] = i + 'a';
			findMinPrefixes(node->children[i], buf, index + 1,res);
		}
	}
}
std::shared_ptr<Trie::TrieNode> Trie::searchNode(char arr[], int index)
{
	std::shared_ptr<TrieNode> node = root;

	for (int i = 0; i < index; i++)
	{
		int indexInNode = arr[i] - 'a';
		if (!node->children[indexInNode])
			return node;

		node = node->children[indexInNode];
	}
	return node;
}

void Trie::findWords(std::shared_ptr<TrieNode> node, std::string& variations, std::string& prePart, char buf[], int index)
{
	if (!node)
		return;
	if (isEmpty(node) && node->isEndOfWord == false) {
		variations.clear();
		return;
	}
	else if (isEmpty(node) && node->isEndOfWord == true) {
		buf[index] = '\0';
		variations.append(prePart);
		variations.append(buf);
		variations.push_back(' ');
		return;
	}
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (node->children[i]) {
			buf[index] = i + 'a';
			findWords(node->children[i],variations, prePart, buf, index+1);
		}
	}
}
