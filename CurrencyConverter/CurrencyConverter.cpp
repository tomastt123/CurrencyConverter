/* Currency converter application that allows*/
/*API with real-time currency exchange rates will be added soon!*/

#include <iostream>
#include <sstream> // For stringstream

double getExchangeRate(const std::string& from, const std::string& to) {
    if (from == "USD" && to == "EUR") return 0.85;
    if (from == "EUR" && to == "USD") return 1.18;
    if (from == "USD" && to == "JPY") return 110.0;
    if (from == "JPY" && to == "USD") return 0.0091;
    return -1.0; // Return -1.0 to indicate an invalid conversion
}

int main() {
    while (true) {
        std::string currency_from, currency_to, amount_str;
        double amount;

        std::cout << "Enter the currency you want to convert from (Possible currencies: USD; EUR; JPY or type 'exit' to quit): ";
        std::cin >> currency_from;
        if (currency_from == "exit") break;

        std::cout << "Enter the currency you want to convert to (Possible currencies: USD; EUR; JPY or type 'exit' to quit): ";
        std::cin >> currency_to;
        if (currency_to == "exit") break;

        std::cout << "Enter the amount (or type 'exit' to quit): ";
        std::cin >> amount_str;
        if (amount_str == "exit") break;

        // Convert amount_str to double
        std::stringstream ss(amount_str);
        if (!(ss >> amount)) {
            std::cout << "Invalid amount entered. Please try again." << std::endl;
            continue; // Restart the loop if conversion fails
        }

        double rate = getExchangeRate(currency_from, currency_to);

        if (rate == -1.0) {
            std::cout << "Invalid currency conversion from " << currency_from << " to " << currency_to << std::endl;
        }
        else {
            double converted_amount = amount * rate;
            std::cout << amount << " " << currency_from << " is " << converted_amount << " " << currency_to << std::endl;
        }
    }

    return 0;
}
