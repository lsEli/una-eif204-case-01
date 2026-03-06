//
// Created by lseli on 3/6/2026.
//

#include <iostream>
#include <format>

#include "../../include/payments/CashPayment.h"

using std::cout;
using std::endl;
using std::format;

namespace payments {
    void CashPayment::pay(double amount) const {
        cout << format("CashPayment: {}", amount) << endl;
    }

    PaymentKind CashPayment::kind() const {
        return PaymentKind::Cash;
    }
}
