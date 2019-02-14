//
// Created by Jan Ycasas on 2019-01-24.
//

#ifndef CHANNEL_AREA_H
#define CHANNEL_AREA_H

#include <unordered_map>
#include <Room.h>

using std::unordered_map;

namespace channel {
    class Area {
        public:
            Area(int id);
            Area(const CusJson::Area& jsonArea);
            string getName();

      Area();

      ~Area();

            /**
             * Gets the Id of the area
             * 
             * @returns the id of the area
             */
            int getId() const;

            /**
             * Adds a new area to the unordered_map.
             * 
             * @param Room room: room object that will be added to the map
             * 
             * @returns true = inserted in the map. false = id already exists in map
             */
            bool addRoom(const Room &room);

            Room getRoom(const RoomId &roomId);
      vector<Room> tempRoomContainer;
        private:
            int _id = 0; //TODO make area id unique
            unordered_map<int, Room> _rooms;
            string _name;
    };
} // namespace channel

#endif //CHANNEL_AREA_H