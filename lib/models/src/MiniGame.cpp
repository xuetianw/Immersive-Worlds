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
        _questions(jsonMiniGame._questions) {

}

void MiniGame::addAnswer(std::string answer) {
    _answers.push_back(answer);
}

void MiniGame::addQuestion(std::string question) {
    //_questions.push_back(question);
    _questions = question;
}

void MiniGame::addCorrectAnswer(int correctAnswer) {
    //_correctAnswers.push_back(correctAnswer);
    _correctAnswers = correctAnswer;
}

bool MiniGame::checkAnswer(const int answer) const {
    //return answer == _correctAnswers.at(_round);
    return answer == _correctAnswers;
}

std::string MiniGame::getQuestion() const {
    //return _questions.at(_round);
    return _questions;
}

std::vector<std::string> MiniGame::getAnswers() const {
    return _answers;
}

std::string MiniGame::printQuestion() {
    std::stringstream ss;
    ss << getQuestion() << std::endl;

    std::vector<std::string> questions = getAnswers();

    char letter = 'a';
    for (int i = 0; i < questions.size(); i++, letter++) {
        std::string question = questions.at(i);

        ss << letter << ") " << question << std::endl;
    }

    return ss.str();
}

bool MiniGame::nextRound() {
    // TODO: NEEDS TO BE CALLED HEARTBEATS
    _round++;
    return _round == _questions.size();
}
