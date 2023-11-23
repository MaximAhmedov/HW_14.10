#include "Functions.h"

int countNumberOfWords(std::string sentence)
{
	int numberOfWords = 0;
	size_t i;
	if (isalpha(sentence[0])) {
	    numberOfWords++;
	}
	for (i = 1; i < sentence.length(); i++) {
	    if ((isalpha(sentence[i])) && (!isalpha(sentence[i - 1]))) {
	        numberOfWords++;
	    }
	}
	return numberOfWords;
}

std::vector<std::string> splitString(std::string sentence)
{
	std::vector<std::string> result;
	std::istringstream iss(sentence);
	std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(result));
	return result;
}

void showWords(std::vector<std::string> x)
{
	for (int i = 0; i < x.size(); i++) {
		std::cout << x[i] << ' ';
	}
	std::cout << std::endl;
}

void gotoxy(short x, short y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void fillTrie(std::shared_ptr<Trie> trie, std::vector<std::string> words)
{
	int size = words.size();
	for (int i = 0; i < size; i++) {
		trie->insert(words[i]);
	}
}


