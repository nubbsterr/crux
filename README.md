# crux
A simple hex editor implemented in C (formerly C-Rust Hex Editor or crux, but C >>>>>>>>>> Rust) :)

# usage
For the C implementation, compile w/ `gcc`:

```bash
gcc crux.c -o crux
./crux <filename>
```

Then just follow instructions and do as you wish! Reminder that you cannot add bytes to the file at given location, since I'd then need to shift a bunch of stuff, and that sucks a bit (in terms of speed to my knowledge!)
