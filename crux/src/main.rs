use std::fs;    // file IO, src: https://doc.rust-lang.org/beta/std/fs/fn.read_to_string.html
use std::env;   // CLI argument handling

fn print_hex(buffer: String, numchars: i32) -> i32 {
    let mut totalbytes: i32 = 0;
    for (i, byte) in buffer.bytes().enumerate() { // enumerate to keep track of indice to print newline
        if i % 10 == 0 {
            print!("\n{} | ", i/10);
        }
        print!("{:02X} ", byte); // took 10 yrs to figure out how to do this trash
        totalbytes+=1;
    }
    return totalbytes;
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let filepath = &args[1];

    let contents = fs::read_to_string(filepath).expect("[-] File not found or was not given.");
    // TODO:
    // * implement the print_hex function; need to cycle through each indice in buffer and print
    // hex bytes (2 characters out)
    // * have error checking for OOB
    // * have basic file i/o to read/close the file
    println!("[+] Reading file {}", filepath);
    let bytesread = print_hex(contents, 1024);

    println!("\n[+] Read {} bytes from {}\n", bytesread, filepath);
}
