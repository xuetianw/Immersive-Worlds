
#ifndef WEBSOCKETNETWORKING_ID_H
#define WEBSOCKETNETWORKING_ID_H

#include <boost/functional/hash.hpp> // boost hash
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators

using UUIDGen = boost::uuids::random_generator;
using UUID = boost::uuids::uuid;

class ID {
public:
    ID();

    explicit ID(int id);

    /**
    * Generate a random, unique uuid using a given random generator
    * @param generator: boost's uuid generator
    */
    explicit ID(UUIDGen& generator);

    const UUID& getID() const;

    bool operator==(const ID& other) const {
        return _uuid == other.getID();
    }

private:
    UUID _uuid;

    int _id;
};

template<>
struct std::hash<ID> {
    std::size_t operator()(const ID& id) const {
        return boost::hash<UUID>()(id.getID());
    }
};

#endif //WEBSOCKETNETWORKING_ID_H
