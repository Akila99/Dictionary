// Dictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>
#include "Word.h"
#include <vector>
#include <fstream>
#include "Dictionary.h"

using namespace std;

void Dictionary::createNewFile() {
	string fileName;
	cout << "Enter the file name that you want to create: ";
	getline(cin, fileName);
	string word;


	
	ofstream file(fileName + ".txt");



	if (file) {
		file << "2023-S1 dictionary contains " << Dictionary.size() << " words" << endl;
		file << "" << endl;
		for (Word wordObj : Dictionary) {
			file << "<word>" << endl;
			file << wordObj.getWord()<< endl;
			file << wordObj.getDefinition() << endl;
			file << wordObj.getType() << endl;
			file << "</word>" << endl;

		}

	}

}

void Dictionary::updateDictionary( string word, string wordType, string definition) {

	cout << " okay" << endl;

	/*
	Word wordInstance; // instance
	if ((word.length() != 0) && (wordType.length() != 0) && (definition.length() != 0)) { // if the word , wordType , word definition is not empty
		Word wordObj; // store the new data in a word object
		wordObj.setWord(word);
		wordObj.setDefinitions(definition);
		wordObj.setType(wordType);
		wordObj = { wordObj.getWord(), wordObj.getDefinition(), wordObj.getType()}; // store the new data in a word object
		Dictionary.push_back(wordObj); // store it in the vector 
	}

	if (wordInstance.getWord()  == word) {
		cout << "The word was saved in the dictionary"  << endl;
		

		Word WordObj1(wordInstance.getWord(), wordInstance.getType(),  wordInstance.getDefinition()); //passing through the constructor
		WordObj1.prinDefinitions(); // print the word , type and definition

	}
	else {
		cin.clear(); //clear the error flag on cin
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Word is not saved!!" << endl;

	}*/

}

string Dictionary:: getDefinition() {

	bool loopCondition = false;
	string definition;

	while (loopCondition != true) {
		cout << "Enter the definition of the word: ";
		getline(cin, definition);

		if (definition.length() == 0) {
			cout << "Please enter the word definition!!" << endl;
			loopCondition = false;
		}
		else
		{
			loopCondition = true;

		}

	}

	return definition;

}
void Dictionary::task3() {
	string findWord;

	string wordType;

	string definition;


	bool loopEnd = false;
	bool loop = false;

	cout << "----------------------------------------------------" << endl;
	cout << "TASK 3: ADD A WORD, TYPE, DEFINITIONS AND SORT AND CREATE A NEW FILE." << endl;
	cout << "----------------------------------------------------" << endl << endl;

	while (loop != true) { // create a while for word validation 

		
		cout << "Enter the word that you want to add to the Dictinoary: ";
		getline(cin, findWord);
		
		for (char c : findWord) {
			if (isdigit(c)) {
				cout << "Invalid! Digit should not be included." << endl;
				loop = false;
				break;
			}
			else if (findWord.find(" ") != string::npos){
				cout << "Invalid! White spaces should not be included." << endl;
				loop = false;
				break;
			}
			else if (findWord.empty()) {
				cout << "Invalid! Digit should not be included." << endl;
				loop = false;
				break;
			}
			else
			{
				loop = true; // if the find word is valid break the loop
				for (int i = 0; i < findWord.length(); i++) {

					findWord[i] = tolower(findWord[i]); // convert wordName characters into lowercase
				}

				
				for (Word word : Dictionary) {


					if (word.getWord() != findWord) {
						cout << "Word is not in the Dictionary, You Good to go!" << endl;// if the word is not in the vector dictionary print the message

					}
					else {
						cout << "Error: word exists, elevated privileges required to edit existing words." << endl;// if the word exist in the vector dictionary the print error message
						

						/*

						while (loopEnd != true) { // while loop for input validation
							cout << "Enter the Word Type(noun,verb, adverb, adjective, preposition, miscellaneous, proper noun or Noun or verb): ";
							getline(cin, wordType);

							if (wordType.length() > 0) { // check if the wordtype is empty 

								for (int i = 0; i < wordType.length(); i++) {

									wordType[i] = tolower(wordType[i]); // convert wordType characters into lowercase
								}

								if (wordType == "noun") {
									loopEnd = true;
									wordType = "n";
									definition = getDefinition();
									cout << "oky" << endl;
									
									//updateDictionary(findWord, wordType, definition);
								}
								else if (wordType == "verb") {
									loopEnd = true;
									wordType = "v";
									definition = getDefinition();
									updateDictionary(findWord, wordType, definition);
								}
								else if (wordType == "adverb") {
									loopEnd = true;
									wordType = "adv";
									definition = getDefinition();
									updateDictionary(findWord, wordType, definition);
								}
								else if (wordType == "adjective") {
									loopEnd = true;
									wordType = "adj";
									definition = getDefinition();
									updateDictionary(findWord, wordType, definition);
								}
								else if (wordType == "preposition") {
									loopEnd = true;
									wordType = "prep";
									definition = getDefinition();
									updateDictionary(findWord, wordType, definition);
								}
								else if (wordType == "miscellaneous") {
									loopEnd = true;
									wordType = "misc";
									definition = getDefinition();
									updateDictionary(findWord, wordType, definition);
								}
								else if (wordType == "proper noun") {
									loopEnd = true;
									wordType = "pn";
									definition = getDefinition();
									updateDictionary(findWord, wordType, definition);
								}
								else if (wordType == "noun or verb") {
									loopEnd = true;
									wordType = "n_and_v";
									definition = getDefinition();
									updateDictionary(findWord, wordType, definition);
								}
								else {
									cout << "Invalid type!! Please Enter the valid type according to given structure." << endl;
									loop = false;
								}

							}
							else {
								cout << "Invalid!! Please Enter the type according to given structure." << endl;
								loop = false;
							}
						}
						break;*/
					} 
					
				}

			}
		}
	}

}
void Dictionary::task2() {
	string name; // variable for store the vector elements
	const char Z = 'z'; // assign a variable for character Z 
	cout << endl;
	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "TASK 2: PRINT ALL THE WORDS THAT ARE CONTAIN MORE THAN 3 Z'S" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	for (Word word : Dictionary) { // create a range based for loop for check each element in the dictionary vector 
		name = word.getWord();  // store each element in the name variable

		if (name.find(Z) != string::npos) { // checking letter z in the each element 

			int length = name.length();  // assign a variable for length of the word
			int count = 0;  // initialized a variable for hold the number of z in the word 
			for (int i = 0; i < (length); i++) {  // checking the word letters one by one using for loop

				if (name[i] == Z) {      // checking if the name[0] is equal to z if the word letter is equal z then add one to count variable  
					count++;
				}

			}
			if (count >= 3) { // if the count is greater than 3 the print to the screen 
				cout << "The words that are contains more that 3 'z's: " << name << endl;
			}
		}


	}
	mainMenu();
}

void Dictionary::task1() 
{
	string wordName; // create a variable to store user input.
	cout << "----------------------" << endl;
	cout << "TASK 1 : FIND THE WORD " << endl;
	cout << "----------------------" << endl;
	cout << "Enter the word that you want to find: ";
	cin >> wordName;

	
	

	for (int i = 0; i < wordName.length(); i++) {

		wordName[i] = tolower(wordName[i]); // convert wordName characters into lowercase
	}
	
	for (Word word : Dictionary)
	{
		
		if (word.getWord() == wordName) {
			cout << "Word Found" << endl;
			//cout << word.getWord() << endl;
			
			Word WordObj1(word.getWord(),word.getType(), word.getDefinition()); //passing through the constructor
			WordObj1.prinDefinitions(); // print the word , type and definition
			
		}
		else {
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Word Not Found!" << endl;
			
		}
		mainMenu();

	}
	
	
	
	/*
	auto searchWord = find_if(Dictionary.begin(), Dictionary.end(), [&wordName](const Word& word) { // search the user input(wordName) in the Dictionary vector by referencing the Wordname 
		return  word.getWord() == wordName; // comparing the current word name with the user input
		});
	//auto searchWord = std::find(Dictionary.begin(), Dictionary.end(), wordName);

	if (searchWord != Dictionary.end()) {
		string word_Name, word_type, word_definition;
		cout << "Word Found" << endl;
		//word_Name = searchWord->word;// asign vector elements to new variables
		//word_type = searchWord->type;
		//word_definition = searchWord->definition;

		//printWord(word_Name, word_type, word_definition);
	}
	else {
		cin.clear(); //clear the error flag on cin
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Word not found" << std::endl;
	}
	//mainMenu(Dictionary);*/
}

void Dictionary::mainMenu() {
	int taskNumber; //create a variabale for  option
	bool taskValidation = false; // create a variable for task validation 

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "ENTER THE OPTION NUMBER THAT YOU WANT TO PERFORM" << endl;
	cout << "------------------------------------------------" << endl << endl;
	cout << "TASK 1: FIND A WORD, TYPE AND DEFINITIONS." << endl;
	cout << "TASK 2: FIND ALL THE WORDS THAT CONTAINS MORE THAN THREE 'Z'." << endl;
	cout << "TASK 3: ADD A WORD, TYPE, DEFINITION AND SORT AND CREATE A NEW FILE." << endl << endl; // Task list

	do {
		cout << "Enter the option number: "; // User input for task 
		cin >> taskNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!!" << endl;// Error message
		}

		switch (taskNumber)
		{
		case 1:
			task1();
			break;
		case 2:
			
			task2();
			break;
		case 3:
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			task3();
			break;

		default:
			cout << "Please enter a valid input from above tasks." << endl;
			break;
		}
	} while (taskNumber < 1 || taskNumber >3);
}

void Dictionary::loadDictionary() // loadDictionary() Load the dictionary
{
	int choice = 0; // variable for user input
	string fileName; // Variable for file name

	while (choice != 1 && choice != 2) { // while loop for choice validation

		cout << "Choose one option (Enter 1 to use default dictionary file or Enter 2 for use a different file): ";
		cin >> choice;

		if (choice == 1) {

			

			//string filename = "dictionary_2023S1.txt"; //asigning the dictionary_2023S1.txt filename variable
			string begin, name, definitions, type, end;

			cout << "Attempting to read text file...\n";
			ifstream myfile("dictionary_2023S1.txt"); //Opening the file 

			if (myfile.is_open())
			{

				while (!myfile.eof())
				{


					getline(myfile, begin); // Store the <word>
					if (!(begin.substr(0, 2) == "20")) { // ignore the header of the file
						if (!(begin == "")) { //ignore the blank line in the file
							if (begin == "<word>") {
								getline(myfile, name); // store the word
								getline(myfile, definitions); // store the word difinition
								getline(myfile, type); // Store the word type
								getline(myfile, end); // store the </Word>

								Word new_Word(name, type, definitions);

								Dictionary.push_back(new_Word); // store the each element to the back of the vector called Dictionary

							}

						}

					}


				}
				myfile.close();
				mainMenu();

			}
			else cout << "NO DICTIONARY LOADED!!" << endl << endl;



		}
		else {

			if (choice == 2) {
				//vector <Word> Dictionary; //A vector to hold all the content from the file

				
				string begin, name, definitions, type, end;

				cout << "Which file do you want to open: ";
				cin >> fileName;

				fileName = (fileName + ".txt");

				cout << "Attempting to read text file...\n";
				ifstream myfile(fileName);
				if (myfile.is_open())
				{

					while (!myfile.eof())
					{


						getline(myfile, begin); // Store the <word>
						if (!(begin.substr(0, 2) == "20")) { // ignore the header of the file
							if (!(begin == "")) { //ignore the blank line in the file
								if (begin == "<word>") {
									getline(myfile, name); // store the word
									getline(myfile, definitions); // store the word difinition
									getline(myfile, type); // Store the word type
									getline(myfile, end); // store the </Word>

									Word word = { name ,type, definitions }; // declare a word for Word struct

									Dictionary.push_back(word); // store the each element to the back of the vector called Dictionary

								}

							}

						}


					}
					myfile.close();
					mainMenu();

				}
				else cout << "NO DICTIONARY LOADED!!" << endl << endl;




			}
			else {
				cin.clear(); //clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the remaining characters in user input
				cout << "Invalid Input!!" << endl;

			}
		}


	}
	

}
void Dictionary:: wellcome()
{
	cout << "WELLCOME TO THE ENGLISH DICTIONARY IN C++" << endl;
	cout << "--------------------------------------------------" << endl << endl;
	cout << "HELLO EVERYONE!!, THIS DICTIONARY WILL PROVIDE OPTIONS TO FIND THE WORD AND SEARCH THE WORDS AND STORE NEW WORDS. YOU GOOD TO GO!!!" << endl << endl;

	loadDictionary();


}


int main()
{
	Dictionary dic1;
	dic1.wellcome();
}

