#include <iostream>
#include <fstream>
#include <sstream>

bool areFilesEqual(const std::string& filename1, const std::string& filename2) {
    std::ifstream file1(filename1);
    std::ifstream file2(filename2);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error opening one or both files." << std::endl;
        return false;
    }

    std::stringstream buffer1;
    buffer1 << file1.rdbuf();

    std::stringstream buffer2;
    buffer2 << file2.rdbuf();

    return buffer1.str() == buffer2.str();
}

int main() {
    std::string file1Path = "path/to/file1.txt";  // Replace with the actual path to your first file
    std::string file2Path = "path/to/file2.txt";  // Replace with the actual path to your second file

    if (areFilesEqual(file1Path, file2Path)) {
        std::cout << "Files are identical." << std::endl;
    } else {
        std::cout << "Files are not identical." << std::endl;
    }

    return 0;
}
