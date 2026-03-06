//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_CARDPAYMENT_H
#define UNA_EIF204_CASE_01_CARDPAYMENT_H

#include "IPayment.h"

namespace payments {

    class CardPayment final : public IPayment {
    public:
        CardPayment() = default;

        void pay(double amount) const override;
        [[nodiscard]] PaymentKind kind() const override;

        ~CardPayment() override = default;
    };

}

#endif //UNA_EIF204_CASE_01_CARDPAYMENT_H