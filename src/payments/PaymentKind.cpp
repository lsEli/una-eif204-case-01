//
// Created by lseli on 3/10/2026.
//

#include "../../include/payments/IPayment.h"

namespace payments {
    std::ostream &operator<<(std::ostream &os, PaymentKind kind) {
        switch (kind) {
                using enum payments::PaymentKind;
            case Card:
                return os << "Card";

            case Cash:
                return os << "Cash";

            case Crypto:
                return os << "Crypto";
        }

        return os;
    }
}
