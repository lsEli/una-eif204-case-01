//
// Created by lseli on 3/6/2026.
//

#include <iostream>
#include <limits>

#include "../../include/presentation/Menu.h"

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using presentation::Menu;
using std::invalid_argument;

namespace {
    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

namespace presentation {
    Menu::Menu()
        : service_(consoleNotifier_, report_) {
    }

    void Menu::run() {
        bool running = true;

        while (running) {
            printMenu();

            try {
                const int option = readInt("Choose an option: ");

                switch (option) {
                    case 1:
                        handleCreateOrder();
                        break;
                    case 2:
                        handleAddItem();
                        break;
                    case 3:
                        handlePayOrder();
                        break;
                    case 4:
                        handleCancelOrder();
                        break;
                    case 5:
                        handleShipOrder();
                        break;
                    case 6:
                        handleShowSummary();
                        break;
                    case 7:
                        handleShowReport();
                        break;
                    case 8:
                        handleShowMemoryMessages();
                        break;
                    case 9:
                        handleChangeNotifier();
                        break;
                    case 0:
                        running = false;

                        cout << "Exiting application.\n";
                        break;
                    default:
                        cout << "Invalid option.\n";

                        break;
                }
            } catch (const invalid_argument &exception) {
                cout << "Validation error: " << exception.what() << '\n';
            } catch (const std::exception &exception) {
                cout << "Error: " << exception.what() << '\n';
            }

            cout << '\n';
        }
    }

    void Menu::printMenu() const {
        cout << "==== Order System ====\n";
        cout << "1. Create order\n";
        cout << "2. Add item\n";
        cout << "3. Pay order\n";
        cout << "4. Cancel order\n";
        cout << "5. Ship order\n";
        cout << "6. Show order summary\n";
        cout << "7. Show payment report\n";
        cout << "8. Show memory notifier messages\n";
        cout << "9. Change notifier\n";
        cout << "0. Exit\n";
    }

    void Menu::handleCreateOrder() {
        string id = readLine("Order id: ");
        currentOrder_ = service_.createOrder(id);

        cout << "Order created successfully.\n";
    }

    void Menu::handleAddItem() {
        if (!hasOrder()) {
            cout << "You must create an order first.\n";

            return;
        }

        string name = readLine("Item name: ");
        const int quantity = readInt("Quantity: ");
        const double unitPrice = readDouble("Unit price: ");

        service_.addItem(*currentOrder_, name, quantity, unitPrice);

        cout << "Item added successfully.\n";
    }

    void Menu::handlePayOrder() {
        if (!hasOrder()) {
            cout << "You must create an order first.\n";
            return;
        }

        const IPayment &payment = selectPaymentMethod();
        service_.pay(*currentOrder_, payment);

        cout << "Payment processed successfully.\n";
    }

    void Menu::handleCancelOrder() {
        if (!hasOrder()) {
            cout << "You must create an order first.\n";

            return;
        }

        service_.cancel(*currentOrder_);

        cout << "Order canceled successfully.\n";
    }

    void Menu::handleShipOrder() {
        if (!hasOrder()) {
            cout << "You must create an order first.\n";

            return;
        }

        service_.ship(*currentOrder_);

        cout << "Order shipped successfully.\n";
    }

    void Menu::handleShowSummary() const {
        if (!hasOrder()) {
            cout << "You must create an order first.\n";

            return;
        }

        cout << "Order id: " << currentOrder_->id() << '\n';
        cout << "Item count: " << currentOrder_->itemCount() << '\n';
        cout << "Total: " << currentOrder_->total() << '\n';

        printOrderStatus(*currentOrder_);
    }

    void Menu::handleShowReport() const {
        report_.print(cout);
    }

    void Menu::handleShowMemoryMessages() const {
        const auto &messages = memoryNotifier_.messages();

        if (messages.empty()) {
            cout << "No messages stored in memory.\n";

            return;
        }

        for (const auto &message: messages) {
            cout << message << '\n';
        }
    }

    void Menu::handleChangeNotifier() {
        cout << "Select notifier:\n";
        cout << "1. ConsoleNotifier\n";
        cout << "2. MemoryNotifier\n";

        switch (readInt("Option: ")) {
            case 1:
                service_.setNotifier(consoleNotifier_);
                cout << "Notifier changed to ConsoleNotifier.\n";

                break;
            case 2:
                service_.setNotifier(memoryNotifier_);
                cout << "Notifier changed to MemoryNotifier.\n";

                break;
            default:
                cout << "Invalid option.\n";

                break;
        }
    }

    bool Menu::hasOrder() const noexcept {
        return currentOrder_.has_value();
    }

    const IPayment &Menu::selectPaymentMethod() const {
        while (true) {
            cout << "Select payment method:\n";
            cout << "1. Card\n";
            cout << "2. Cash\n";
            cout << "3. Crypto\n";

            switch (readInt("Option: ")) {
                case 1:
                    return cardPayment_;
                case 2:
                    return cashPayment_;
                case 3:
                    return cryptoPayment_;
                default:
                    cout << "Invalid option.\n";

                    break;
            }
        }
    }

    int Menu::readInt(const char *prompt) {
        int value{};

        while (true) {
            cout << prompt;

            if (cin >> value) {
                clearInput();
                return value;
            }

            cout << "Invalid integer.\n";

            clearInput();
        }
    }

    double Menu::readDouble(const char *prompt) {
        double value{};

        while (true) {
            cout << prompt;

            if (cin >> value) {
                clearInput();

                return value;
            }

            cout << "Invalid number.\n";

            clearInput();
        }
    }

    string Menu::readLine(const char *prompt) {
        cout << prompt;

        string value;
        getline(cin, value);

        return value;
    }

    void Menu::printOrderStatus(const Order &order) {
        cout << "Status: ";

        switch (order.status()) {
                using enum domain::OrderStatus;
            case Created:
                cout << "Created";
                break;
            case Accepted:
                cout << "Accepted";
                break;
            case Rejected:
                cout << "Rejected";
                break;
            case Shipping:
                cout << "Shipping";
                break;
        }

        cout << '\n';
    }
}
