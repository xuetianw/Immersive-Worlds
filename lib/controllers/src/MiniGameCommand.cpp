//
// Created by Jan Ycasas on 14/02/19.
//

#include "MiniGameCommand.h"

networking::Message MiniGameCommand::execute(GameService& service) {
    //auto message = networking::Message();
    //message.text = "YO WAT UP";
    return networking::Message{3, "IN MINIGAME"};
}

networking::Message MiniGameCommand::test(GameService& service, const Message& message) {
    //auto message = networking::Message();
    //message.text = "YO WAT UP";

    /*
    if(ClientManager::isClientPromptingLogin(message.connection)){
        return networking::Message{message.connection.id, "LOGGED IN"};
    }
    return networking::Message{message.connection.id, "NOT LOGGED IN"};
    */

    //return networking::Message{3, "IN MINIGAME"};
}