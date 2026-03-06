//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_ORDER_H
#define UNA_EIF204_CASE_01_ORDER_H

#include <string>
#include <vector>

#include "OrderItem.h"
#include "OrderStatus.h"

using std::string;
using std::vector;

namespace domain {
    class Order {
    public:
        Order() = delete;

        explicit Order(string id);

        [[nodiscard]] string_view id() const;

        [[nodiscard]] OrderStatus status() const;

        void addItem(OrderItem item);

        [[nodiscard]] double total() const;

        [[nodiscard]] size_t itemCount() const;

        void setStatus(OrderStatus newStatus);

        ~Order() = default;

    private:
        string id_{};
        OrderStatus status_{};
        vector<OrderItem> items_;
    };
}

#endif //UNA_EIF204_CASE_01_ORDER_H
