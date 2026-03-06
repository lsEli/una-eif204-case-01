//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_ORDENITEM_H
#define UNA_EIF204_CASE_01_ORDENITEM_H

#include <string>

using std::string;
using std::string_view;

namespace domain {
    class OrderItem {
    public:
        OrderItem() = delete;

        OrderItem(string_view name, int quantity, double unitPrice);

        [[nodiscard]] string_view name() const;

        [[nodiscard]] const int quantity() const;

        [[nodiscard]] const double unitPrice() const;

        [[nodiscard]] const double subTotal() const;

        [[nodiscard]] string &toString() const;

        ~OrderItem() = default;

    private:
        string name_{};
        int quantity_{};
        double unitPrice_{};
    };
}

#endif //UNA_EIF204_CASE_01_ORDENITEM_H
