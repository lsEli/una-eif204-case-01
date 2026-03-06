//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_INOTIFIER_H
#define UNA_EIF204_CASE_01_INOTIFIER_H

#include <string_view>

using std::string_view;

namespace notifications {
    class INotifier {
    public:
        virtual void notity(string_view message) = 0;

        virtual ~INotifier() = default;
    };
}

#endif //UNA_EIF204_CASE_01_INOTIFIER_H
