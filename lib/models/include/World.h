//
// Created by Jan Ycasas on 2019-01-24.
//

#ifndef MODELS_WORLD_H
#define MODELS_WORLD_H

#include "ID.h"

namespace models {
    class World {
        public:
            explicit World(ID id) : _id(id) {}

            /**
             * Gets the Id of the area
             * 
             * @returns the id of the area
             */
            const ID& getId() const {
                return _id;
            }

        private:
            ID _id;
    };
} // namespace models

#endif //MODELS_WORLD_H