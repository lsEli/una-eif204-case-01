//
// Created by lseli on 3/5/2026.
//

#include <iostream>
#include <format>

#include "../../include/notifications/MultiNotifier.h"

using std::cout;
using std::endl;
using std::format;

namespace notifications {
    void MultiNotifier::notify(const string_view message) noexcept {
        for (const auto &target: this->targets_) {
            target.get().notify(message);
        }
    }
}
