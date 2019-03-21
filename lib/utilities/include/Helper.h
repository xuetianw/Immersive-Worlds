#ifndef WEBSOCKETNETWORKING_HELPER_H
#define WEBSOCKETNETWORKING_HELPER_H

#include <iostream>
#include <vector>
#include <sstream>

namespace helper {

    /**
     * Converts a vector to a comma separated string of values
     * TODO use generics to make this more generalized
     * @param list
     * @return
     */
    std::string convertListToString(std::vector<std::string> list, std::string_view delimiter = ", ");
}

#endif //WEBSOCKETNETWORKING_HELPER_H
