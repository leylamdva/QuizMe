#include "Question.h"
#include <string>
#include <iostream>

using namespace std;

Question::Question(string question, string options[], string answer){
    this->question = question;
    for (int i = 0; i < 4; i++){
        this->options[i] = options[i];
    }
    this->answer = answer;
}

ostream& operator<<(ostream& os, const Question& question){
    os << question.question << endl;
    os << "Options:" << endl;
    for (int i = 0; i < 4; i++)
    {
        os << i + 1 << ") " << question.options[i] <<  endl;
    }
    return os;
}

bool Question::validate_answer(int user_answer){
    return options[user_answer - 1] == answer;
}