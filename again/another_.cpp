#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

class Question {
private:
    string question;
    vector<string> options;
    char correctAnswer;

public:
    Question(string q, vector<string> opts, char ans) : question(q), options(opts), correctAnswer(ans) {}

    string getQuestion() const {
        return question;
    }

    vector<string> getOptions() const {
        return options;
    }

    char getCorrectAnswer() const {
        return correctAnswer;
    }
};

class QuestionBank {
private:
    vector<Question> questions;

public:
    void addQuestion(Question q) {
        questions.push_back(q);
    }

    vector<Question> getRandomQuestions(int num) {
        random_shuffle(questions.begin(), questions.end());
        return vector<Question>(questions.begin(), questions.begin() + num);
    }
};

class Exam {
private:
    QuestionBank questionBank;
    vector<Question> examQuestions;
    int timeLimit; // in seconds

public:
    Exam(int limit) : timeLimit(limit) {}

    void loadQuestionsFromFile(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Unable to open file!" << endl;
            return;
        }

        string q;
        while (getline(file, q)) {
            vector<string> options;
            char correctAns;
            file >> correctAns;

            file.ignore(); // Ignore the newline character after the correct answer
            string option;
            for (int i = 0; i < 4; ++i) {
                getline(file, option);
                options.push_back(option);
            }

            Question question(q, options, correctAns);
            questionBank.addQuestion(question);
        }

        file.close();
    }

    void conductExam() {
        cout << "Welcome to the Exam!\n";

        cout << "Loading questions...\n";
        examQuestions = questionBank.getRandomQuestions(5); // Change the number of questions as needed

        cout << "You have " << timeLimit << " seconds to complete the exam.\n";
        time_t startTime = time(nullptr);
        time_t endTime = startTime + timeLimit;

        int marks = 0;
        for (const Question &q : examQuestions) {
            cout << "\nQuestion: " << q.getQuestion() << endl;
            vector<string> options = q.getOptions();
            for (size_t i = 0; i < options.size(); ++i) {
                cout << static_cast<char>('A' + i) << ") " << options[i] << endl;
            }

            cout << "Your answer: ";
            char userAnswer;
            cin >> userAnswer;

            if (toupper(userAnswer) == toupper(q.getCorrectAnswer())) {
                ++marks;
            }
        }

        time_t currentTime = time(nullptr);
        int timeTaken = currentTime - startTime;

        cout << "\nTime taken: " << timeTaken << " seconds\n";
        cout << "Marks obtained: " << marks << "/" << examQuestions.size() << endl;
    }
};

int main() {
    Exam exam(300); // 300 seconds (5 minutes) time limit for the exam
    exam.loadQuestionsFromFile("E:\\IT workshop\\CP\\questions.txt"); // Replace 'questions.txt' with your file name
    exam.conductExam();

    return 0;
}
