#pragma once
#include <iostream>
#include <string>
#include "Word.h"
#include <vector>

using namespace std;

#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary  {
private:
	vector <Word>Dictionary; //slt vector called dictionary
	
public:
	
	void loadDictionary();
	void wellcome();
	void mainMenu();
	void task1();
	void task2();
	void task3();
	string getDefinition();
	void  updateDictionary(string , string ,string);
	void createNewFile();
};


#endif