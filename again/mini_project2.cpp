#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Question {
private:
    string questionText;
    vector<string> options;
    char correctAnswer;

public:
    Question(string text, vector<string> opts, char ans)
        : questionText(text), options(opts), correctAnswer(ans) {}

    string getQuestionText() const {
        return questionText;
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
    void loadQuestionsFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string questionText;
            while (getline(file, questionText)) {
                vector<string> options;
                string option;
                for (int i = 0; i < 4; ++i) { // Read 4 options
                    getline(file, option);
                    options.push_back(option);
                }
                string answer;
                getline(file, answer); // Read the line with the correct answer
                char correctAnswer;
                for (size_t i = 0; i < answer.size(); ++i) {
                    if (answer[i] == '*') {
                        correctAnswer = 'A' + i;
                        break;
                    }
                }
                questions.emplace_back(questionText, options, correctAnswer);
            }
            file.close();
        } else {
            cerr << "Unable to open file." << endl;
        }
    }

    vector<Question> getQuestions() const {
        return questions;
    }
};

class Exam {
private:
    vector<Question> questions;

public:
    void startExam(const QuestionBank& questionBank) {
        questions = questionBank.getQuestions();
        random_shuffle(questions.begin(), questions.end());
        time_t startTime = time(NULL);

        int score = 0;
        for (const auto& question : questions) {
            cout << "Question: " << question.getQuestionText() << endl;
            vector<string> options = question.getOptions();
            for (size_t i = 0; i < options.size(); ++i) {
                cout << static_cast<char>('A' + i) << ") " << options[i] << endl;
            }
            char userAnswer;
            cout << "Your answer (A/B/C/D): ";
            cin >> userAnswer;

            if (toupper(userAnswer) == question.getCorrectAnswer() || userAnswer == question.getCorrectAnswer()) {
                score++;
            }
        }

        time_t endTime = time(NULL);
        double timeTaken = difftime(endTime, startTime);
        cout << "Exam completed in " << timeTaken << " seconds." << endl;
        cout << "Your score: " << score << "/" << questions.size() << endl;
    }
};

int main() {
    QuestionBank questionBank;
    questionBank.loadQuestionsFromFile("E:\\IT workshop\\CP\\questions.txt"); // Update with your file path
    
    Exam exam;
    exam.startExam(questionBank);

    return 0;
}
