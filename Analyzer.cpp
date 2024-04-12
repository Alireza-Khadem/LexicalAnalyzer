#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
string letter[52] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
string digit[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
string reservedword[16] = {"int", "float", "void", "return", "if", "while", "cin", "cout", "continue", "break", "#include", "using", "namespace", "std", "main", "for"};
string symbol[23] = {"(", ")", "{", "}", "[", "]", ",", ";", "+", "-", "*", "/", "==", "!=", ">", ">=", "<", "<=", "=", "&&", "||", "<<", ">>"};

void tokenize(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        // symbol tokenize
        if (find(begin(symbol), end(symbol), string(1, input[i])) != end(symbol))
        {
            if (i + 1 < input.length() && find(begin(symbol), end(symbol), string(1, input[i + 1])) != end(symbol) && input[i + 1] != ')' && input[i + 1] != '}' && input[i + 1] != ']' && input[i + 1] != '{')
            {
                // if we have two chars symbol
                cout << "<symbol , " << input[i] << input[i + 1] << ">" << endl;
                i++;
            }
            else
            {
                // if we have one char symbol
                cout << "<symbol , " << input[i] << ">" << endl;
            }
        }
        // digit & number tokenize
        else if (find(begin(digit), end(digit), string(1, input[i])) != end(digit))
        {
            string k = "";
            while (i + 1 < input.length() && find(begin(digit), end(digit), string(1, input[i + 1])) != end(digit))
            {
                // read digits
                k = k + input[i];
                i++;
            }
            k = k + input[i];
            cout << "<number , " << k << ">" << endl;
        }
        // reservedword & identifier tokenize
        else if (find(begin(letter), end(letter), string(1, input[i])) != end(letter))
        {
            string word;
            while (find(begin(letter), end(letter), string(1, input[i])) != end(letter))
            {
                // store letter while reading them
                word += input[i];
                i++;
            }
            i--;
            if (word == "include")
            {
                word = "#include";
                while (input[i] != '>')
                {
                    // if read include while reading library name skip
                    i++;
                }
            }
            if (find(begin(reservedword), end(reservedword), word) != end(reservedword))
            {
                // if word was reservedword
                cout << "<reservedword , " << word << ">" << endl;
            }
            else
            {
                // if word was identifier
                cout << "<identifier , " << word << ">" << endl;
            }
        }
        // if read '"' (string)
        else if (input[i] == '"')
        {
            string output;
            i++;
            while (input[i] != '"')
            {
                // while reading letters, store them
                output += input[i];
                i++;
            }
            cout << "<string , " << '"' << output << '"' << ">" << endl;
        }
    }
}

int main()
{
    ifstream file("input.cpp");
    string input, temp;
    while (getline(file, temp))
    {
        // reading input file line by line
        input += temp;
        if (temp == "")
        {
            break;
        }
    }
    tokenize(input);
    return 0;
}