/*
Step 1: Run this command to compile the file
        g++ 190101033_Assignment2.cpp -o assembler

Step 2: Run the executable file assembler.exe using the following command
        assembler <INPUT FILE> <OUTPUT FILE> <LISTING FILE>

        <INPUT FILE> is a required argument and is the name of the file which we need to read
        I have attached input.txt with my code which contains the sample input for the program

        Here <OUTPUT FILE> and <LISTING FILE> are optional arguments and by default will take
        output.txt and listing.txt values.

        Here using <OUTPUT FILE> you can name the output file according to your wish
        Using <LISTING FILE> you can name the listing file according to your wish

        Here if you want to add <LISTING FILE> then you have to add <OUTPUT FILE> also.

        Sample command:
        assembler.exe input.txt output.txt listing.txt

Step 3: After the assembler successfully assembles the code, I am asking for the program address.
        The user has to provide us with the program address in hexadecimal format.

Step 4: Check the output, listing, memory.txt, memory_visualizer.txt files created in the same directory whose name is either equal to their default values
        output.txt and listing.txt or equal to the names given by you during the execution.

opcodes_file.txt contains the opcodes and their corresponding values. So if you want to add, delete or edit opcodes, you can directly edit this file
memory.txt file contains the view of our memory where I have shown the values and their corresponding addresses i.e. all instruction's generated object codes and addresses are shown.
memory_visualizer.txt contains the actual view of our memory where data stored at all the addresses is shown.
Thus these files also takes into account the execution address related to our program.

*/

#include "utility.h"
#include "assembler/pass1.h"
#include "assembler/pass2.h"
#include "linker_loader/pass1.h"
#include "linker_loader/pass2.h"

int main(int argc, char *argv[])
{
        if (argc < 2) //  User will provide necessary informations required for the assembler like which input file to convert
        {             //  and what should be the name of the outfile file produced.
                cout << "Wrong format" << endl
                     << "USAGE: <INPUT_FILE_NAME> <OUTPUT_FILE_NAME> <LISTING_FILE_NAME>" << endl
                     << "OPTIONAL: <OUTPUT_FILE_NAME>, <LISTING_FILE_NAME>" << endl;
                return 0;
        }

        string intermediate_filename, output_filename, listing_filename, loader_output_filename, loader_output_visualizer_filename, prog_addr; // Will store the names of the files which will be opened.

        OPTAB_filler();                                                                                                                                 // Using OPTAB_filler(), we will first create the OPCodes Table
        set_variables(intermediate_filename, output_filename, listing_filename, loader_output_filename, loader_output_visualizer_filename, argc, argv); // Here I am setting the variables equal to the values given at the start
        int program_length = pass_1(argv[1], intermediate_filename);                                                                                    // As we are implementing 2 pass assembler, therefore this function will perform the pass1 and will return the program length
        pass_2(program_length, intermediate_filename, output_filename, listing_filename);                                                               // Pass 2 of the assembler

        cout << "Enter the program address in hexadecimal format... ";
        cin >> prog_addr;
        loader_pass_1(output_filename, prog_addr);                                                            // Pass 1 of the linker loader
        loader_pass_2(prog_addr, output_filename, loader_output_filename, loader_output_visualizer_filename); // Pass 2 of the linker loader

        return 0;
}