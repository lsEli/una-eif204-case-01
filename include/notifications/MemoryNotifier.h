//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_MEMORYNOTIFIER_H
#define UNA_EIF204_CASE_01_MEMORYNOTIFIER_H

#include <vector>
#include <string>

#include "INotifier.h"

using std::vector;
using std::string;

namespace notifications {

    class MemoryNotifier final : public INotifier {
    public:
        MemoryNotifier() = default;

        void notity(string_view message) override;

        ~MemoryNotifier() override = default;
    private:
        vector<string> messages_;
    };

}

#endif //UNA_EIF204_CASE_01_MEMORYNOTIFIER_H