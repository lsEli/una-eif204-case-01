//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_ORDENITEM_H
#define UNA_EIF204_CASE_01_ORDENITEM_H

#include <string>

using std::string;
using std::string_view;

namespace domain {
    class OrderItem final {
    public:
        OrderItem() = delete;

        OrderItem(string name, int quantity, double unitPrice);

        [[nodiscard]] string_view name() const noexcept;

        [[nodiscard]] int quantity() const noexcept;

        [[nodiscard]] double unitPrice() const noexcept;

        [[nodiscard]] double subTotal() const noexcept;

        ~OrderItem() = default;

    private:
        string name_{};
        int quantity_{};
        double unitPrice_{};
    };
}

#endif //UNA_EIF204_CASE_01_ORDENITEM_H
