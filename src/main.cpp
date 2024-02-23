#include "io.h"
#include "run_program.h"
using namespace std;
int main(int argc, char* argv[]) {

    string inputFilename = "a.sfs"; // Set default input filename

    // Check if the user requested help with -h
    if (argc == 2 && string(argv[1]) == "-h") {
        cout << "Usage: " << argv[0] << " <input_filename>\n"
                  << "Default input file is 'a.sfs'.\n"
                  << "Use '-h' for help." << endl;
        return 0;
    }

    // Override default filename if provided as argument
    if (argc == 2) {
        inputFilename = argv[1];
    } else if (argc > 2) {
        cerr << "Usage: " << argv[0] << " <input_filename>\n"
                  << "Use '-h' for help." << endl;
        return 1;
    }

    // Read the file
    read_file(inputFilename);
    run_program();
    return 0;
}