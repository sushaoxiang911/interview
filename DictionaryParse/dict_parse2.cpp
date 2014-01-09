#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
    node()
    {
        is_word = false;
        for (int i = 0; i < 26; i++)
        {
            leaf.push_back(NULL);
        }
    };
    bool is_word;
    vector <node*> leaf;
};

int dict_parse (string sentence, string dict[], int size)
{
    // construct trie tree
    node root;
    root.is_word = false;
    // with memory leak, expected to be modified
    for (int i = 0; i < size; i++)
    {
        node* current = &root;
        for (int j = 0; j < dict[i].size(); j++)
        {
            if (current->leaf[dict[i][j]-'a'] == NULL)
            {
                current->leaf[dict[i][j]-'a'] = new node;
            }
            current = current -> leaf[dict[i][j]-'a'];
            if (j == dict[i].size()-1)
            {
                current -> is_word = true;
            }
        }
    }
    vector <int> DP (sentence.size()+1);
    for (int i = 0; i < sentence.size(); i++)
    {
        DP[i] = 0;        
    }
    DP[DP.size()-1] = 1;
    for(int i = sentence.size()-1; i >= 0; i--)
    {
        node* current = &root;
        for (int j = i; j < sentence.size(); j++)
        {
            if (current->leaf[sentence[j]-'a'] == NULL)
                break;
            current = current->leaf[sentence[j]-'a'];
            if (current->is_word == true)
            {
                DP[i] += DP[j+1];
            }
        }
    }
    return DP[0];
}
int main ()
{
    string sentence = "twitterisagoodplace";
    string dict[9];
    dict[0] = "twitter";
    dict[1] = "twit";
    dict[2] = "ter";
    dict[3] = "is";
    dict[4] = "i";
    dict[5] = "a";
    dict[6] = "good";
    dict[7] = "place";
    dict[8] = "goodplace";
    cout << dict_parse (sentence, dict, 9) << endl;
}


