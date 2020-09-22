MODEL=mce_oilngas.fcr
VERIFY_INPUTS=-DVERIFY_INPUTS=TRUE
VERIFY_2oo4=-DVERIFY_2oo4=TRUE
VERIFY_2oo5=-DVERIFY_2oo5=TRUE
VERIFY_2oo7=-DVERIFY_2oo7=TRUE
VERIFY_2oo10=-DVERIFY_2oo10=TRUE

all: input

input:
	gpp $(MODEL) $(VERIFY_INPUTS)  > mce_oilngas_model.fcr

v2oo4: 
	gpp $(MODEL) $(VERIFY_2oo4)  > mce_oilngas_model.fcr

v2oo5: 
	gpp $(MODEL) $(VERIFY_2oo5)  > mce_oilngas_model.fcr

v2oo7: 
	gpp $(MODEL) $(VERIFY_2oo7)  > mce_oilngas_model.fcr

v2oo10: 
	gpp $(MODEL) $(VERIFY_2oo10)  > mce_oilngas_model.fcr

clean:
	rm -rf mce_oilngas_model.fcr *.tts *.ktz