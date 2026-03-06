//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_PAYMENTREPORT_H
#define UNA_EIF204_CASE_01_PAYMENTREPORT_H

#include <iosfwd>
#include <unordered_map>

#include "../payments/PaymentKind.h"

using std::pmr::unordered_map;
using payments::PaymentKind;
using std::ostream;

namespace reporting {
    class PaymentReport {
    public:
        PaymentReport() = default;

        void recordPayment(PaymentKind kind);

        [[nodiscard]] size_t count(PaymentKind kind) const;

        void print(ostream &os) const;

        ~PaymentReport() = default;

    private:
        unordered_map<PaymentKind, size_t> counts_;
    };
}

#endif //UNA_EIF204_CASE_01_PAYMENTREPORT_H
