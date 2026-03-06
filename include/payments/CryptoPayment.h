//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_CRYPTOPAYMENT_H
#define UNA_EIF204_CASE_01_CRYPTOPAYMENT_H

#include "IPayment.h"

namespace payments {
    class CryptoPayment final : public IPayment {
    public:
        CryptoPayment() = default;

        void pay(double amount) const override;

        [[nodiscard]] PaymentKind kind() const override;

        ~CryptoPayment() override = default;
    };
}

#endif //UNA_EIF204_CASE_01_CRYPTOPAYMENT_H
