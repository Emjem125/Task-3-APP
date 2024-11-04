//
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


void getPosition(vector <string> lowerWord , string wordToFind) {
	
	auto it = find(lowerWord.begin(), lowerWord.end(), wordToFind);

	if (it != lowerWord.end()) {


		int index = it - lowerWord.begin();
		cout << index + 1 << endl;
	}
	else {
		cout << "-1" << endl;
	}

}

void getLastPosition(vector <string> lowerWord, string wordToFind, int numberOfWords) {
	reverse(lowerWord.begin(), lowerWord.end());

	auto it = find(lowerWord.begin(), lowerWord.end(), wordToFind);

	if (it != lowerWord.end()) {
		int index = it - lowerWord.begin();
		cout << numberOfWords - (index - 1 )<< endl;
	}
	else {
		cout << "-1" << endl;
	}
}



int main() {
	string filename;
	string word;
	cout << "Please enter filename to read here: "; getline(cin, filename);

	fstream File; //opens the file
	File.open(filename.c_str());
	//string line;
	//getline(File, line);//reads each line of the file

	int numberOfWords = 0;
	int numberOfSentences = 0;
	int count = 0;
	string wordToFind;

	vector<string> wordFile;
	vector<string> newWordFile;
	vector<string> lowerWord;

	while(File) {
		File >> word;
		if ((word.back() == '.' || word.back() == '!' || word.back() == '?' || word.back() == ';' || word.back() == ',' || word.back() == '\n') && !word.empty()) {
			word = word.substr(0, word.size() - 1);
		}
		wordFile.push_back(word);
		cout << "the word is " << word << endl; //prints out each word on each line (visual aid for now)
		numberOfWords += 1;
		
	}


	cout << "rat" << endl;

	File.close();

	File.open(filename);

	while (!File.eof()) {
		string sentence;
		sentence = File.get();
		//cout << sentence << endl;
		if (sentence == "." || sentence == "!" || sentence == "?") {
			//cout << "hello rat you made it";
			numberOfSentences += 1;
		}


	}

	numberOfWords -= 1;
	cout << "number of sentences is " << numberOfSentences << endl;
	cout << "number of words is " << numberOfWords << endl;

	map<string, int> wordCount;
	//Loop through every word in the wordFile vector
	//Add the first word to the new vector be default
	//Add it to the newWordFile vector if it is not already in it or unique
	//A word in the newWordFile vector has already been checked. 
	for (const auto& word : wordFile) {
		wordCount[word]++;
	}
	/*
	for (const auto& pair : wordCount) {
	//pair.first is the word, pair.second is the word count
		cout << pair.first << "\t" << pair.second << endl;
	}
	*/

	//Search through each word in the original vector
	for (string word : wordFile) {
		if (find(newWordFile.begin(), newWordFile.end(), word) != newWordFile.end()) {
			//Then the current word has already been checked
		}
		else {
			newWordFile.push_back(word);
		}
	}

	/*
	for (string word : newWordFile) {
		cout << "Printing distinct words from file: " << word << endl;
	}
	*/

	for (string word : newWordFile) {
		auto result = wordCount.find(word);
		cout << word << '\t' << result->second << endl;
	}

	/*
	for (string word : wordFile) {
		cout << "newWordFile size: " << newWordFile.size() << endl;
		count = 0;
		checked = false;

		if (newWordFile.empty()) {
			newWordFile.push_back(word);
		}
		else {
			int i = 0;
			while (checked == false) {
				cout << "Rattus cattus cactus: " << i << endl;
				cout << "newWorldFile[i]: " << i << ":" << newWordFile[i] << endl;
				if (word == newWordFile[i]) {
					checked = true;
				}
				else {
					checked = false;
					newWordFile.push_back(word);
				}
				if (i > 39) {
					checked = true;
				}
				i++;

			}
		}

		if (checked) {
			continue;
		}
		else {
			for (int i = 0; i < wordFile.size(); i++) {
				if (word == wordFile[i]) {
					count += 1;
				}
			}
		}
		*/


		//sort(wordFile.begin(), wordFile.end());
		/*auto it
			= unique(wordFile.begin(), wordFile.end());
		wordFile.erase(it, wordFile.end());*/










		/*for (const auto& pair : count) {
			cout << pair.first << " " << pair.second << endl;
		}
		*/

	cout << "Enter word to find please: " << endl;
	cin >> wordToFind;
	if (int(wordToFind.at(0) < 97)) {
		wordToFind.at(0) = int(wordToFind.at(0) + 32);
	}

	for (string word : wordFile) {
		if (int(word.at(0) < 97)) {
			word.at(0) = int(word.at(0) + 32);
		}
		lowerWord.push_back(word);
	}
	

	getPosition(lowerWord, wordToFind);

	getLastPosition(lowerWord, wordToFind, numberOfWords);

	File.close();
}