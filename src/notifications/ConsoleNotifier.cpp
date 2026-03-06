//
// Created by lseli on 3/5/2026.
//

#include <iostream>
#include <format>

#include "../../include/notifications/ConsoleNotifier.h"

using std::cout;
using std::endl;
using std::format;

namespace notifications {
    void ConsoleNotifier::notity(string_view message) {
        cout << format("ConsoleNotifier: {}", message) << endl;
    }
}
