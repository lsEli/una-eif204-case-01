//
// Created by lseli on 3/5/2026.
//

#include <iostream>
#include <format>

#include "../../include/notifications/MemoryNotifier.h"

using std::cout;
using std::endl;
using std::format;

namespace notifications {
    void MemoryNotifier::notify(string_view message) {
        cout << format("MemoryNotifier: {}", message) << endl;
    }
}
