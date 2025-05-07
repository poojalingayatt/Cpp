/* Programmer: Pooja Lingayat
   Date: 18-4-25
   Aim: To implement a word frequency counter that reads a paragraph from a file and counts the occurrences of each word. */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Convert a character to lowercase (manual)
char toLowerChar(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch + ('a' - 'A');
    return ch;
}

// Convert a string to lowercase
string toLowerString(const string& str)
{
    string result;
    for (char ch : str)
        result += toLowerChar(ch);
    return result;
}

// Struct to store word and count
struct WordFreq
{
    string word;
    int count;
};

// Function to split a string into words manually
bool isDelimiter(char ch)
{
    return ch == ' ' || ch == ',' || ch == '.' || ch == '-' || ch == '\n';
}

// Word frequency counter using dynamic memory
void countWords(const string& paragraph)
{
    WordFreq* words = new WordFreq[10];
    int size = 0;
    int capacity = 10;

    string word = "";

    for (char ch : paragraph)
        {
        if (!isDelimiter(ch))
        {
            word += toLowerChar(ch);  // Build lowercase word
        }
    else if (!word.empty())
        {
            // Check if word already exists
            bool found = false;
            for (int i = 0; i < size; ++i)
            {
                if (words[i].word == word)
                {
                    words[i].count++;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                if (size == capacity)
                {
                    capacity *= 2;
                    WordFreq* newWords = new WordFreq[capacity];
                    for (int i = 0; i < size; ++i)
                        newWords[i] = words[i];
                    delete[] words;
                    words = newWords;
                }
                words[size].word = word;
                words[size].count = 1;
                size++;
            }
            word = ""; // Reset for next word
        }
    }

    // Final word (if no delimiter at end)
    if (!word.empty())
        {
        bool found = false;
        for (int i = 0; i < size; ++i)
        {
            if (words[i].word == word)
            {
                words[i].count++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            if (size == capacity)
            {
                capacity *= 2;
                WordFreq* newWords = new WordFreq[capacity];
                for (int i = 0; i < size; ++i)
                    newWords[i] = words[i];
                delete[] words;
                words = newWords;
            }
            words[size].word = word;
            words[size].count = 1;
            size++;
        }
    }

    // Display output
    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < size; ++i)
        cout << words[i].word << ": " << words[i].count << endl;

    delete[] words;
}

int main() {
    ifstream file("paragraph.txt");
    if (!file)
    {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    string line, paragraph;
    while (getline(file, line))
    {
        paragraph += line + " ";
    }

    countWords(paragraph);
    cout<<"\n24CE060_POOJA\n";
    return 0;
}
