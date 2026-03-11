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
    class Order final {
    public:
        Order() = delete;

        explicit Order(string &id);

        [[nodiscard]] string_view id() const noexcept;

        [[nodiscard]] OrderStatus status() const noexcept;

        void addItem(const OrderItem &item);

        [[nodiscard]] double total() const noexcept;

        [[nodiscard]] size_t itemCount() const noexcept;

        void setStatus(OrderStatus newStatus) noexcept;

        ~Order() = default;

    private:
        string id_{};
        OrderStatus status_{};
        vector<OrderItem> items_{};
    };
}

#endif //UNA_EIF204_CASE_01_ORDER_H
