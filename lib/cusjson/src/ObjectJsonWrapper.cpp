//
// Created by user on 3/4/19.
//

#include "ObjectJsonWrapper.h"

CusJson::ObjectJsonWrapper::ObjectJsonWrapper(int _objectId, int _roomId) : _objectJsonId(_objectId),
                                                                                  _roomJsonId(_roomId) {}

void CusJson::ObjectJsonWrapper::addObject(int objectId) {
    _containedObjectJsonIds.push_back(objectId);

}
