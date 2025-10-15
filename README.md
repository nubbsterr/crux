# crux
A simple hex editor implemented in both C and Rust to learn both languages :)

# agenda
The C implementation is complete and works nicely.

Rust implementation has been started and is going well! The print_hex function has been implemented nicely and works well. My big gripe at the moment is the goofy distribution of standard library functions and overall iffy and odd usage of format specifiers in Rust. I spent a lot of time looking for things that take 2 seconds to find in C and I don't know why that is.

# usage
For the C implementation, compile w/ `gcc`:

```bash
gcc crux.c -o crux
./crux <filename>
```

For the Rust implementation, either use `rustc <filename>` or clone this repo and build like so:

```bash
cargo build
./target/debug/crux <filename>
```
