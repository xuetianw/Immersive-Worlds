//
// Created by Jan Ycasas on 2019-02-06.
//

#ifndef CHANNEL_MINIGAME_H
#define CHANNEL_MINIGAME_H

#include <vector>
#include <string>
#include <sstream>
#include "CusJson.h"

namespace models {
    class MiniGame {
    public:
        MiniGame();

        MiniGame(const CusJson::MiniGame& jsonMiniGame);

        /**
         * Checks the input of the user if it is correct.
         * @param answer
         * @return boolean. True if answer is correct.
         */
        bool checkAnswer(const int answer) const;

        /**
         * Print the current question
         * @return the string of the round
         */
        std::string printQuestion();

        /**
         * Advances the round. Returns true or false if there are no more remaining questions.
         */
        void nextRound();

        /**
         * Checks if the minigame has more rounds left.
         * @return true if there are more rounds
         */
        bool hasMoreRounds();

        /**
         * Reset the Minigame and make the rounds zero.
         */
        void resetMiniGame();
    private:
        /**
         * Get the current question
         * @return the question of the round
         */
        std::string getQuestion() const;

        /**
         * Get the list of possible answers in the round.
         * @return vector of possible answers
         */
        std::vector<std::string> getAnswers() const;

        int _id;
        int _roomId;
        std::string _type;
        std::vector<std::vector<std::string>> _answers;
        std::vector<std::string> _questions;
        std::vector<int> _correctAnswers;
        int _round;
        std::string _roomName;

    };
} // namespace channel

namespace channel {
    enum MiniGameType {
        MULTIPLE_CHOICE
    };
}

#endif //CHANNEL_MINIGAME_H
