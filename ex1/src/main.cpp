#include "mantid-exercises/ex1/CountWordFrequency.h"
#include "mantid-exercises/ex1/PairRangeToOrderedVector.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string file_to_string(std::ifstream& file) {
    auto file_string_stream = std::stringstream{};
    file_string_stream << file.rdbuf();
    return file_string_stream.str();
}

std::ostream& new_row(std::ostream& os) {
    os << '\n';
    return os;
}

std::ostream& word_column(std::ostream& os) {
    os << std::left << std::setfill(' ') << std::setw(17);
    return os;
}

std::ostream& usage_column(std::ostream& os) {
    os << std::right << std::setfill(' ') << std::setw(5);
    return os;
}

void print_frequency_table_row(std::ostream& os, std::pair<std::string, int> const& row) {
    new_row(os);
    word_column(os) << row.first;
    usage_column(os) << row.second;
}

template <typename PairInputIterator>
void print_frequency_table(std::ostream& os, PairInputIterator begin, PairInputIterator end) {
    word_column(os) << "Word";
    usage_column(os) << "Usage";
    for (auto current = begin; current != end; current++)
        print_frequency_table_row(os, *current);
    os << std::endl;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        auto input_filename = std::string{argv[1]};
        auto infile         = std::ifstream{input_filename};
        auto outfile        = std::ofstream{"results.txt", std::ofstream::out};
        auto line           = std::string{};

        if (infile.is_open()) {
            if (outfile.is_open()) {
                auto const file_string = file_to_string(infile);
                auto const frequency_map =
                        count_word_frequency(file_string.begin(), file_string.end());
                auto const ordered_frequencies = make_ordered_vector<std::string, int>(
                        frequency_map.begin(), frequency_map.end(), [](auto&& a, auto&& b) -> auto {
                            return a.second > b.second;
                        });
                print_frequency_table(
                        outfile, ordered_frequencies.begin(), ordered_frequencies.end());
                return 0;
            } else {
                std::cerr << "Failed to create results.txt output file." << std::endl;
                return 1;
            }
        } else {
            std::cerr << "No file with path '" << input_filename << "' exists." << std::endl;
            return 1;
        }
    }
}
