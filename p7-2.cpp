/* Programmer: Pooja Lingayat
   Date: 14-04-25
   Aim: To process a text file and count total lines, words, and characters using dynamic memory and without <cstring>.*/

#include <iostream>
#include <fstream>
using namespace std;

// Function to count words in a line
int countWords(const char* line)
 {
    int count = 0;
    bool inWord = false;

    for (int i = 0; line[i] != '\0'; i++)
    {
        char ch = line[i];
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
            inWord = false;
        else if (!inWord)
        {
            inWord = true;
            count++;
        }
    }
    return count;
}

// Function to calculate length of a C-style string
int myStrLen(const char* str)
{
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// Function to copy one C-style string to another
void myStrCpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main()
{
    char filename[100];
    cout << "Enter the filename: ";
    cin.getline(filename, 100);

    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file '" << filename << "'.\n";
        return 1;
    }

    int capacity = 10;
    char** lines = new char*[capacity];
    int lineCount = 0, wordCount = 0, charCount = 0;

    char buffer[1000];

    while (file.getline(buffer, 1000))
        {
        if (lineCount == capacity)
        {
            capacity *= 2;
            char** newLines = new char*[capacity];
            for (int i = 0; i < lineCount; i++)
                newLines[i] = lines[i];
            delete[] lines;
            lines = newLines;
        }

        int len = myStrLen(buffer);
        lines[lineCount] = new char[len + 1];
        myStrCpy(lines[lineCount], buffer);

        charCount += len + 1; // includes newline
        wordCount += countWords(buffer);
        lineCount++;
    }

    file.close();

    // Output result
    cout << "\n--- File Statistics ---\n";
    cout << "Total Lines     : " << lineCount << endl;
    cout << "Total Words     : " << wordCount << endl;
    cout << "Total Characters: " << charCount << " (includes newlines and punctuation)\n";

    // Free memory
    for (int i = 0; i < lineCount; i++)
        delete[] lines[i];
    delete[] lines;

    cout << "\n24CE060_POOJA\n";
    return 0;
}
