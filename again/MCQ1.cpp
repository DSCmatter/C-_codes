#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Define a class for a single question
class Question {
private:
    string questionText;
    vector<string> options;
    char correctAnswer;
public:
    Question(string qText, vector<string> opts, char correct)
        : questionText(qText), options(opts), correctAnswer(correct) {}

    string getQuestion() const {
        return questionText;
    }

    void displayOptions() const {
        char option = 'A';
        for (const string& opt : options) {
            cout << option << ") " << opt << endl;
            option++;
        }
    }

    bool isCorrect(char choice) const {
        return toupper(choice) == toupper(correctAnswer);
    }
};

// Define a class for the question bank
class QuestionBank {
private:
    vector<Question> questions;
public:
    void loadQuestionsFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                string qText = line;
                vector<string> opts;
                for (int i = 0; i < 4; ++i) {
                    getline(file, line);
                    opts.push_back(line);
                }
                char correct;
                file >> correct;
                file.ignore(); // Ignore newline after correct answer
                questions.emplace_back(qText, opts, correct);
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void conductExam() {
        srand(static_cast<unsigned int>(time(nullptr)));
        int totalQuestions = questions.size();
        int score = 0;

        time_t startTime = time(nullptr);
        time_t currentTime = startTime;

        for (int i = 0; i < totalQuestions; ++i) {
            int index = rand() % totalQuestions;
            Question currentQ = questions[index];

            cout << "Question " << i + 1 << ":\n";
            cout << currentQ.getQuestion() << endl;
            currentQ.displayOptions();

            cout << "Your answer (A/B/C/D): ";
            char choice;
            cin >> choice;

            if (currentQ.isCorrect(choice)) {
                cout << "Correct answer!\n";
                score++;
            } else {
                cout << "Wrong answer!\n";
            }
            cout << "----------------------------\n";
        }

        time_t endTime = time(nullptr);
        double totalTime = difftime(endTime, startTime);
        cout << "Exam completed in " << totalTime << " seconds.\n";
        cout << "You scored: " << score << " out of " << totalQuestions << endl;
    }
};

int main() {
    QuestionBank qBank;
    qBank.loadQuestionsFromFile("E:\\IT workshop\\CP\\questions.txt");
    qBank.conductExam();

    return 0;
}
