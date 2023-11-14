#include <iostream>
#include <functional>

class NumericalIntegration {
protected:
    int numPoints;
    double step;
    double precision;

public:
    NumericalIntegration(int numPoints, double step, double precision)
            : numPoints(numPoints), step(step), precision(precision) {}

    virtual double calc(std::function<double(double)> function, double lowerLimit, double upperLimit) = 0;

    void validateParameters(double lowerLimit, double upperLimit) {
        if (lowerLimit >= upperLimit) {
            throw std::invalid_argument("Верхняя граница должна быть больше нижней");
        }
    }
};

class TrapezoidalIntegration : public NumericalIntegration {
public:
    TrapezoidalIntegration(int numPoints, double step, double precision)
            : NumericalIntegration(numPoints, step, precision) {}

    double calc(std::function<double(double)> function, double lowerLimit, double upperLimit) override {
        validateParameters(lowerLimit, upperLimit);

        double integral = 0.0;
        double h = (upperLimit - lowerLimit) / numPoints;

        for (int i = 1; i < numPoints; ++i) {
            double x = lowerLimit + i * h;
            integral += function(x);
        }

        integral += (function(lowerLimit) + function(upperLimit)) / 2.0;
        integral *= h;

        return integral;
    }
};

class SimpsonIntegration : public NumericalIntegration {
public:
    SimpsonIntegration(int numPoints, double step, double precision)
            : NumericalIntegration(numPoints, step, precision) {}

    double calc(std::function<double(double)> function, double lowerLimit, double upperLimit) override {
        validateParameters(lowerLimit, upperLimit);

        double integral = 0.0;
        double h = (upperLimit - lowerLimit) / numPoints;

        integral += function(lowerLimit) + function(upperLimit);

        for (int i = 1; i < numPoints; i += 2) {
            double x = lowerLimit + i * h;
            integral += 4 * function(x);
        }

        for (int i = 2; i < numPoints - 1; i += 2) {
            double x = lowerLimit + i * h;
            integral += 2 * function(x);
        }

        integral *= h / 3.0;

        return integral;
    }
};

int main() {
    int numPoints = 100;
    double step = 0.01;
    double precision = 0.0001;

    TrapezoidalIntegration trapezoidal(numPoints, step, precision);
    SimpsonIntegration simpson(numPoints, step, precision);

    auto function = [](double x) { return x*x; };

    double lowerLimit = 0.0;
    double upperLimit = 1.0;

    try {
        double trapezoidalResult = trapezoidal.calc(function, lowerLimit, upperLimit);
        double simpsonResult = simpson.calc(function, lowerLimit, upperLimit);

        std::cout << "Результат при использовании метода трапеций " << trapezoidalResult << std::endl;
        std::cout << "Результит при использовании метода Симпсона: " << simpsonResult << std::endl;
    }
    catch (std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
