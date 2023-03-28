#include <iostream>
#include <vector>
using namespace std;

// Класс товара
class Product {
public:
    Product(string name, double price, int quantity)
        : name_(name), price_(price), quantity_(quantity) {}

    // Геттеры и сеттеры для свойств товара
    string getName() const { return name_; }
    double getPrice() const { return price_; }
    int getQuantity() const { return quantity_; }
    void setPrice(double price) { price_ = price; }
    void setName(string name) { name_ = name; }
    void setQuantity(int quantity) { quantity_ = quantity; }

private:
    string name_;
    double price_;
    int quantity_;
};

// Класс заказа
class Order {
public:
    Order(int id, vector<Product> products)
        : id(id), products(products) {}

    // Геттеры и сеттеры для свойств заказа
    int getId() const { return id; }
    vector<Product> getProducts() const { return products; }
    void addProduct(Product product) { products.push_back(product); }
    void removeProduct(string productName) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getName() == productName) {
                products.erase(it);
                break;
            }
        }
    }

private:
    int id;
    vector<Product> products;
};

// Класс управления заказами
class OrderManager {
public:
    void createOrder(int id, vector<Product> products) {
        Order order(id, products);
        orders.push_back(order);
    }

    void updateOrder(int orderId, vector<Product> products) {
        for (auto& order : orders) {
            if (order.getId() == orderId) {
                order.getProducts() = products;
                break;
            }
        }
    }

    void deleteOrder(int orderId) {
        for (auto it = orders.begin(); it != orders.end(); ++it) {
            if (it->getId() == orderId) {
                orders.erase(it);
                break;
            }
        }
    }

    Order getOrder(int orderId) const {
        for (auto& order : orders) {
            if (order.getId() == orderId) {
                return order;
            }
        }
        throw "No such order";
    }

    void addProductToOrder(int orderId, Product product) {
        for (auto& order : orders) {
            if (order.getId() == orderId) {
                order.addProduct(product);
                break;
            }
        }
    }

    void removeProductFromOrder(int orderId, string productName) {
        for (auto& order : orders) {
            if (order.getId() == orderId) {
                order.removeProduct(productName);
                break;
            }
        }
    }

    // Получение списка всех заказов
    vector<Order> getOrders() {
        return orders;
    }

private:
    vector<Order> orders;
};

// Класс для обработки платежей
class PaymentProcessor {
public:
    void processPayment(Order order, double amount) {
        // Обработка платежа
        cout << "Payment processed for order #" << order.getId()
            << " in the amount of $" << amount << endl;
    }
};

// Класс для отправки уведомлений
class NotificationSender {
public:
    void sendNotification(Order order, string message) {
        // Отправка уведомления
        cout << "Notification sent for order #" << order.getId()
            << ": " << message << endl;
    }
};

int main() {
    // Создаем объекты классов
    OrderManager orderManager;
    PaymentProcessor paymentProcessor;
    NotificationSender notificationSender;

    // Создаем заказы и добавляем товары
    vector<Product> products1 = {
        Product("Product 1", 10.0, 2),
        Product("Product 2", 20.0, 1) };
    orderManager.createOrder(1, products1);
    orderManager.addProductToOrder(1, Product("Product 3", 15.0, 3));

    vector<Product> products2 = { Product("Product 4", 5.0, 10) };
    orderManager.createOrder(2, products2);

    // Получаем заказы и выводим их информацию
    Order order1 = orderManager.getOrder(1);
    cout << "Order #" << order1.getId() << ":" << endl;
    for (auto& product : order1.getProducts()) {
        cout << "- " << product.getName() << " x" << product.getQuantity() << endl;
    }
    paymentProcessor.processPayment(order1, 50.0);
    notificationSender.sendNotification(order1, "Your order has been processed.");

    Order order2 = orderManager.getOrder(2);
    cout << "Order #" << order2.getId() << ":\n";
    for (auto& product : order2.getProducts()) {
        cout << "- " << product.getName() << " x" << product.getQuantity() << "\n";
    }
    paymentProcessor.processPayment(order2, 50.0);
    notificationSender.sendNotification(order2, "Your order has been processed.");

    // Удаляем заказ и выводим информацию об оставшихся заказах
    orderManager.deleteOrder(1);
    cout << "Orders:\n";
    for (auto& order : orderManager.getOrders()) {
        cout << "- Order #" << order.getId() << endl;
    }
}

/*
ЗАДАЧА:

Напишите класс для управления заказами в интернет-магазине. Класс должен иметь
одну ответственность - управление заказами. В классе должны быть методы для
создания, изменения, удаления и получения заказов, а также методы для работы
с товарами в заказах (добавление, удаление, изменение количества товаров).
Однако, класс не должен заниматься обработкой платежей или отправкой уведомлений
клиентам.

Ваша задача - реализовать этот класс, следуя принципу единственной
ответственности. Разделите функциональность класса так, чтобы каждый
метод выполнял только одну ответственность. Вся обработка платежей и
отправка уведомлений должны быть вынесены в отдельные классы с соответствующими
методами.

Таким образом, вы создадите систему, которая будет легко расширяемой и
поддерживаемой, и которая будет соответствовать принципу единственной
ответственности.
*/

/*
Код представляет собой пример реализации нескольких классов в рамках
управления заказами и обработки платежей.

Класс Product представляет собой модель товара с набором свойств и методов
для доступа к ним.

Класс Order содержит список товаров, выбранных клиентом, а также методы
для добавления и удаления товаров из заказа.

Класс OrderManager содержит набор методов для управления заказами, включая
создание, обновление и удаление заказов, а также добавление и удаление товаров
в заказах и получение списка всех заказов.

Класс PaymentProcessor имеет метод для обработки платежей, который выводит
информацию о номере заказа и сумме платежа.

Класс NotificationSender содержит метод для отправки уведомлений клиентам,
в котором отображается номер заказа и текст сообщения.

Функция main создает объекты всех классов, создает несколько заказов с товарами,
используя методы OrderManager, получает информацию о заказах и вызывает методы
PaymentProcessor и NotificationSender для обработки платежей и отправки
уведомлений. В конце, она удаляет один из заказов и выводит информацию
об оставшихся заказах.
*/

/*
Что такое S.O.L.I.D?
Это принципы проектирования классов
Всего их 5 штук

Основные идеи
1. Увеличение уровня абстракции: интерфейсы, а не реализации
2. Усиление связей внутри классов
3. Ослабление связей между классами
4. Хорошо спроектированный класс не потребуется менять в будущем!
*/

/*
Single Responsibility Principle (SRP) – принцип единственной обязанности,
принцип разделения обязанностей (на каждый класс должна быть возложена одна
единственная обязанность, а также класс должен иметь одну и только одну
причину для изменений).

Именно этот принцип является реализацией условия «сильное внутреннее сцепление».
Он как раз и занимается усилением связей внутри класса.
*/

// BAD: https://gist.github.com/sunmeat/3caae0b8fa625ded1d8d92f3bc9ceb9e
// GOOD: https://gist.github.com/sunmeat/599c1e9e6d55302af4aaf4b2b493f308