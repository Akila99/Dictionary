#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef WORD_H
#define WORD_H


class Word { // created a class called word
private:
	string word;  // variables of the class
	string type;
	string definition;

public:
	Word(string, string, string); 
	// funtion members
	Word(){}
	void prinDefinitions();
	void setWord(string);
	void setType(string);
	void setDefinitions(string);
	string getWord();
	string getType();
	string getDefinition();
};
//constructor
Word::Word(string Word, string Type, string Definition) {
	this->word = Word;
	this->type = Type;
	this->definition = Definition;

}

void Word::prinDefinitions() {
	cout << "Word Name: " << word << endl;
	if (type == "n") {
		cout << "Word Type: " << "[noun]" << endl;
	}
	else if (type == "v") {
		cout << "Word Type: " << "[verb]" << endl;
	}
	else if (type == "adv") {
		cout << "Word Type: " << "[adverb]" << endl;
	}
	else if (type == "adj") {
		cout << "Word Type: " << "[adjective]" << endl;
	}
	else if (type == "prep") {
		cout << "Word Type: " << "[preposition]" << endl;
	}
	else if (type == "misc") {
		cout << "Word Type: " << "[miscellaneous]" << endl;
	}
	else if (type == "pn") {
		cout << "Word Type: " << "[proper noun]" << endl;
	}
	else if (type == "n_and_v") {
		cout << "Word Type: " << "[noun and verb]" << endl;
	}
	cout << "Word Definition: " << definition << endl;
}

void Word::setWord(string set_word) {
	word = set_word;
}

void Word::setType(string set_type) {
	type = set_type;
}
void Word::setDefinitions(string set_definition) {
	definition = set_definition;
}
string Word::getWord() {
	return word;
}

string Word::getType() {
	return type;
	
}
string Word::getDefinition() {
	return definition;
}







#endif // !WORD_H