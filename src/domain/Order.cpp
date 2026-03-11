//
// Created by lseli on 3/5/2026.
//

#include "../../include/domain/Order.h"

namespace domain {
    Order::Order(string &id) : id_(std::move(id)) {
    };

    string_view Order::id() const noexcept {
        return this->id_;
    }

    OrderStatus Order::status() const noexcept {
        return this->status_;
    }

    void Order::addItem(const OrderItem &item) {
        this->items_.push_back(item);
    }

    double Order::total() const noexcept {
        double total{};

        for (const auto &item: this->items_) {
            total += item.subTotal();
        }

        return total;
    }

    size_t Order::itemCount() const noexcept {
        return this->items_.size();
    }

    void Order::setStatus(OrderStatus newStatus) noexcept {
        this->status_ = newStatus;
    }
}
