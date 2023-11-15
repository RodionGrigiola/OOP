#include <iostream>
#include <cmath>

class Point {
public:
    double x, y, z;
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
};

class Vector {
public:
    double x, y, z;
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}
    Vector(Point p1, Point p2) {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
        z = p2.z - p1.z;
    }

    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y, z + v.z);
    }

    Vector operator-(const Vector& v) const {
        return Vector(x - v.x, y - v.y, z - v.z);
    }

    Vector operator-() const {
        return Vector(-x, -y, -z);
    }

    Vector unitVector() const {
        double length = sqrt(x * x + y * y + z * z);
        return Vector(x / length, y / length, z / length);
    }

    double dotProduct(const Vector& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    Vector crossProduct(const Vector& v) const {
        return Vector(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }

    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    bool areCollinear(const Vector& v) const {
        double epsilon = 1e-10;
        return fabs(crossProduct(v).length()) < epsilon;
    }

    bool areCoplanar(const Vector& v1, const Vector& v2) const {
        double scalarTripleProduct = dotProduct(v1.crossProduct(v2));
        return fabs(scalarTripleProduct) < 1e-10;
    }

    double distance(const Vector& v) const {
        return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
    }

    double angle(const Vector& v) const {
        double dot = dotProduct(v);
        double thisLength = length();
        double vLength = v.length();
        return acos(dot / (thisLength * vLength));
    }
};

int main() {
    double x1, y1, z1, x2, y2, z2, x3, y3, z3;
    std::cout << "Введите координаты первой точки (x y z): ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "Введите координаты второй точки (x y z): ";
    std::cin >> x2 >> y2 >> z2;

    Point p1(x1, y1, z1);
    Point p2(x2, y2, z2);
    Vector v1(p1, p2);
    std::cout << "Вектор v1: (" << v1.x << ", " << v1.y << ", " << v1.z << ")\n";

    std::cout << "Введите координаты второго вектора (x y z): ";
    std::cin >> x3 >> y3 >> z3;
    Vector v2(x3, y3, z3);
    std::cout << "Vector v2: (" << v2.x << ", " << v2.y << ", " << v2.z << ")\n";

    int choice;
    while (true) {
        std::cout << "\nДоступные операции над векторами:\n";
        std::cout << "1. Найти сумму векторов\n";
        std::cout << "2. Найти разность векторов\n";
        std::cout << "3. Найти обратный вектор\n";
        std::cout << "4. Рассчитать векторы нормали\n";
        std::cout << "5. Рассчитать скалярное произведение\n";
        std::cout << "6. Рассчитать смешанное произведение\n";
        std::cout << "7. Найти длину векторов\n";
        std::cout << "8. Проверить коллинеарность векторов\n";
        std::cout << "9. Проверить компланарность векторов\n";
        std::cout << "10. Рассчитать расстояние между векторами\n";
        std::cout << "11. Расчитать угол между векторами\n";
        std::cout << "12. Выйти\n";
        std::cout << "Введите номер операции: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Сумма векторов равна: (" << (v1 + v2).x << ", " << (v1 + v2).y << ", " << (v1 + v2).z << ")\n";
                break;
            case 2:
                std::cout << "Разность векторов равна: (" << (v1 - v2).x << ", " << (v1 - v2).y << ", " << (v1 - v2).z << ")\n";
                break;
            case 3:
                std::cout << "Обратный вектор v1: (" << (-v1).x << ", " << (-v1).y << ", " << (-v1).z << ")\n";
                std::cout << "Обратный вектор v2: (" << (-v2).x << ", " << (-v2).y << ", " << (-v2).z << ")\n";
                break;
            case 4:
                std::cout << "Вектор нормали v1: (" << v1.unitVector().x << ", " << v1.unitVector().y << ", " << v1.unitVector().z << ")\n";
                std::cout << "Вектор нормали v2: (" << v2.unitVector().x << ", " << v2.unitVector().y << ", " << v2.unitVector().z << ")\n";
                break;
            case 5:
                std::cout << "Cкалярное произведение равно " << v1.dotProduct(v2) << "\n";
                break;
            case 6:
                std::cout << "Смешанное произведение равно (" << v1.crossProduct(v2).x << ", " << v1.crossProduct(v2).y << ", " << v1.crossProduct(v2).z << ")\n";
                break;
            case 7:
                std::cout << "Длина вектора v1: " << v1.length() << "\n";
                std::cout << "Длина вектора v2: " << v2.length() << "\n";
                break;
            case 8:
                std::cout << "Коллинеарны? " << (v1.areCollinear(v2) ? "Да" : "Нет") << "\n";
                break;
            case 9:
                std::cout << "Компланарны? " << (v1.areCoplanar(v2, v1.crossProduct(v2)) ? "Да" : "Нет") << "\n";
                break;
            case 10:
                std::cout << "Расстояние между векторами v1 и v2 равно: " << v1.distance(v2) << "\n";
                break;
            case 11:
                std::cout << "Угол между векторами v1 и v2 (в радианах) равен: " << v1.angle(v2) << "\n";
                break;
            case 12:
                std::cout << "Выход...\n";
                return 0;
            default:
                std::cout << "Неверный номер операции, введите номер заново\n";
        }
        std::cout << "Нажмите enter для продолжения...\n";

        std::cin.ignore(256, '\n');
        std::cin.get();
    }

    return 0;

}