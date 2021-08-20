#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string question;
        cin >> question;
        int result = 0;
        int score = 1;

        for (int j = 0; j < question.length(); j++)
        {
            if (question[j] == 'X')
            {
                score = 1;
            }
            else
            {
                result += score;
                score++;
            }
        }

        cout << result << endl;
    }
}