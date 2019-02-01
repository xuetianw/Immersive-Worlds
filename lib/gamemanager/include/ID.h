
#ifndef WEBSOCKETNETWORKING_ID_H
#define WEBSOCKETNETWORKING_ID_H

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators



class ID {

public:

    ID();

    /**
    * Generate a random, unique uuid using a given random generator
    * @param generator: boost's uuid generator
    */
    ID(boost::uuids::random_generator &generator);

    boost::uuids::uuid getID() const;

private:
    boost::uuids::uuid _uuid;
};


#endif //WEBSOCKETNETWORKING_ID_H
