#pragma once
#include <iostream>
#include <map>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include "Trie.h"

int countNumberOfWords(std::string sentence);
std::vector<std::string> splitString(std::string sentence);
void showWords(std::vector<std::string> x);
void gotoxy(short x, short y);
void fillTrie(std::shared_ptr<Trie> trie, std::vector<std::string> words);