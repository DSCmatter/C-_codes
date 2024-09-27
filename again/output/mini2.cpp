#include <iostream>
#include <fstream>
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
    Question(const string& ques, const vector<string>& opts, int correct) : question(ques), options(opts), correctOption(correct) {}

    void display() const {
        cout << question << endl;
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(int choice) const {
        return choice == correctOption;
    }
};

class QuestionBank {
private:
    vector<Question> questions;

public:
    void loadQuestions(const string& fileName) {
        ifstream file(fileName);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                string questionText = line;
                vector<string> options;
                for (int i = 0; i < 4; ++i) {
                    getline(file, line);
                    options.push_back(line);
                }
                int correctOption;
                file >> correctOption;
                file.ignore(); // ignore newline
                questions.emplace_back(questionText, options, correctOption);
            }
            file.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }

    void conductExam() {
        random_shuffle(questions.begin(), questions.end());
        int score = 0;
        time_t startTime = time(nullptr);
        for (const auto& q : questions) {
            q.display();
            cout << "Enter your choice (1-4): ";
            int choice;
            cin >> choice;
            if (q.checkAnswer(choice)) {
                score++;
            }
        }
        time_t endTime = time(nullptr);
        int timeTaken = static_cast<int>(difftime(endTime, startTime));
        cout << "\nExam finished!\n";
        cout << "Time taken: " << timeTaken << " seconds\n";
        cout << "Score: " << score << "/" << questions.size() << endl;
    }
};

int main() {
    QuestionBank questionBank;
    questionBank.loadQuestions("E:\\IT workshop\\CP\\questions.txt");
    questionBank.conductExam();
    return 0;
}
