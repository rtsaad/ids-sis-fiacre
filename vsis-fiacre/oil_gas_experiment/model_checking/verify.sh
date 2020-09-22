#!/bin/sh

INPUT=$1
MODEL='models/mce_oilngas_model'

if [ $# -eq 0 ]
  then
    echo 'No arguments supplied.\nPlease, select a valid argument: input, v2oo4, v2005, v2007 or v2oo10.'
elif [ $# -eq 0 -o $INPUT != "input" -a $INPUT != "v2oo4" -a $INPUT != "v2oo5" -a $INPUT != "v2oo7" -a $INPUT != "v2oo10" ]; then
  echo 'Please, select a valid argument: input, v2oo4, v2005, v2007 or v2oo10.'
else

echo "Model Selected $MODEL"
echo "Generate FIACRE $INPUT"
make --directory models $INPUT
echo "Generating TTS"
frac -obs $MODEL.fcr model.tts
echo '\n\nCompiling' 
make NAME=model
echo '\n\nExploring State Space with Tina'
tina model.tts model.ktz
echo '\n\nVerifing Properties with Selt'
selt model.ktz model.tts/model.ltl

fi