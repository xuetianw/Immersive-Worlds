//
// Created by Jan Ycasas on 2019-02-06.
//

#include "MiniGame.h"

using models::MiniGame;

MiniGame::MiniGame() {
    _round = 0;
}

MiniGame::MiniGame(const CusJson::MiniGame& jsonMiniGame) :
        _id(jsonMiniGame._id), _roomId(jsonMiniGame._roomId), _type(jsonMiniGame._type),
        _answers(jsonMiniGame._possibleAnswers), _correctAnswers(jsonMiniGame._correctAnswers),
        _questions(jsonMiniGame._questions), _roomName(jsonMiniGame._roomName) { 
            _round = 0;
        }

bool MiniGame::checkAnswer(const int answer) const {
    return answer == _correctAnswers.at(_round);
}

std::string MiniGame::getQuestion() const {
    return _questions.at(_round);
}

std::vector<std::string> MiniGame::getAnswers() const {
    return _answers.at(_round);
}

std::string MiniGame::printQuestion() {
    std::stringstream ss;
    ss << getQuestion() << std::endl;

    std::vector<std::string> answers = getAnswers();

    char letter = 'a';
    for (unsigned i = 0; i < answers.size(); i++, letter++) {
        std::string answer = answers.at(i);

        ss << letter << ") " << answer << std::endl;
    }

    return ss.str();
}

void MiniGame::nextRound() {
    _round++;
}

bool MiniGame::hasMoreRounds() {
    return _round < _questions.size();
}

void MiniGame::resetMiniGame() {
    _round = 0;
}
