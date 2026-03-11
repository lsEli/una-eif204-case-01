//
// Created by lseli on 3/6/2026.
//

#include <iostream>
#include <format>

#include "../../include/payments/CashPayment.h"

using std::cout;
using std::endl;
using std::format;
using std::invalid_argument;

namespace payments {
    void CashPayment::pay(const double amount) const {
        if (0 >= amount) {
            throw invalid_argument("Amount must be greater than zero");
        }

        cout << format("CashPayment: {}", amount) << endl;
    }

    PaymentKind CashPayment::kind() const noexcept {
        return PaymentKind::Cash;
    }
}
