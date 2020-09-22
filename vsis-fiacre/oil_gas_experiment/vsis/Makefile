mce_oilngas:
	gcc -c  -D POSIX -D_TICK_UNIT_=10000000 -O2 -I lib/hippo/ -fmessage-length=0 -I ./mce_oilngas.hippo lib/hippo//hippo.c mce_oilngas.hippo/*.c ./*.c
	gcc -o mce_oilngas ./*.o -lpthread -lrt 
	rm *.o
clean:
	rm mce_oilngas | true
new: clean
	$(MAKE)
