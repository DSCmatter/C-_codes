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
    Question(string text, vector<string> opts, char ans) : questionText(text), options(opts), correctAnswer(ans) {}

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
            string line;
            while (getline(file, line)) {
                string questionText = line;
                vector<string> options;
                char correctAnswer;
                for (int i = 0; i < 4; ++i) {
                    getline(file, line);
                    if (line[0] == '*') {
                        correctAnswer = 'A' + i;
                        line = line.substr(2); // Remove the '* ' marker
                    } else {
                        line = line.substr(3); // Remove the option marker (A), (B), etc.
                    }
                    options.push_back(line);
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
            char optionChar = 'A'; // Character for displaying options
            for (const string& option : options) {
            cout << optionChar << ") " << option << endl;
            optionChar++;
        }

            char userAnswer;
            cout << "Your answer (A/B/C/D): ";
            cin >> userAnswer;

            if (toupper(userAnswer) == question.getCorrectAnswer()) {
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
    questionBank.loadQuestionsFromFile("E:\\IT workshop\\CP\\questions.txt");

    Exam exam;
    exam.startExam(questionBank);

    return 0;
}
