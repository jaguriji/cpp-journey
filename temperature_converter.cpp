#include <iostream>
using namespace std;

class temp {
private:
  double fahrenheit;

public:

  temp(double f = 0.0) : fahrenheit(f) {}

  void setFahrenheit(double f) { fahrenheit = f; }

  double getFahrenheit() const { return fahrenheit; }

  // Convert to Celsius
  double toCelsius() const { return (fahrenheit - 32.0) * 5.0 / 9.0; }

  // Convert to Kelvin
  double toKelvin() const { return toCelsius() + 273.15; }

  // Display all temperatures
  void displayTemperatures() const {
    cout << "Temperature in Fahrenheit: " << fahrenheit << " °F\n";
    cout << "Temperature in Celsius:    " << toCelsius() << " °C\n";
    cout << "Temperature in Kelvin:     " << toKelvin() << " K\n";
  }
};

int main() {
  double fTemp;
  cout << "Enter temperature in Fahrenheit: ";
  if (cin >> fTemp) {
    // Create an object of TemperatureConverter
    temp temp(fTemp);

    cout << "\n--- Conversion Results ---\n";
    // Display the converted temperatures
    temp.displayTemperatures();
  } else {
    cout << "Invalid input. Please enter a numerical value.\n";
  }

  return 0;
}
