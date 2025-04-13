#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


int main ()
{
    vector<string> words;
    for (string temp; cin >> temp; )
        words.push_back(temp);
    cout << "\nnr of words " << words.size() << '\n';
    ranges::sort(words);

    string disliked = "mondongo";

    for (int i = 0; i < words.size(); ++i)
    {
        if (i == 0 || words[i-1] != words[i])
        {
            if (words[i] == disliked)
                cout << i << "BLEEP" << '\n';
            else
                cout << i << words[i] << "\n";
        }
    }
}
