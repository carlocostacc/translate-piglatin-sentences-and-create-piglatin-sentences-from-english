#include <iostream>
#include <string>
using namespace std;

char vowel[] = { 'a','e','i','o','u','y','A','E','I','O', 'U', 'Y' };
char consonant[] = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'X', 'Z', 'W', 'b' , 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'w', 'z' };
string findandchangeword(string tosearch, int pos);
string findandchangewordcons(string tosearch, int pos);
string notvowelnotconsonant(string tosearch, int pos);
string getString(char x);
string completitioncons = "-";
string completion = "-way";

int main() {
	string sentence;
	string copystring;
	bool space = true;
	int type;
	cout << "select if you want to transform a sentence to piglatin or to translate a sentence from piglatin" << endl;
	cout << "1 to transform and 2 to translate" << endl;
	cin >> type;
	cout << endl;
	cout << "enter your string here : ";
	cin.ignore();
	getline(cin, sentence);
	cout << endl;
	if (type == 1) {
		for (int i = 0; i < sentence.length(); i++) {
			if (i == 0) {
				for (char x : vowel) {
					if ( x == sentence[i]) {
						sentence = findandchangeword(sentence, i);
						cout << "do stuff";
					}
				}
				
				sentence = notvowelnotconsonant(sentence, i);
				cout << "do stuff 1";
			}
			if (sentence[i] == ' ') {
				for (char x : vowel) {
					if (sentence[i + 1] == x) {
						sentence = findandchangeword(sentence, i + 1);
						
					}
				}
				cout << "do stuff 1";
				sentence = notvowelnotconsonant(sentence, i+1);
			}
		}
		for (int j = 0; j < sentence.length(); j++) {
			if (j == 0) {
				for (char x : consonant) {
					if (x == sentence[j]) {
						sentence = findandchangewordcons(sentence, j);
						cout << "do stuff2";
					}
				}
			}
			if (sentence[j] == ' ') {
				for (char x : consonant) {
					if ( x == sentence[j+1]) {
						sentence = findandchangewordcons(sentence, j +1);
						cout << "do stuff3";
					}
				}
			}
		}
		cout << endl << sentence;
		return 0;
	}
	if (type == 2) {
		/*for (int i = 0; i < sentence.length(); i++) {
			if (sentence.find(completion, i) > i) {

				sentence.erase(sentence.find(completion, i), 4);
				cout << i;
			}
		}*/
		do {
			string sentencenew = sentence;
			if (sentence.find(completion) > 0 && sentence.find(completion)< sentence.length())
				sentence.erase(sentence.find(completion), 4);
			cout << sentence.find(completion);
			cout << endl << sentence;
			if (sentence == sentencenew) {
				break;
			}
		} while (sentence.find(completion)>0);
		cout << "didipass 2";
		do {
			if (sentence.find_first_of(completitioncons, i) > i) {
				int x = sentence.find_first_of(" ", i);
				int y = sentence.find_first_of(completitioncons, i);
				if (sentence.find_first_of("ay", y) < x && sentence.find_first_of("ay", y)>i){
					string str = sentence.substr(y + 1, sentence.find_first_of("ay", y) - 1);
					if( sentence.find_last_of(" ", y) + 1> 0)
						sentence.insert(sentence.find_last_of(" ", y)+1, str);
					else 
						sentence.insert(0, str);
					sentence.erase(sentence.find_first_of("ay", y), 2);
					sentence.erase(sentence.find_first_of("-", i),1);
				}
			}
		} while (sentence.find_first_of("ay") > 0);
		
		cout << endl << sentence;
		return 0;
	}
}

string findandchangeword(string tosearch, int pos) {
	for (; pos <= tosearch.length(); pos++)
	{
		if (tosearch[pos] == ' ')
		{
			tosearch.insert(pos, completion);
			return tosearch;

		}
		if (pos == tosearch.length() ) {
			tosearch.insert(pos, completion);
			return tosearch;
		}
	}
	return tosearch;
	
}

string findandchangewordcons(string tosearch, int pos) {
	int realstart = pos;
	int shift = 1;
	for (; pos <= tosearch.length(); pos++)
	{
		if (tosearch[pos] == ' ')
		{
			tosearch.insert(pos, completitioncons);
			for (; realstart <= pos; realstart++) {
				for (char x : consonant) {
					if (x == tosearch[realstart]) {
						tosearch.insert(pos + shift, getString(tosearch[realstart]));
						tosearch.erase(realstart, 1);
						realstart--;
						if (realstart == -1)
							realstart = 0;
						if (realstart < 0 || realstart > tosearch.length() || pos + shift > tosearch.length()) {
							cout << "outofrange 4";
							cout << "the value of the pointer is " << realstart;
							break;
						}
					}
				}
				for (char x : vowel) {
					if (x == tosearch[realstart]) {
						tosearch.insert(pos + shift, "ay");
						return tosearch;
					}
				}
			}
			

		}
		if (pos == tosearch.length()) {
			tosearch.insert(pos, completitioncons);
			for (; realstart <= pos; realstart++) {
				for (char x : consonant) {
					if (x == tosearch[realstart]) {
						tosearch.insert(pos + shift, getString(tosearch[realstart]));
						tosearch.erase(realstart, 1);
						shift++;
					}
				}
				for (char x : vowel) {
					if (x == tosearch[realstart]) {
						tosearch.insert(pos + shift - 1, "ay");
						return tosearch;
					}
				}
			}
			return tosearch;
		}
	}
	return tosearch;
}

string getString(char x)
{
	string s(1, x);

	return s;
}

string notvowelnotconsonant(string tosearch, int pos) {
	int realstart = pos;
	int count = 0;
	for (; pos <= tosearch.length(); pos++) {
		if (tosearch[pos] == ' ' || pos == tosearch.length()) {
			for (; realstart < pos;realstart++) {
				for (char x : vowel) {
					if (x == tosearch[realstart])
						count++;
				}
				for (char x : consonant) {
					if (x == tosearch[realstart])
						count++;
				}
			}
			if (count == 0) {
				tosearch.insert(pos, completion);
				return tosearch;
			}
			else
				return (tosearch);
		}
	}
}