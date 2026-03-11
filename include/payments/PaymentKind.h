//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_PAYMENTKIND_H
#define UNA_EIF204_CASE_01_PAYMENTKIND_H

#include <ostream>

using std::ostream;

namespace payments {
    enum class PaymentKind {
        Card,
        Cash,
        Crypto
    };

    ostream &operator<<(ostream &os, PaymentKind kind);
}

#endif //UNA_EIF204_CASE_01_PAYMENTKIND_H
