/*  Program created on 3/19/2022

    The program takes in a line of text from the user. It
    then splits the line into words and outputs it to the user
    while checking which word has the most letter repeats.

    If there are words with the same amount of repeated characters, then the program will
    default to the right most word found.

    It will assume that spaces indicates a new word. This program
    is made to test strings and vectors. It is also used to mess around with passing a vector by
    reference.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void splitString(string userInput, int length, vector<string> &wordList);
void printWordList(vector<string> wordList);
void checkRepeats(vector<string> wordList);

int main(){
    string userInput;
    vector<string> wordList;

    //Loops the whole program
    while(true){
        //Getting userInput
        std::cout << "Enter a line of text: ";
        getline(cin, userInput);

        //length of the userInput
        int length = userInput.length();

        //Splits the string
        splitString(userInput, length, wordList);

        //Prints out the words
        printWordList(wordList);

        //Checks which word has the most amount of letter repeats
        checkRepeats(wordList);

        //Resets the wordList
        wordList.clear();
    }

    return 0;
}

//Splits the word list, messing around with vector addresses
void splitString(string userInput, int length, vector<string> &wordList){
    int wordNum = 0;
    string word;

    //Separating the words into a vector
    for(int i = 0; i < length; i++){
        if(userInput[i] != ' '){
            word = word + userInput[i];
        }
        else{
            //If quit or q show up at any time, end the program
            if(word == "q" || word == "quit"){
                cout << "Quitting program.";
                exit(1);
            }
            wordList.push_back(word);
            word = "";
            wordNum++;
        }
    }
    
    //Because there is not a space at the end, we need to
    //Add the last word manually
    wordList.push_back(word);

    //If quit or q shows up at start or end of userInput, end the program
    if(word == "q" || word == "quit"){
        cout << "Quitting program.";
        exit(1);
    }
}

//Prints out the words in the word list
void printWordList(vector<string> wordList){
    //Outputting the number of words
    if(wordList.size() == 1){
        cout << endl << "There is only " << wordList.size() << " word in your line. Here is your word: " << endl;
    }
    else{
        cout << endl << "There are " << wordList.size() << " words in your line. Here are your words: " << endl;
    }

    //Outputting the words
    for(int i = 0; i < wordList.size(); i++){
        cout << "Word " << i+1 << ": ";
        cout << wordList[i] << endl;
    }
    cout << endl;
}

//Checks which word has the most amount of repeats
void checkRepeats(vector<string> wordList){
    int repeats = 0;     
    vector<int> repeatCount(wordList.size(), 0);
    
    //For each word in list
    for(int i = 0; i < wordList.size(); i++){
        //For each letter in the word
        int length = wordList[i].length(); 
        for(int j = 0; j < length; j++){
            //Compare each letter
            for(int k = 0; k < length; k++){
                //If the letter repeats, add one, sets to lowercase to check easier
                if(tolower(wordList[i][j]) == tolower(wordList[i][k])){
                    repeats++;
                }
            }
            //Overwrites the max repeats
            if(repeats > repeatCount[i]){
                repeatCount[i] = repeats;
            }
            //Reset the counter
            repeats = 0;
        }
    }

    //Check which word had the most letter repeats
    int chosenWord = 0;
    for(int i = 0; i <  repeatCount.size() - 1; i++){
        if(repeatCount[i] < repeatCount[i+1]){
            chosenWord = i+1;
        }
    }

    //There is only 1 repeat, so all words are the same
    if(repeatCount[chosenWord] == 1){
        cout << "The words have the same amount of repeats." << endl << endl;
        return;
    }
    //Outputs the word with the most letter repeats
    else{
        cout << "The word: \"" << wordList[chosenWord] << "\" has the most repeated letters." << endl << endl;
    }
}