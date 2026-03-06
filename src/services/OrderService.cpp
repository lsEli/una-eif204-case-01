//
// Created by lseli on 3/6/2026.
//

#include "../../include/services/OrderService.h"

namespace services {
    OrderService::OrderService(INotifier &notifier, PaymentReport &report) {
        // TODO: Implement this method.
    }

    Order OrderService::createOrder(string id) {
        // TODO: Implement this method.
    }

    void OrderService::addItem(Order &order, string name, int quantity, double unitPrice) {
        // TODO: Implement this method.
    }

    void OrderService::pay(Order &order, IPayment &payment) {
        // TODO: Implement this method.
    }

    void OrderService::cancel(Order &order) {
        // TODO: Implement this method.
    }

    void OrderService::ship(Order &order) {
        // TODO: Implement this method.
    }
}
