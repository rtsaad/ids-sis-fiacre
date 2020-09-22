MODEL=example.fcr
VERIFY_EFFECT1=-DVERIFY_EFFECT1=TRUE
VERIFY_EFFECT2=-DVERIFY_EFFECT2=TRUE
VERIFY_EFFECT3=-DVERIFY_EFFECT3=TRUE
VERIFY_EFFECT4=-DVERIFY_EFFECT4=TRUE

all: input

effect1:
	gpp $(MODEL) $(VERIFY_EFFECT1)  > example_model.fcr

effect2: 
	gpp $(MODEL) $(VERIFY_EFFECT2)  > example_model.fcr

effect3: 
	gpp $(MODEL) $(VERIFY_EFFECT3)  > example_model.fcr

effect4: 
	gpp $(MODEL) $(VERIFY_EFFECT4)  > example_model.fcr

clean:
	rm -rf example_model.fcr *.tts *.ktz