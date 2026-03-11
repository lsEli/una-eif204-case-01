cmake_minimum_required(VERSION 4.0)
project(una_eif204_case_01)

set(CMAKE_CXX_STANDARD 26)

add_executable(una_eif204_case_01 main.cpp
        include/domain/OrderItem.h
        include/domain/Order.h
        include/domain/OrderStatus.h
        include/payments/IPayment.h
        include/payments/CardPayment.h
        include/payments/CashPayment.h
        include/payments/CryptoPayment.h
        include/notifications/INotifier.h
        include/notifications/ConsoleNotifier.h
        include/notifications/MemoryNotifier.h
        include/services/OrderService.h
        include/reporting/PaymentReport.h
        include/payments/PaymentKind.h
        include/notifications/MultiNotifier.h
        include/presentation/Menu.h
        src/domain/Order.cpp
        src/domain/OrderItem.cpp
        src/notifications/ConsoleNotifier.cpp
        src/notifications/MemoryNotifier.cpp
        src/notifications/MultiNotifier.cpp
        src/payments/CardPayment.cpp
        src/payments/CashPayment.cpp
        src/payments/CryptoPayment.cpp
        src/reporting/PaymentReport.cpp
        src/services/OrderService.cpp
        src/presentation/Menu.cpp
        src/payments/PaymentKind.cpp
)
