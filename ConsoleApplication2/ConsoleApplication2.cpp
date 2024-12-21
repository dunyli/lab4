// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
using namespace std;


//Класс для хранения информации о товаре
class Product {
private:
    string name;
    int price;
    int count;
    int category_id;
    int supplier_id;
public:
    Product(); //конструктор
    Product(string name, int price, int count, int category_id, int supplier_id);
    Product(Product& p); //конструктор копирования
    void get(string& name, int* price, int* count, int* category_id, int* supplier_id); //Получение данных класса
    void set(string name, int price, int count, int category_id, int supplier_id); //Получение значений переменных-членов класса
    int getPrice() {
        return price;
    };
    int getCount() {
        return count;
    };
    // Перегрузка оператора вывода
    friend ostream& operator << (ostream& os, Product& p);
};

//Класс для хранения информации о количестве товара
class Storehouse {
private:
    std::unique_ptr<Product[]> products; // Уникальный указатель на массив объектов Product
    int num_products;
public:
    Storehouse(); //конструктор
    void addProduct(Product& newProduct);
    void editProduct(int product_id, string name, int price, int volume, int category_id, int supplier_id);
    void listStorehouse(Product* product, int count);
    void get(int num_products); //Получение данных класса
    int listnum_products() {
        return num_products;
    };
};

// Определение контруктора класса Storehouse
Storehouse::Storehouse()
{
    num_products = 0;
}

//Определение функции-члена класса Storehouse для вывода списка товаров
void Storehouse::listStorehouse(Product* product, int count) {
    for (int i = 0; i < num_products; i++) {
        if (i == count) *product = products[i];
    }
}

// Определение функции - члена класса Storehouse - функции addProduct()
void Storehouse::addProduct(Product& newProduct) {
    // Создаем новый массив с размером на 1 больше
    std::unique_ptr<Product[]> newProducts = std::make_unique<Product[]>(num_products + 1);

    // Копируем старые продукты в новый массив
    for (int i = 0; i < num_products; ++i) {
        newProducts[i] = products[i]; // Используем оператор копирования
    }

    // Добавляем новый продукт
    newProducts[num_products] = newProduct; // Копируем новый продукт
    num_products++;

    // Перенаправляем указатель
    products = std::move(newProducts); // Умный указатель автоматически освободит старую память
}

void Storehouse::editProduct(int product_id, string name, int price, int volume, int category_id, int supplier_id) {
    products[product_id].set(name, price, volume, category_id, supplier_id);
}

// Определение контруктора класса Product
Product::Product()
{
    price = 0;
    count = 0;
    category_id = 0;
    supplier_id = 0;
}

// Определение контруктора класса Product
Product::Product(string name, int price, int count, int category_id, int supplier_id)
{
    this->name = name;
    this->price = price;
    this->count = count;
    this->category_id = category_id;
    this->supplier_id = supplier_id;
}

// Определение контруктора копирования класса Product
Product::Product(Product& p) {
    name = p.name;
    price = p.price;
    count = p.count;
    category_id = p.category_id;
    supplier_id = p.supplier_id;
}

//Получение значений переменных-членов класса и данных класса Product
void Product::get(string& name, int* price, int* count, int* category_id, int* supplier_id) {
    name = this->name;
    *price = this->price;
    *count = this->count;
    *category_id = this->category_id;
    *supplier_id = this->supplier_id;
}

void Product::set(string name, int price, int count, int category_id, int supplier_id) {
    this->name = name;
    this->price = price;
    this->count = count;
    this->category_id = category_id;
    this->supplier_id = supplier_id;
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& os, Product& p) {
    os << "Название товара: " << p.name << ", Цена: " << p.price
        << ", Количество: " << p.count << ", ID Категории: " << p.category_id
        << ", ID Поставщика: " << p.supplier_id;
    return os;
}

int main()
{
    setlocale(0, "RUS");
    string name;
    int price;
    int count;
    int category_id;
    int supplier_id;
    Storehouse storehouse;
    Product product1("ffejj", 32, 234, 3454, 345);
    Product product2("kdkflsdfls", 32, 234, 3454, 345);
    Product product3;
    storehouse.addProduct(product1);
    storehouse.addProduct(product2);
    storehouse.listStorehouse(&product3, 1);
    product3.get(name, &price, &count, &category_id, &supplier_id);
    printf("%d%d%d%d", price, count, category_id, supplier_id);
    cout << product3;
    storehouse.listStorehouse(&product1, 0);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
