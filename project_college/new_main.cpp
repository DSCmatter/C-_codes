#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Class to represent a single MCQ question
class MCQuestion {
private:
    string question;
    vector<string> options;
    int correctAnswer;

public:
    MCQuestion() {}

    MCQuestion(string q, vector<string> opts, int correct) {
        question = q;
        options = opts;
        correctAnswer = correct;
    }

    string getQuestion() const {
        return question;
    }

    vector<string> getOptions() const {
        return options;
    }

    int getCorrectAnswer() const {
        return correctAnswer;
    }
};

// Class for handling the question bank and exam
class QuestionBank {
private:
    vector<MCQuestion> questions;

public:
    void addQuestion(const MCQuestion& question) {
        questions.push_back(question);
    }

    MCQuestion getRandomQuestion() const {
        int index = rand() % questions.size();
        return questions[index];
    }

    int getTotalQuestions() const {
        return questions.size();
    }
};

// Function to load questions from a file
void loadQuestionsFromFile(const string& filename, QuestionBank& questionBank) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string q = line;
            vector<string> opts;
            for (int i = 0; i < 4; ++i) {
                getline(file, line);
                opts.push_back(line);
            }
            int correct;
            file >> correct;
            file.ignore(); // Ignore newline character
            MCQuestion mcq(q, opts, correct);
            questionBank.addQuestion(mcq);
        }
        file.close();
    } else {
        cout << "Unable to open file.";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    QuestionBank questionBank;
    loadQuestionsFromFile("E:\\IT workshop\\CP\\questions.txt", questionBank);

    int totalQuestions = questionBank.getTotalQuestions();
    int questionsToAsk = min(totalQuestions, 5); // Let's ask 5 questions

    time_t startTime = time(nullptr);

    int score = 0;
    for (int i = 0; i < questionsToAsk; ++i) {
        MCQuestion question = questionBank.getRandomQuestion();
        cout << "Question " << i + 1 << ": " << question.getQuestion() << endl;

        vector<string> options = question.getOptions();
        for (size_t j = 0; j < options.size(); ++j) {
            cout << j + 1 << ". " << options[j] << endl;
        }

        int userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;

        if (userAnswer == question.getCorrectAnswer()) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect." << endl;
        }
        cout << endl;
    }

    time_t endTime = time(nullptr);
    int timeTaken = endTime - startTime;

    cout << "Test completed!" << endl;
    cout << "Time taken: " << timeTaken << " seconds" << endl;
    cout << "Your score: " << score << "/" << questionsToAsk << endl;

    return 0;
}
