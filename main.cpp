#include <iostream>
#include "Trie.h"
#include "Functions.h"


int main() {
    setlocale(LC_ALL, "");
    std::shared_ptr<Trie> myTrie(new Trie());

    std::vector<std::string> Dictionary{"hello","call","help","leave","run","say","how","go","what","can","love","like","to","by","talk","miss","you","are","me","my",
    "name","why","who","do","not","take","give","up","right","left","stay"};

    fillTrie(myTrie, Dictionary);

    char arr[100]{' '};
    int ind = 0;
    bool isRunning = true;
    int time = clock();
    std::string stroka;
    std::string strokaFinal;
    short posSpc = 0;
    short posLns = 0;
    char x;

    while (isRunning) {
        gotoxy(posSpc, posLns);
        x = _getch();
        if (x != 32 && (x > 96 && x < 123)) {
            arr[ind] = x;
            arr[ind + 1] = '\0';
            ind++;
            int newInd = 0;
            char newArr[100];
            std::shared_ptr<Trie::TrieNode> start = myTrie->searchNode(arr, ind);
            std::string prefix;
            prefix.append(arr);
            stroka.clear();
            if (myTrie->searchT9(prefix))
                myTrie->findWords(start, stroka, prefix, newArr, newInd);
        }
        else if ((x > 47 && x < 57) || x == 32) {
            if ((x > 47 && x < 57) && (!stroka.empty())) {
                std::vector<std::string> newStringVector = splitString(stroka);
                int y = (int)x - 49;
                if (y < newStringVector.size()) {
                    strokaFinal += newStringVector[y] += " ";
                }
                else
                    continue;
            }
            else if (x == 32) {
                if (ind != 0) {
                    strokaFinal.append(arr);
                }
                strokaFinal.push_back(' ');
            }
            for (int i = ind - 1; i > -1; i--) {
                arr[i] = ' ';
            }
            ind = 0;
            if (!stroka.empty()) {
                stroka.clear();
            }
        }
        else if (x == 13) {
            if (ind > 0)
                strokaFinal.append(arr);
            break;
        }
        else
            continue;
        system("cls");
        if(!strokaFinal.empty())
            std::cout << strokaFinal;
        if (ind > 0) {
            for (int i = 0; i < ind; i++) {
                std::cout << arr[i];
            }
            std::cout << '\n';
        }
        if (!stroka.empty()) {
            std::cout << "Выберите номер слова для его добавления в ваше сообщение, нажмите Enter для завершения работы.\n";
            std::cout << stroka << '\n';
        }
        posSpc = strokaFinal.length() + ind;
    }
    system("cls");
    std::cout << "Ваше сообщение:\n\t" << strokaFinal << '\n';
	return 0;
}