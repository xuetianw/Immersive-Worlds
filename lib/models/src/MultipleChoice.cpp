//
// Created by Jan Ycasas on 2019-02-06.
//

#include "MultipleChoice.h"

using channel::MultipleChoice;

MultipleChoice::MultipleChoice() { 
    _round = 0;
}

void MultipleChoice::addAnswer(std::string answer) {
    _answers.push_back(answer);
}

void MultipleChoice::addQuestion(std::string question) {
    _questions.push_back(question);
}

void MultipleChoice::addCorrectAnswer(int correctAnswer) { 
    _correctAnswers.push_back(correctAnswer);
}

bool MultipleChoice::checkAnswer(const int answer) const{ 
    return answer == _correctAnswers.at(_round);
}

std::string MultipleChoice::getQuestion() const {
    return _questions.at(_round);
}

std::vector<std::string> MultipleChoice::getAnswers() const {
    return _answers;
}

std::string MultipleChoice::printQuestion() {
    std::stringstream ss;
    ss << getQuestion() << std::endl;
    
    std::vector<std::string> answers = getAnswers();

    char letter = 'a';
    for(int i = 0; i < answers.size(); i++, letter++) {
        auto answer = answers.at(i);

        ss << letter << ") " << answer << std::endl; 
    }

    return ss.str();
}

bool MultipleChoice::nextRound() {
    // TODO: NEEDS TO BE CALLED HEARTBEATS
    _round++;
    return _round == _questions.size();
}

std::string MultipleChoice::execute() {
    return printQuestion();
}

