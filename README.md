# QuizMe
I wanted a better way to prepare for exams 

## C++ Version:

- Takes CSV file as input
- Takes name of the file as parameter (once compiled, should be run as "./'name of exe' 'name of csv file'")
- The questions will be asked in a random order
- If a wrong answer is given, the question will be repeated until the correct answer is chosen

### CSV File Format

* Each question has to have 4 answer options
* There can only be one correct answer
* Each line is a sepatate question
* Questions should be written as follows:
    - 'Question','Option1','Option2','Option3','Option4','Answer'
* Answer should match one of the options
