//
// Created by Jan Ycasas on 2019-02-06.
//

#include "MiniGame.h"

using channel::MiniGame;

MiniGame::MiniGame(std::string question, int answer) : _question(question), _correctAnswer(answer) { }

void MiniGame::addAnswer(std::string answer) {
    _answers.push_back(answer);
}

bool MiniGame::checkAnswer(int answer) { 
    return answer == _correctAnswer;
}

std::string MiniGame::getQuestion() {
    return _question;
}

std::vector<std::string> MiniGame::getAnswers() {
    return _answers;
}
