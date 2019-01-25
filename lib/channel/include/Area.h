//
// Created by Jan Ycasas on 2019-01-24.
//

#ifndef CHANNEL_AREA_H
#define CHANNEL_AREA_H

#include <unordered_map>
#include <Room.h>

namespace channel {
    class Area {
        public:
            Area();
            ~Area();

            /**
             * Gets the Id of the area
             * 
             * @returns the id of the area
             */
            int getId() const;

            /**
             * Adds a new room to the unordered_map.
             * 
             * @param Room newRoom: room object that will be added to the map
             * 
             * @returns true = inserted in the map. false = id already exists in map
             */
            bool addRoom(Room newRoom);

        private:
            const int _id = 0; //TODO make room id unique
            std::unordered_map<int, Room> _rooms;
    };
} // namespace channel

#endif //CHANNEL_AREA_H