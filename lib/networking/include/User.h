//
// Created by vinshit on 24/01/19.
//

#ifndef WEBSOCKETNETWORKING_USER_H
#define WEBSOCKETNETWORKING_USER_H


class User{
private:
  Connection connection;
  std::string const password;
  std::string const username;
public:
  std::string const id;
};


#endif //WEBSOCKETNETWORKING_USER_H
