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
    void ConsoleNotifier::notify(const string_view message) noexcept {
        cout << format("ConsoleNotifier: {}", message) << endl;
    }
}
