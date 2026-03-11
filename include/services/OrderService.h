//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_ORDERSERVICE_H
#define UNA_EIF204_CASE_01_ORDERSERVICE_H

#include <string>

#include "../notifications/INotifier.h"
#include "../reporting/PaymentReport.h"
#include "../domain/Order.h"
#include "../payments/IPayment.h"

using std::string;

using notifications::INotifier;
using reporting::PaymentReport;
using domain::Order;
using payments::IPayment;

namespace services {
    class OrderService final {
    public:
        OrderService() = delete;

        OrderService(INotifier &notifier, PaymentReport &report);

        void setNotifier(INotifier &notifier) noexcept;

        void setReport(PaymentReport &report) noexcept;

        [[nodiscard]] Order createOrder(string &id) const;

        void addItem(Order &order, string name, int quantity, double unitPrice) const;

        void pay(Order &order, const IPayment &payment) const;

        void cancel(Order &order) const;

        void ship(Order &order) const;

        ~OrderService() = default;

    private:
        INotifier *notifier_;
        PaymentReport *report_;
    };
}

#endif //UNA_EIF204_CASE_01_ORDERSERVICE_H
