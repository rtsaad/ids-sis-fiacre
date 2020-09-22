
# full path of the frac libraries (please adapt)
FRACLIB=/home/digaots/Programs/frac-2.5.0/lib

# specify a store library
STORE=avl

# default compiler to gcc
CC=gcc

# default optimizations flags
OPTFLAGS=-O2

# x86_64-linux specific
EXT=.so
SHFLG=-shared -fPIC -fpic
CFLAGS=-m64
CDEFS=

# for compatibility with older interface; handles "make NAME=myapp"
default:
	@if test $(NAME); then $(MAKE) -f $(FRACLIB)/../Makefile $(NAME); else echo "usage:  make rootname"; fi

clean:
	rm -rf *.tts *.ktz

# compiles the library into the tts
%:
	$(CC) $(CFLAGS) $(CDEFS) $(OPTFLAGS) -o $*.tts/$*$(EXT) $(SHFLG) -I $(FRACLIB) -I $(FRACLIB)/$(STORE) $*.tts/`basename $*`.c $(CLIBS)
