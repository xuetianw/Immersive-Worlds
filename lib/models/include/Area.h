//
// Created by Jan Ycasas on 2019-01-24.
//

#ifndef MODELS_AREA_H
#define MODELS_AREA_H

#include <string>

#include "ID.h"

namespace models {
    class Area {
        public:
            explicit Area(ID id) : _id(id) {}

            std::string getName() {
                return _name;
            }

            const ID& getId() const {
                return _id;
            }

        private:
            ID _id;

            std::string _name;
    };
} // namespace models

#endif //MODELS_AREA_H