// initially built off of Nir Lichtman's own guide: https://www.youtube.com/watch?v=aSkW8HgQbSk
// has some more error checking and cool features/prompts

#include <stdio.h>
#include <stdbool.h>

// print the hex values of the read ascii chars in the buffer
void print_hex(unsigned char* buffer, int numchars) {
    printf(" 0  1  2  3  4  5  6  7  8  9  10");
    for (int i = 0; i < numchars; i++) {
        if (i % 10 == 0) // every 10 hex bytes gets a newline and prints a number line
            printf("\n%d | ", i/10);
        
        // .2 will ensure 2 bytes are printed per hex character 
        printf("%.2X ", buffer[i]);
    }
}


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("[-] No file was given.");
        return 1;
    }


    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("[-] Error when opening file.");
        return 1;
    }

    // unsigned since we're storing ASCII, 0 - 255
    unsigned char buffer[1024] = {0};
    // buffer, size of elements being read, the count of elements to be read, the stream to read from
    int numBytesRead = fread(buffer, sizeof(char), 1024, file);
    printf("[+] Bytes read: %d bytes\n", numBytesRead);

    print_hex(buffer, numBytesRead);
    printf("\n[+] Successful hex read of buffer.\n");

    while (true) {
        char cmd;
        int loc;

        printf("[+] Enter a cmd [p(rint),e(dit),s(ave),force q(uit)] and location [int] (p1, e3...)\n$ ");
        if (scanf(" %c%d", &cmd, &loc) == 2) {
            // verify that the correct amount of args were parsed
            // NOTE that this does NOT handle edge cases where multiple inputs are given; e.g. 42 42 will error out twice, though this is better than some undefined behaviour trash
            ;
        } else {
            printf("[!] Failed to parse input!\n");
            continue;
        }
        if (cmd == 'p') { // print within buffer bounds
            // if over ternary op for ISO C compliance cuz that's cool lololol
            if (loc <= (numBytesRead-10) && loc > 0) {
                print_hex(buffer + loc, 10);
            } else {
                printf("[!] OOB buffer access spotted!\n");
            }
        }

        else if (cmd == 'e') { // edit  
                          // %hhx will ingest just one hex byte and edit THAT byte in the given file
                          // specifically, hh will turn the input into an unsigned char*, which as we know is 1 byte
                          // src: https://stackoverflow.com/questions/21782244/what-is-the-need-of-hh-and-h-format-specifiers
                          // if this is not done, then scanf actually overruns and edits 4 bytes into the file; 1 for the input and 3 null bytes
            if (loc <= (numBytesRead-10) && loc > 0) { 
                printf("[+] Enter hex byte to input.\n$ ");
                scanf(" %hhx", buffer + loc); 
            } else { 
                printf("[!] OOB buffer access spotted!\n"); 
            }
        }

        else if (cmd == 's') { // break from loop and write to buffer
                          // THIS WILL FAIL IF THERE IS NOTHING NEW IN THE BUFFER!
            break;
        }

        else if (cmd == 'q') {
            fclose(file);
            return 0;
        }

        else {
            printf("[!] Invalid input was given!!\n");
        }
        printf("\n"); 
    }

    fclose(file);
    // close then reopen to edit as needed
    file = fopen(argv[1], "w");
    fwrite(buffer, sizeof(char), 1024, file);
    fclose(file);
    printf("[+] Edits to file '%s' complete.", argv[1]);

    return 0;
}
