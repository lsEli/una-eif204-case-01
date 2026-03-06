//
// Created by lseli on 3/5/2026.
//

#include "../../include/domain/OrderItem.h"

using domain::OrderItem;

namespace domain {
    OrderItem::OrderItem(string_view name, int quantity, double unitPrice) : name_(name), quantity_(quantity),
                                                                             unitPrice_(unitPrice) {
    }

    string_view OrderItem::name() const {
        return this->name_;
    }

    int OrderItem::quantity() const {
        return this->quantity_;
    }

    double OrderItem::unitPrice() const {
        return this->unitPrice_;
    }

    double OrderItem::subTotal() const {
        return this->unitPrice() * this->quantity();
    }
}
