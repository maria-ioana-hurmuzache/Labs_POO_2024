#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

set<char> delimiters = { ' ', ',', '?', '!', '.' };

vector<string> get_words(const string& str)
{
    vector<string> words;
    string word;

    for (size_t i = 0; i < str.size(); ++i) {
        char c = tolower(str[i]);
        if (delimiters.find(c) == delimiters.end())
        {
            word += c;
        }
        else
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
    }

    if (!word.empty()) //ultimul cuvant
    {
        words.push_back(word);
    }

    return words;
}

class Comparator
{
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const
    {
        if (a.second == b.second)
        {
            return a.first > b.first; //cuvintele apar de acelasi numar de ori
        }
        return a.second < b.second; //un cuvant apare de mai multe ori decat celalalt
    }
};

int main()
{
    ifstream file("file.txt");
    if (!file.is_open())
    {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    string phrase;
    getline(file, phrase);
    file.close();

    vector<string> words = get_words(phrase);

    map<string, int> word_count;
    for (int i=0; i < words.size(); i++)
    {
        if (word_count.count(words[i]) != 0)
        {
            word_count[words[i]]++;
        }
        else
        {
            word_count[words[i]]=1;
        }
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Comparator> word_priority_queue;

    for (auto i=word_count.begin(); i!=word_count.end(); i++)
    {
        word_priority_queue.push(pair<string, int>(i->first, i->second));
    }

    //afisare coada cu prioritati
    while (!word_priority_queue.empty())
    {
        cout << word_priority_queue.top().first << " => " << word_priority_queue.top().second << '\n';
        word_priority_queue.pop();
    }

    return 0;
}
