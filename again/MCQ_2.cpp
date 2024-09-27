#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Question {
private:
    string question;
    vector<string> options;
    int correctOption;

public:
    Question(const string& q, const vector<string>& opts, int correct)
        : question(q), options(opts), correctOption(correct) {}

    string getQuestion() const {
        return question;
    }

    vector<string> getOptions() const {
        return options;
    }

    int getCorrectOption() const {
        return correctOption;
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
                int correctOption;

                for (int i = 0; i < 4; ++i) {
                    getline(file, line);
                    options.push_back(line);
                }
                getline(file, line);
                correctOption = stoi(line);

                Question q(questionText, options, correctOption);
                questions.push_back(q);
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    vector<Question> getRandomQuestions(int numQuestions) const {
        vector<Question> selectedQuestions = questions;
        random_shuffle(selectedQuestions.begin(), selectedQuestions.end());
        if (numQuestions < selectedQuestions.size()) {
            selectedQuestions.resize(numQuestions);
        }
        return selectedQuestions;
    }
};

int main() {
    QuestionBank questionBank;
    questionBank.loadQuestionsFromFile("E:\\IT workshop\\CP\\questions.txt");

    vector<Question> selectedQuestions = questionBank.getRandomQuestions(10);

    time_t start = time(0);

    int score = 0;
    for (const auto& question : selectedQuestions) {
        cout << question.getQuestion() << endl;
        vector<string> options = question.getOptions();
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
        cout << "Enter your choice (1-4): ";
        int choice;
        cin >> choice;

        if (choice == question.getCorrectOption()) {
            ++score;
        }
    }

    time_t end = time(0);
    int timeTaken = static_cast<int>(end - start);

    cout << "You scored " << score << " out of " << selectedQuestions.size() << " in " << timeTaken << " seconds." << endl;

    return 0;
}
