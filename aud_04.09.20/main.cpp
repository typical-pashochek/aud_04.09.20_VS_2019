#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "");

    std::vector<std::string> students;

    std::string buffer = "";

    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
    }

    while (std::getline(file, buffer)) {
        if (buffer.size() > 0) {
            students.push_back(buffer);
        }
    }

    unsigned int vector_size = students.size();

    for (int i = 0; i < vector_size; i++) {
        for (int j = i + 1; j < vector_size; j++) {
            if (students[i] == students[j]) {
                students.erase(students.begin() + j);
                vector_size -= 1;
            }
        }
    }

    for (int i = 0; i < vector_size; i++) {
        for (int j = i + 1; j < vector_size; j++) {
            if (students[i] > students[j]) {
                std::swap(students[i], students[j]);
            }
        }
    }

    for (int i = 0; i < vector_size; i++) {
        std::cout << students[i] << std::endl;
    }

    file.close();
    return 0;
}