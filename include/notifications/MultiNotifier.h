//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_MULTINOTIFIER_H
#define UNA_EIF204_CASE_01_MULTINOTIFIER_H

#include <vector>

#include "INotifier.h"

using std::vector;

namespace notifications {
    class MultiNotifier final : public INotifier {
    public:
        MultiNotifier() = default;

        void notify(string_view message) override;

        ~MultiNotifier() override = default;

    private:
        vector<std::reference_wrapper<INotifier> > targets_;
    };
}

#endif //UNA_EIF204_CASE_01_MULTINOTIFIER_H
