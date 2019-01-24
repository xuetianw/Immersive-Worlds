//
// Created by vinshit on 24/01/19.
//

#include "Server.h"

using networking::Connection;


// Dummy Structs
class DumbClientManager{
private:

public:
  virtual bool login();
  virtual bool addConnection(Connection connection);
  virtual bool removeConnection(Connection connection);
  virtual bool isLoggedIn(Connection connection);
};

class DumbGameManager{
public:
  virtual Message updateGame(User user, Message message);
};

class User{
private:Dummy Structs
class DumbClientManager{
private:

public:
  virtual bool login();
  virtual bool addConnection(Connection connection);
  virtual bool removeConnection(Connection connection);
  virtual bool isLoggedIn(Connection connection);
};
  Connection connection;
  std::string password;

};

DumbClientManager clientManager;
DumbGameManager gameManager;

//TODO: decide to make a User <-> UserCharacter Map/make an interpreter class to conver/
void onConnect(Connection c) {
  std::cout << "New connection found: " << c.id << "\n";
  clientManager.addConnection(c);
}

void onDisconnect(Connection c) {
  std::cout << "Connection lost: " << c.id << "\n";
  clientManager.removeConnection(c);
//  auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
//  clients.erase(eraseBegin, std::end(clients));
//  TO DO: Handle User information on disconnect
}

//
std::deque<Message> processMessages (Server &server,
        const std::deque<Message> &incoming,
        bool &quit) {
  std::deque<Message> result;
  for (auto& message : incoming) {
    if(!DumbClientManager.isLoggedin(message.id){
      // TODO: Define the design for this ! !
      result.push_back(DumbClientManager.tryLogin(message));
    } if (message.text == "quit") {
      server.disconnect(message.connection);
    } else if (message.text == "shutdown") {
      std::cout << "Shutting down.\n";
      quit = true;
    } else {
      User user = clientManager.getUser(message.connection);
      std::string gameManager.updateGame(user, message);
    }
  }
  return result.str();
}

std::deque<Message> buildOutgoing(const std::string& log) {
  std::deque<Message> outgoing;
  for (auto client : clients) {
    outgoing.push_back({client, log});
  }
  return outgoing;
}


std::string
getHTTPMessage(const char* htmlLocation) {
  if (access(htmlLocation, R_OK ) != -1) {
    std::ifstream infile{htmlLocation};
    return std::string{std::istreambuf_iterator<char>(infile),
                       std::istreambuf_iterator<char>()};

  } else {
    std::cerr << "Unable to open HTML index file:\n"
              << htmlLocation << "\n";
    std::exit(-1);
  }
}


int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
              << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
    return 1;
  }

  bool done = false;
  unsigned short port = std::stoi(argv[1]);
  Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};

  while (!done) {
    try {
      server.update();
    } catch (std::exception& e) {
      std::cerr << "Exception from Server update:\n"
                << " " << e.what() << "\n\n";
      done = true;
    }

    auto incoming = server.receive();
    auto log      = processMessages(server, incoming, done);
    auto outgoing = buildOutgoing(log);
    server.send(outgoing);
    sleep(1);
  }

  return 0;
}
