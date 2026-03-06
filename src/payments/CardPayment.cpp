//
// Created by lseli on 3/6/2026.
//

#include <iostream>
#include <format>

#include "../../include/payments/CardPayment.h"

using std::cout;
using std::endl;
using std::format;

namespace payments {
    void CardPayment::pay(double amount) const {
        cout << format("CardPayment: {}", amount) << endl;
    }

    PaymentKind CardPayment::kind() const {
        return PaymentKind::Card;
    }
}
