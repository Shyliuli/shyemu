#include"io.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_filename>" << std::endl;
        return 1;
    }

    // Get the input filename from the command-line argument
    const std::string inputFilename = argv[1];
   read_file(inputFilename);


    return 0;
}