//
// Created by lseli on 3/5/2026.
//

#include "../../include/domain/OrderItem.h"

using domain::OrderItem;

namespace domain {
    OrderItem::OrderItem(string name, const int quantity, const double unitPrice) : name_(std::move(name)), quantity_(quantity),
        unitPrice_(unitPrice) {
    }

    string_view OrderItem::name() const noexcept {
        return this->name_;
    }

    int OrderItem::quantity() const noexcept {
        return this->quantity_;
    }

    double OrderItem::unitPrice() const noexcept {
        return this->unitPrice_;
    }

    double OrderItem::subTotal() const noexcept {
        return this->unitPrice() * this->quantity();
    }
}
