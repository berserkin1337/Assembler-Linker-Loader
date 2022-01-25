
Step 1: Run this command to compile the file
        g++ Main.cpp -o assembler

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
