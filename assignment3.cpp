//Use only the following three libraries:
#include "parserClasses.h"
#include <iostream>
#include <fstream>

using namespace std;

//Removes all inline comments from the tokenList including the // marker
//Returns the number of comments removed
int removeInlineComments(TokenList &tokenList) {
	int count = 0;
	Token *t = tokenList.getFirst();
	while (t) {
		Token *c1, *c2;
		if (t->getStringRep() == "//") {
			c1 = t;
			c2 = t->getNext();
			if (c2->getStringRep() != "\n") {
				t = c2->getNext();
				tokenList.deleteToken(c2);
				tokenList.deleteToken(c1);
				count++;
			}
			else {
				t = c2;
				tokenList.deleteToken(c1);
				count++;
			}
		}
		else {
			t = t->getNext();
		}
	}
	return count;
}

//Remove all block comments from the tokenList including /* and */ markers
//Returns the number of block comments removed (where each pair of /* and */ count as one comment)
int removeBlockComments(TokenList &tokenList) {
	int count = 0;
	Token *t = tokenList.getFirst();
	Token *prev;
	bool deleteNext = false;

	while (t) {
		if (t->getStringRep() == "/*") {
			deleteNext = true;
		}

		prev = t;
		t = t->getNext();

		if (prev->getStringRep() == "*/") {
			tokenList.deleteToken(prev);
			deleteNext = false;
			count++;
		}

		if (deleteNext) {
			tokenList.deleteToken(prev);
		}
	}
	return count;
}

//Input: a list of tokens
//Output: head pointer to the list of assignment statements, returns NULL if there are no assignment statements
//NOTE: Assignment statement must end with a semi-colon
//@ description: extract all the assignment statements from input token list, prepare a new token list (assignment list)
//using extracted statements and return the head pointer to it
Token* getAssignmentStatements(TokenList &tokenList) {
	Token *t = tokenList.getFirst(); //current position in our token of the passed in token list
	TokenList *assignmentList;
	assignmentList = new TokenList;
	Token * temp = new Token; //temporary position of tokens
	Token* token = new Token; //temporary token to put into the assignmentList
	string tokenString = "";
	{
		using namespace ensc251;
		while (t) {
			if (t->getStringRep() == "=") { //have to add more cases, but test simple case first
				temp = t;
				while (temp->getPrev() != NULL && temp->getPrev()->getStringType() != T_Identifier) {
					temp = temp->getPrev();
				}
				if (temp->getPrev() != NULL) {
					temp = temp->getPrev();
				}
				tokenString += temp->getStringRep();
				while (temp->getStringRep() != ";") {
					temp = temp->getNext();
					tokenString += temp->getStringRep();
				}
				token->setStringRep(tokenString);
				assignmentList->append(token);
				t = t->getNext();
			}
			else {
				t = t->getNext();
			}
		}
	}
	return assignmentList->getFirst();
}

//Example Test code for interacting with your Token, TokenList, and Tokenizer classes
//Add your own code to further test the operation of your Token, TokenList, and Tokenizer classes
int main() {
	ifstream sourceFile;
	TokenList tokens;
	Tokenizer tokenizer;

	//Read in a file line-by-line and tokenize each line
	sourceFile.open("test.cpp");
	if (!sourceFile.is_open()) {
		cout << "Failed to open file" << endl;
		return 1;
	}

	while (!sourceFile.eof()) {
		string lineA, lineB;

		getline(sourceFile, lineA);

		//while the current line ends with a line-continuation \ append the next line to the current line
		while (lineA.length() > 0 && lineA[lineA.length() - 1] == '\\') {
			lineA.erase(lineA.length() - 1, 1);
			getline(sourceFile, lineB);
			lineA += lineB;
		}

		tokenizer.setString(&lineA);
		while (!tokenizer.isComplete()) {
			tokens.append(tokenizer.getNextToken());
		}
		//Re-insert newline that was removed by the getline function
//		tokens.append("\n");
	}

	//MY TEST CASE
	Token *t = tokens.getFirst();
	int k = 0;
	while (t) {
		cout << "token" << k << ": " << t->getStringRep() << "\n";
		cout << "token" << k << ": " << t->getStringType() << "\n";
		t = t->getNext();
		k++;
	}/**/



/*	Token *assignmentStuff = getAssignmentStatements(tokens);
	int k = 0;
	while (assignmentStuff) {
		cout << assignmentStuff->getStringRep();
		assignmentStuff = assignmentStuff->getNext();
	}
	removeInlineComments(tokens);
	removeBlockComments(tokens);



	*/
	/*Test your tokenization of the file by traversing the tokens list and printing out the tokens and the tokens type */
	/*	Token *t = tokens.getFirst();
	while (t) {
	cout << t->getStringRep() << " ";
	t = t->getNext();
	}
	t = tokens.getFirst();
	while (t) {
	cout << t->getStringType() << " ";
	t = t->getNext();
	} */

/*	//MY TEST CASE
	Token *t = tokens.getFirst();
	int k = 0;
	while (t) {
		cout << "token" << k << ": " << t->getStringRep() << "\n";
		cout << "token" << k << ": " << t->getStringType() << "\n";
		t = t->getNext();
		k++;
	}/**/

	/*	//Test your assignment statements
	Token *aListPtr = getAssignmentStatements(tokens);
	while (aListPtr) {
	cout << aListPtr->getStringRep() << " ";
	aListPtr = aListPtr->getNext();
	}*/

	return 0;
}
