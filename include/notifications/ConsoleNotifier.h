//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_CONSOLENOTIFIER_H
#define UNA_EIF204_CASE_01_CONSOLENOTIFIER_H

#include "INotifier.h"

namespace notifications {
    class ConsoleNotifier final : public INotifier {
    public:
        ConsoleNotifier() = default;

        void notify(string_view message) noexcept override;

        ~ConsoleNotifier() override = default;
    };
}

#endif //UNA_EIF204_CASE_01_CONSOLENOTIFIER_H
