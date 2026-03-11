//
// Created by lseli on 3/5/2026.
//

#ifndef UNA_EIF204_CASE_01_MENU_H
#define UNA_EIF204_CASE_01_MENU_H

#include <string>
#include <optional>

#include "../../include/notifications/ConsoleNotifier.h"
#include "../../include/notifications/MemoryNotifier.h"
#include "../../include/reporting/PaymentReport.h"
#include "../../include/services/OrderService.h"
#include "../../include/payments/CardPayment.h"
#include "../../include/payments/CashPayment.h"
#include "../../include/payments/CryptoPayment.h"

using notifications::ConsoleNotifier;
using notifications::MemoryNotifier;
using services::OrderService;
using payments::CardPayment;
using payments::CashPayment;
using payments::CryptoPayment;
using std::optional;

namespace presentation {
    class Menu {
    public:
        Menu();

        void run();

    private:
        ConsoleNotifier consoleNotifier_{};
        MemoryNotifier memoryNotifier_{};
        PaymentReport report_{};

        OrderService service_;

        CardPayment cardPayment_{};
        CashPayment cashPayment_{};
        CryptoPayment cryptoPayment_{};

        optional<Order> currentOrder_{};

        void printMenu() const;

        void handleCreateOrder();

        void handleAddItem();

        void handlePayOrder();

        void handleCancelOrder();

        void handleShipOrder();

        void handleShowSummary() const;

        void handleShowReport() const;

        void handleShowMemoryMessages() const;

        void handleChangeNotifier();

        [[nodiscard]] bool hasOrder() const noexcept;

        [[nodiscard]] const IPayment &selectPaymentMethod() const;

        static int readInt(const char *prompt);

        static double readDouble(const char *prompt);

        static string readLine(const char *prompt);

        static void printOrderStatus(const Order &order);
    };
};

#endif //UNA_EIF204_CASE_01_MENU_H
