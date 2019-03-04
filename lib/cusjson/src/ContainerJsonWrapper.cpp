//
// Created by user on 3/4/19.
//

#include <ContainerJsonWrapper.h>

#include "ContainerJsonWrapper.h"

CusJson::ContainerJsonWrapper::ContainerJsonWrapper(int _objectId, int _roomId) : _objectId(_objectId),
                                                                                  _roomId(_roomId) {}

void CusJson::ContainerJsonWrapper::addObject(int objectId) {
    _containedObjectIds.push_back(objectId);

}
