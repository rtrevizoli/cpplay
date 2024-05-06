#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> read_cases()
{
    std::ifstream file ("./banknotes/test_cases.txt");

    if (!file.is_open())
    {
        std::cout << "ERROR: Test cases file not found." << std::endl;
        return {};
    }

    std::vector<std::string> test_cases = {};

    for (std::string line; std::getline(file, line);)
    {
        std::cout << line << std::endl;
        test_cases.push_back(line);
    }

    return test_cases;

}

int main()
{
    std::vector<std::string> input_cases = read_cases();

    for (int i = 0; i < cases.size(); i++)
        check(input_cases[i], expected_outputs[i]);

    return 0;
}
