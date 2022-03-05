#include <string>

using namespace std;

class Question{
    private:
        string question;
        string options[4];
        string answer;
    public:
        Question(string question, string options[], string answer);
        friend ostream& operator<<(ostream& os, const Question& question);
        bool validate_answer(int user_answer);
};
