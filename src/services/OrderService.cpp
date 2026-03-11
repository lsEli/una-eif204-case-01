//
// Created by lseli on 3/6/2026.
//

#include "../../include/services/OrderService.h"

#include <stdexcept>

#include "../../include/domain/OrderItem.h"
#include "../../include/domain/OrderStatus.h"

using domain::OrderItem;
using domain::OrderStatus;
using std::invalid_argument;

namespace services {
    OrderService::OrderService(INotifier &notifier, PaymentReport &report) : notifier_(notifier), report_(report) {
    }

    Order OrderService::createOrder(string &id) const noexcept {
        return Order{id};
    }

    void OrderService::addItem(Order &order, string &name, const int quantity, const double unitPrice) const {
;       order.addItem(OrderItem(name, quantity, unitPrice));
    }

    void OrderService::pay(Order &order, const IPayment &payment) const {
        try {
            payment.pay(order.total());

            order.setStatus(OrderStatus::Accepted);
        } catch (invalid_argument &exception) {
            throw invalid_argument(exception.what());
        }
    }

    void OrderService::cancel(Order &order) const noexcept {
        order.setStatus(OrderStatus::Rejected);
    }

    void OrderService::ship(Order &order) const noexcept {
        order.setStatus(OrderStatus::Shipping);
    }
}
