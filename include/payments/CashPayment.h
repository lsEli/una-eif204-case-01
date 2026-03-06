//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_CASHPAYMENT_H
#define UNA_EIF204_CASE_01_CASHPAYMENT_H

#include "IPayment.h"

namespace payments {
    class CashPayment final : public IPayment {
    public:
        CashPayment() = default;

        void pay(double amount) const override;

        [[nodiscard]] PaymentKind kind() const override;

        ~CashPayment() override = default;
    };
}

#endif //UNA_EIF204_CASE_01_CASHPAYMENT_H
