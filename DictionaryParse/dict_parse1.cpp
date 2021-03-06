#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dict_parse (string sentence, string dict[], int size)
{
    // Use DP to do that
    vector <int> DP(sentence.size() + 1);
    // init
    for (int i = 0; i < DP.size(); i++)
    {
        DP[i] = 0;
    }
    DP [0] = 1;
    
    for (int i = 0; i < sentence.size(); i++)
    {
        for (int j = 0; j < i+1; j++) // notice that there is no need to go from 0 to i+1, since we have already know the longest word in dictionary
        			      // that is the proper inner loop number: for (int j = 0; j < dict_word_maxlength; j++)
        			      // So the total complexity goes back to O(n)
        {
           // cout << "the substr is " << sentence.substr(j, i-j+1) << endl;
            for (int k = 0; k < size; k++)
            {
                if (sentence.substr(j, i-j+1) == dict[k])
                {
                    DP[i+1] += DP[j];
                }
            }
        }
    }
    return DP[DP.size()-1];
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

