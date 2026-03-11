//
// Created by lseli on 3/6/2026.
//

#include <ostream>
#include <iostream>

#include "../../include/reporting/PaymentReport.h"

using std::ostream;

namespace reporting {
    void PaymentReport::recordPayment(const PaymentKind kind) {
        counts_[kind]++;
    }

    size_t PaymentReport::count(const PaymentKind kind) const {
        const auto it = counts_.find(kind);

        if (it == counts_.end()) {
            return 0;
        }

        return it->second;
    }

    void PaymentReport::print(ostream &os) const {
        for (const auto &[type, count]: counts_) {
            os << type << ": " << count << "\n";
        }
    }
}
