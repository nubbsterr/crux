# makefiles are amazing
CC = gcc
TARGET = crux
MANPAGE = crux.1
MANDIR = /usr/local/share/man/man1
CFLAGS = -Wall -Wextra -Werror -pedantic -O2

PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET)

clean:
	@echo "Cleaning up..."
	rm -f $(TARGET)

install: $(TARGET)
	@echo "Creating $(BINDIR) directory..."
	mkdir -p $(BINDIR)
	@echo "Installing $(TARGET) to $(BINDIR)..."
	sudo install -m 755 $(TARGET) $(BINDIR)
	@echo "Installing manpage..."
	gzip $(MANPAGE)
	sudo mkdir -p $(MANDIR)
	mv $(MANPAGE).gz $(MANDIR)
	@echo "Done!"

uninstall:
	@echo "Uninstalling $(TARGET) from $(BINDIR) and removing manpage..."
	rm -f $(BINDIR)/$(TARGET)
	sudo rm -f $(MANDIR)/$(MANPAGE).gz

.PHONY: all clean install uninstall

