# crux
A simple hex editor implemented in C (formerly C-Rust Hex Editor or crux, but C >>>>>>>>>> Rust) :)

# compile from source + usage
Clone this repo, then build using GNU Make:

```bash
make
```

If you wish to install this to your system then run `make install`. Uninstall w/ `make uninstall`.

Then just follow instructions and do as you wish!

Reminder that you cannot add bytes to the file at given location, since I'd then need to shift a bunch of stuff, and that sucks a bit (in terms of speed to my knowledge).
- I also just suck a bit at C development but whatever.
