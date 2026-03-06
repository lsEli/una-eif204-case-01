//
// Created by lseli on 3/6/2026.
//

#include <iostream>
#include <format>

#include "../../include/payments/CryptoPayment.h"

using std::cout;
using std::endl;
using std::format;

namespace payments {
    void CryptoPayment::pay(double amount) const {
        cout << format("CryptoPayment: {}", amount) << endl;
    }

    PaymentKind CryptoPayment::kind() const {
        return PaymentKind::Crypto;
    }
}
