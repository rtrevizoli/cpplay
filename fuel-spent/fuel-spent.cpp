#include <iostream>
#include <string>
#include <iomanip>

double calculate_trip_fuel(double &travelled_distance, double car_autonomy)
{
    return travelled_distance / car_autonomy;
}

double calculate_travelled_distance(double trip_time, double avg_speed)
{
    return trip_time * avg_speed;
}

int main()
{
    std::string trip_time = "";
    std::string avg_speed = "";
    double travelled_distance = 0.0;
    double trip_fuel = 0.0;

    std::getline(std::cin, trip_time);
    std::getline(std::cin, avg_speed);

    travelled_distance = calculate_travelled_distance(std::stod(trip_time), std::stod(avg_speed));

    trip_fuel = calculate_trip_fuel(travelled_distance, 12.0);

    std::cout << std::fixed << std::setprecision(3) << trip_fuel << std::endl;

    return 0;
}
