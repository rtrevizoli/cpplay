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

    std::vector<int> notes = { 100, 50, 20, 10, 5, 2, 1 };
    std::vector<int> amount_notes_to_withdraw(notes.size());

    std::string input = "";
    std::getline(std::cin, input);
    int remaining_amount_to_withdraw = std::stoi(input);

    std::cout << remaining_amount_to_withdraw << std::endl;

    std::cout << "RTX | DEBUG | 0" <<std::endl;
    for (int i = 0 ; i < notes.size(); i++)
    {
        std::cout << "RTX | DEBUG | 1" <<std::endl;
        while (remaining_amount_to_withdraw >= notes[i])
        {
            std::cout << "RTX | DEBUG | 2" <<std::endl;

            std::cout << "RTX | DEBUG | 2. remaining_amount_to_withdraw - notes[i] => " 
                << remaining_amount_to_withdraw << " - "
                << notes[i]
                << " (" << remaining_amount_to_withdraw - notes[i] << ")."
                << std::endl;

            std::cout << "RTX | DEBUG | 3" <<std::endl;
            remaining_amount_to_withdraw -= notes[i];
            amount_notes_to_withdraw[i]++;

            std::cout << "RTX | DEBUG | 4" <<std::endl;

        }
        std::cout << "RTX | DEBUG | 5" <<std::endl;
        continue;
    }

    for (int& note : notes)
        std::cout << note << "\t";

    std::cout << std::endl;

    for (int& amount_note_to_withdraw : amount_notes_to_withdraw)
        std::cout << amount_note_to_withdraw << "\t";

    std::cout << std::endl;

    return 0;
}
