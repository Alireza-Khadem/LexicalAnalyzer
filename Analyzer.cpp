#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

char letter[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char digit[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string reservedword[15] = {"int", "float", "void", "return", "if", "while", "cin", "cout", "continue", "break", "#include", "using", "namespace", "std", "main"};

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
                cout << "<Symbol , " << input[i] << input[i + 1] << ">" << endl;
                i++;
            }
            else
            {
                cout << "<Symbol , " << input[i] << ">" << endl;
            }
        }
    }
}

int main()
{
    string input, temp;
    while (getline(cin, temp))
    {
        input += temp;
        if (temp == "")
        {
            break;
        }
    }
    tokenize(input);
    return 0;
}