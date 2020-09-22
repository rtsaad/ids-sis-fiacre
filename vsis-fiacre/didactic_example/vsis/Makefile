example:
	gcc -c  -D POSIX -D_TICK_UNIT_=1000000000 -O2 -I lib/hippo -fmessage-length=0 -I ./example.hippo lib/hippo/hippo.c example.hippo/*.c ./*.c
	gcc -o example ./*.o -lpthread -lrt 
	rm *.o
clean:
	rm example | true
new: clean
	$(MAKE)
