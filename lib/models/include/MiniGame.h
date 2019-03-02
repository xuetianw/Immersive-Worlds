//
// Created by Jan Ycasas on 2019-02-06.
//

#ifndef CHANNEL_MINIGAME_H
#define CHANNEL_MINIGAME_H

#include <Room.h>
#include <vector>
#include <sstream>

using std::unordered_map;

namespace channel {
    class MiniGame {
        public:
            MiniGame();

            /**
             * Add possible answers.
             * @param answer
             */
            void addAnswer(std::string answer);

            /**
             * Add Questions to the multiple choice game.
             * @param question
             */
            void addQuestion(std::string question);

            /**
             * add the correct answer for the given round
             * @param answer
             */
            void addCorrectAnswer(int answer);

            /**
             * Checks the input of the user if it is correct.
             * @param answer
             * @return boolean. True if answer is correct.
             */
            bool checkAnswer(const int answer) const;

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

            /**
             * Print the current question
             * @return the string of the round
             */
            std::string printQuestion();

            /**
             * Advances the round. Returns true or false if there are no more remaining questions.
             * @return boolean. True if no more rounds.
             */
            bool nextRound();
        private:
            std::vector<std::string> _answers;
            std::vector<std::string> _questions;
            std::vector<int> _correctAnswers;
            int _round;

    };
} // namespace channel

/*
    - Rewards based on level of difficulty

    - Possible MINI GAME IDEAS:
        - multiple choice
            - one question
            - give users options
            - one option is the correct choice
            - If answer is correct
                - get a random boost in one stat

        - Gambling
            - roll a die
            - guess the right number
            - wager an item or stat.
                - if the number is correct = double the stat 
                - if wrong lost the stat
                
        - Matching (Memory)
            - show a nxm matrix, show the values
            - tell to memorize as much as they can in a span of 3 secs
            - write the indicies of the values
    
    - Possible Implementation Ideas:
        - MiniGame Manager
        - polymorphism
            - Interface where it has the necessary functions (insertAnswer, checkAnswer)
            - https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm
    
*/

#endif //CHANNEL_MINIGAME_H