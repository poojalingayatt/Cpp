/* Programmer: Pooja Lingayat
   Date: -05-25
   Aim: To create a tool that analyzes text content and displays word frequency distribution using a std::map for efficient word storage and retrieval.*/

#include <iostream>
#include <map>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

// Function to count word frequencies
void countWordFrequencies(const string& sentence)
{
    map<string, int> wordFrequency;

    // Create a stringstream from the sentence
    stringstream ss(sentence);
    string word;

    // Process each word in the sentence
    while (ss >> word) {
        // Remove punctuation from the word
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Convert the word to lowercase for case-insensitive counting
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Increase the word count in the map
        wordFrequency[word]++;
    }

    // Display the word frequencies
    cout << "\nWord Frequencies:\n";
    for (const auto& pair : wordFrequency)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);  // Read a full line of input

    countWordFrequencies(sentence);  // Call the function to count word frequencies
     cout << "\n24CE060_POOJA\n";

return 0;
}

