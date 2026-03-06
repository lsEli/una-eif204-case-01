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
    class OrderService {
    public:
        OrderService() = delete;

        OrderService(INotifier &notifier, PaymentReport &report);

        Order createOrder(string id);

        void addItem(Order &order, string name, int quantity, double unitPrice);

        void pay(Order &order, IPayment &payment);

        void cancel(Order &order);

        void ship(Order &order);

        ~OrderService() = default;

    private:
        INotifier &notifier_;
        PaymentReport &report_;
    };
}

#endif //UNA_EIF204_CASE_01_ORDERSERVICE_H
