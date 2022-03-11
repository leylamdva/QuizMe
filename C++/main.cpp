#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <ctime>
#include "Question.cpp"

using namespace std;

int print_question(Question& question, int index);

int main(int argc, char const *argv[])
{
    if(argc != 2){
        cerr << "Wrong number of arguments" << endl;
        exit(1);
    }

    ifstream input_file(argv[1]);
    //Error if file could not be opened
    if(!input_file){
        cerr << "Cannot open file" << endl;
        exit(1);
    }

    vector<Question> questions;

    //Reading the questions
    while(!input_file.eof()){
        string question_content, answer;
        string options[4];
        getline(input_file, question_content, ',');
        for (int i = 0; i < 4; i++)
        {
            getline(input_file, options[i], ',');
        }
        getline(input_file, answer);

        Question question(question_content, options, answer);
        questions.push_back(question);
    }

    vector<Question>::iterator ptr = questions.begin();

    input_file.close();

    srand(time(NULL));
    int random_question_index;
    int question_number = 0;
    
    //Asking questions in random order
    while(questions.size() != 0){
        random_question_index = rand() % questions.size();
        //Set iterator to start
        ptr = questions.begin();
        advance(ptr, random_question_index);

        int user_answer = print_question(questions[random_question_index], question_number);

        //If the answer is wrong, the question will be repeated until a correct answer is given
        while(!questions[random_question_index].validate_answer(user_answer)){
            cout << '\n' << "Wrong! Try again." << '\n' << endl;
            user_answer = print_question(questions[random_question_index], question_number);
        }
            
        cout << '\n' << "Correct!" << '\n' << endl;

        questions.erase(ptr);
    }
    cout << "End of Quiz" << endl;

    return 0;
}

int print_question(Question& question, int index){
    int user_answer;
    cout << "Question" << index + 1 << ":";
    cout << question << endl;
    cout << "Your answer: " << endl;
    cin >> user_answer;

    return user_answer;
}
