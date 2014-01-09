#include <iostream>
#include <string>

using namespace std;

// expected to consider some corner cases such as spaces at the beginning of the sentence


void reverse_word (string &sentence, int begin, int end)
{
    while(1)
    {
        if (end <= begin)
            break;
        char temp = sentence[begin];
        sentence[begin] = sentence[end];
        sentence[end] = temp;
        end--;
        begin++;
    }
}

void reverse_word_order (string &sentence)
{
    reverse_word (sentence, 0, sentence.size()-1);
    int begin = 0;
    int end = 0;
    while (end != sentence.size() + 1)
    {
        if (sentence[end] == ' ' || end == sentence.size())
        {
            reverse_word (sentence, begin, end-1);
            begin = end + 1;
        }
        end++;
    }
}


int main()
{
    string sentence = "leading the way to retirement income certainty";
    reverse_word_order (sentence);
    cout << sentence << endl;
}
