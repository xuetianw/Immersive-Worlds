//
// Created by Jan Ycasas on 2019-02-06.
//

#ifndef CHANNEL_MINIGAME_H
#define CHANNEL_MINIGAME_H

#include <vector>

namespace channel {
    class MiniGame {
        public:
            virtual bool execute();
            virtual void addUser(int id);
        private:
            std::vector<int> _users;

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