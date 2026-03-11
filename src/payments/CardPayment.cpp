//
// Created by lseli on 3/6/2026.
//

#include <iostream>
#include <format>

#include "../../include/payments/CardPayment.h"

using std::cout;
using std::endl;
using std::format;
using std::invalid_argument;

namespace payments {
    void CardPayment::pay(const double amount) const {
        if (0 >= amount) {
            throw invalid_argument("Amount must be greater than zero");
        }

        cout << format("CardPayment: {}", amount) << endl;
    }

    PaymentKind CardPayment::kind() const noexcept {
        return PaymentKind::Card;
    }
}
