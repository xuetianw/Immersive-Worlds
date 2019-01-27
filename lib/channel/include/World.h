//
// Created by Jan Ycasas on 2019-01-24.
//

#ifndef CHANNEL_WORLD_H
#define CHANNEL_WORLD_H

#include <unordered_map>
#include <Area.h>

namespace channel {
    class World {
        public:
            World();
            ~World();

            /**
             * Gets the Id of the area
             * 
             * @returns the id of the area
             */
            int getId() const;

            /**
             * Adds a new area to the unordered_map.
             * 
             * @param Area area: room object that will be added to the map
             * 
             * @returns true = inserted in the map. false = id already exists in map
             */
            bool addArea(Area area);

        private:
            const int _id = 0; //TODO make world id unique
            std::unordered_map<int, Area> _areas;
    };
} // namespace channel

#endif //CHANNEL_WORLD_H