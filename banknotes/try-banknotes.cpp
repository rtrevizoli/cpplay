#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> read_file(std::string file_path)
{
    std::ifstream file (file_path);

    if (!file.is_open())
    {
        std::cout << "ERROR: file not found (" << file_path << ")." << std::endl;
        return {};
    }

    std::vector<std::string> lines = {};

    for (std::string line; std::getline(file, line);)
    {
        std::cout << line << std::endl;
        lines.push_back(line);
    }

    return lines;
}

std::vector<std::string> read_cases()
{
    return read_file("./banknotes/test_cases.txt");
}

int main()
{
    std::vector<std::string> input_cases = read_cases();
    // std::vector<std::string> expected_outputs = read_expected_outputs();

    // for (int i = 0; i < cases.size(); i++)
    //     check(input_cases[i], expected_outputs[i]);

    return 0;
}
