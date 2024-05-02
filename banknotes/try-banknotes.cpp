#include <iostream>
#include <fstream>

std::vector<std::string> read_cases()
{
    std::ifstream file ("test_cases.txt");

    if (!file.isOpen())
    {
        std::cout << "ERROR: Test cases file not found." << std::endl;
        return {};
    }

    std::vector<std::string> test_cases = {};

    for (std::string line; std::getline(input, line);)
        test_cases.push_back(line);

}

int main()
{
    read_cases();
    return 0;
}
