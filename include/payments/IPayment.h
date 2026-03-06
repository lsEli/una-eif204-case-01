//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_IPAYMENT_H
#define UNA_EIF204_CASE_01_IPAYMENT_H

#include "PaymentKind.h"

namespace payments {
    class IPayment {
    public:
        virtual void pay(double amount) const = 0;

        [[nodiscard]] virtual PaymentKind kind() const = 0;

        virtual ~IPayment() = default;
    };
}

#endif //UNA_EIF204_CASE_01_IPAYMENT_H
