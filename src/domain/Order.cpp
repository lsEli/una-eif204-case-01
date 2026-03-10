//
// Created by lseli on 3/5/2026.
//

#include "../../include/domain/Order.h"

namespace domain {
    Order::Order(string &id) : id_(std::move(id)) {
    };

    string_view Order::id() const {
        return this->id_;
    }

    OrderStatus Order::status() const {
        return this->status_;
    }

    void Order::addItem(const OrderItem &item) {
        this->items_.push_back(item);
    }

    double Order::total() const {
        double total{};

        for (const auto &item: this->items_) {
            total += item.subTotal();
        }

        return total;
    }

    size_t Order::itemCount() const {
        return this->items_.size();
    }

    void Order::setStatus(OrderStatus newStatus) {
        this->status_ = newStatus;
    }
}
