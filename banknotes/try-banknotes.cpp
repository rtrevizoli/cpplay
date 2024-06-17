#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> read_file(std::string file_path)
{
    std::ifstream file (file_path);

    if (!file.is_open())
    {
        std::cout << "ERROR: file not found (" << file_path << ")." << std::endl;
        return {};
    }

    std::vector<int> lines = {};

    for (std::string line; std::getline(file, line);)
        lines.push_back(std::stoi(line));

    return lines;
}

std::vector<int> read_cases()
{
    return read_file("./banknotes/test_cases.txt");
}

void run(int remaining_amount_to_withdraw = 0)
{
    std::vector<int> notes = { 100, 50, 20, 10, 5, 2, 1 };
    std::vector<int> amount_notes_to_withdraw(notes.size());

    std::cout << remaining_amount_to_withdraw << std::endl;

    for (int i = 0 ; i < notes.size(); i++)
    {
        while (remaining_amount_to_withdraw >= notes[i])
        {
            remaining_amount_to_withdraw -= notes[i];
            amount_notes_to_withdraw[i]++;
        }

        continue;
    }

    for (int i = 0; i < notes.size(); i++)
        std::cout << amount_notes_to_withdraw[i] << " nota(s) de R$ " << notes[i] << ",00" << std::endl;

}

int main()
{
    std::vector<int> input_cases = read_cases();
    // std::vector<std::string> expected_outputs = read_expected_outputs();

    // for (int i = 0; i < cases.size(); i++)
    //     check(input_cases[i], expected_outputs[i]);

    for (int input_case : input_cases)
        run(input_case);

    return 0;
}
