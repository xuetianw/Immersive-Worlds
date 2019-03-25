//
// Created by asim on 25/03/19.
//

#ifndef WEBSOCKETNETWORKING_OBJECT_H
#define WEBSOCKETNETWORKING_OBJECT_H

#include "ID.h"

namespace models {
    class Object {
    public:
        Object(ID& id, bool isContainer) : _id(id), _isContainer(isContainer) {}

        const ID& getId() const;

        bool isContainer() const;

        Object* getParent() const;

        void setParent(Object* parent);

    private:
        ID _id;

        bool _isContainer;

        Object* _parent = nullptr;
    };
}

#endif //WEBSOCKETNETWORKING_OBJECT_H
