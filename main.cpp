#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    string storege("\\MyFolder\\MyDoc\\myFile.txt");
    ifstream fin;
    vector<string> vVectr;
    string resultStr;
    fin.open(storege);

    if (!fin.is_open())
    {
        cout << "this file is missing" << endl;
    }
    else
    {
        cout << "this file is open" << endl;
        string str;
        while(!fin.eof())
        {
           fin >> str;
           vVectr.push_back(str);
        }
    }

    for (int i = 0; i < vVectr.size(); ++i)//виведення на екран тексту файла
    {
        cout << vVectr[i] << ' ';
    }

    cout << endl;

    for (int i = 0; i < vVectr.size(); ++i)
    {
        string str = vVectr[i];

        for (int j = 0; j < str.length(); ++j)
        {
            char ch = str[j];
            str.erase(str.begin()+j);

            if(str.find(ch) == string::npos)
            {
                resultStr.push_back(ch);
                break;
            }
            else
            {
                str.insert(str.begin()+j,ch);
            }
        }
    }

    cout << endl;

    for (int i = 0; i < resultStr.size(); ++i)
    {
        cout << resultStr[i] << ' ';
    }

    cout << endl;

    for (int j = 0; j < resultStr.size(); ++j)
    {
        char resch = resultStr[j];
        resultStr.erase(resultStr.begin()+j);

        if(resultStr.find(resch) == string::npos && resultStr[resultStr.find(resch)] != resch)
        {
            cout << resch;
            break;
        }
        else
        {
            resultStr.insert(resultStr.begin()+j,resch);
        }
    }

    cout << endl;

    fin.close();

    if (!fin.is_open())
    {
        cout << "this file is missing";
    }
    else
    {
        cout << "this file is open";
    }

    return 0;
}















