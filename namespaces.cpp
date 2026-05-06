#include<iostream>
#include<string>
using namespace std;

namespace Math {
    const double PI = 3.14159;

    double circleArea(double r) {
        return PI * r * r;
    }

    double circlePerimeter(double r) {
        return 2 * PI * r;
    }

    namespace Advanced {
        double power(double base, int exp) {
            double result = 1;
            for(int i = 0; i < exp; i++)
                result *= base;
            return result;
        }

        double squareRoot(double n) {
            double x = n;
            for(int i = 0; i < 1000; i++)
                x = (x + n / x) / 2;
            return x;
        }
    }
}

namespace Converter {
    double kmToMiles(double km) { return km * 0.621371; }
    double celsiusToFahrenheit(double c) { return (c * 9/5) + 32; }
    double kgToPounds(double kg) { return kg * 2.20462; }
}

int main() {
    cout << "--- Math Namespace ---" << endl;
    cout << "PI: " << Math::PI << endl;
    cout << "Circle Area (r=5): " << Math::circleArea(5) << endl;
    cout << "Circle Perimeter (r=5): " << Math::circlePerimeter(5) << endl;

    cout << "\n--- Advanced Math ---" << endl;
    cout << "2^10: " << Math::Advanced::power(2, 10) << endl;
    cout << "Square root of 144: " << Math::Advanced::squareRoot(144) << endl;

    cout << "\n--- Converter Namespace ---" << endl;
    cout << "100 km = " << Converter::kmToMiles(100) << " miles" << endl;
    cout << "37 C = " << Converter::celsiusToFahrenheit(37) << " F" << endl;
    cout << "70 kg = " << Converter::kgToPounds(70) << " pounds" << endl;

    return 0;
}