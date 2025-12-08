# crux
A simple hex editor implemented in C (formerly C-Rust Hex Editor or crux, but C >>>>>>>>>> Rust) :)

# installation
Clone this repo, then build using GNU Make:

```bash
https://github.com/nubbsterr/crux.git
cd crux
make
```

This will produce an executable in the `crux` directory.

If you wish to install this to your system then run `sudo make install`. Uninstall with `sudo make uninstall`.
- Note that `make install` will also install a manpage for crux, which can be viewed with `man crux`!

Then just follow instructions and do as you wish!

Reminder that you cannot add bytes to the file at given location, since I'd then need to shift a bunch of stuff, and that sucks a bit (in terms of speed to my knowledge).
- I also just suck a bit at C development but whatever.
