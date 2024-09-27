#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

class Question {
private:
    std::string questionText;
    std::vector<std::string> options;
    int correctOption;

public:
    Question(const std::string& qText, const std::vector<std::string>& opts, int correctOpt)
        : questionText(qText), options(opts), correctOption(correctOpt) {}

    const std::string& getQuestionText() const {
        return questionText;
    }

    const std::vector<std::string>& getOptions() const {
        return options;
    }

    int getCorrectOption() const {
        return correctOption;
    }
};

class QuestionBank {
private:
    std::vector<Question> questions;
    int currentQuestionIndex;

public:
    QuestionBank() : currentQuestionIndex(0) {}

    void loadQuestionsFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::string questionText = line;
            std::vector<std::string> options;
            int correctOption;

            // Read options
            for (int i = 0; i < 4; ++i) {
                std::getline(file, line);
                options.push_back(line);
            }

            // Read correct option
            std::getline(file, line);
            correctOption = std::stoi(line);

            // Create question object and add to the question bank
            Question newQuestion(questionText, options, correctOption);
            questions.push_back(newQuestion);
        }

        file.close();
    }

    void shuffleQuestions() {
        std::random_shuffle(questions.begin(), questions.end());
    }

    Question getNextQuestion() {
        if (currentQuestionIndex < questions.size()) {
            return questions[currentQuestionIndex++];
        } else {
            // If no more questions, return an empty question
            return Question("", {}, -1);
        }
    }
};

int main() {
    QuestionBank questionBank;
    questionBank.loadQuestionsFromFile("questions.txt");
    questionBank.shuffleQuestions();

    int marks = 0;
    int totalTime = 0;

    std::clock_t start = std::clock();

    while (true) {
        Question currentQuestion = questionBank.getNextQuestion();
        if (currentQuestion.getQuestionText() == "") {
            break; // No more questions
        }

        std::cout << "Question: " << currentQuestion.getQuestionText() << std::endl;

        const std::vector<std::string>& options = currentQuestion.getOptions();
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << i + 1 << ". " << options[i] << std::endl;
        }

        int userAnswer;
        std::cout << "Your answer (1-4): ";
        std::cin >> userAnswer;

        if (userAnswer == currentQuestion.getCorrectOption()) {
            marks++;
        }
    }

    std::clock_t end = std::clock();
    totalTime = static_cast<int>((end - start) / (CLOCKS_PER_SEC / 60)); // Calculate time in seconds

    std::cout << "Total marks obtained: " << marks << std::endl;
    std::cout << "Total time taken: " << totalTime << " minutes" << std::endl;

    return 0;
}
