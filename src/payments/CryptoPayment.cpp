//
// Created by lseli on 3/6/2026.
//

#include <iostream>
#include <format>

#include "../../include/payments/CryptoPayment.h"

using std::cout;
using std::endl;
using std::format;
using std::invalid_argument;

namespace payments {
    void CryptoPayment::pay(double amount) const {
        if (0 >= amount) {
            throw invalid_argument("Amount must be greater than zero");
        }

        cout << format("CryptoPayment: {}", amount) << endl;
    }

    PaymentKind CryptoPayment::kind() const noexcept {
        return PaymentKind::Crypto;
    }
}
