#include "Helper.h"

std::string helper::convertListToString(std::vector<std::string> list, std::string_view delimiter) {
    std::ostringstream out;
    if (!list.empty()) {
        std::copy(list.begin(),
                  list.end() - 1,
                  std::ostream_iterator<std::string>(out, std::string(delimiter).c_str())
        );
        out << list.back();
    }

    std::string result(out.str());
    return result;
}
