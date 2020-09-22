#!/bin/sh

INPUT=$1
MODEL='models/example_model'

if [ $# -eq 0 ]
  then
    echo 'No arguments supplied.\nPlease, select a valid argument: effect1, effect2, effect3 or effect4.'
elif [ $# -eq 0 -o $INPUT != "effect1" -a $INPUT != "effect2" -a $INPUT != "effect3" -a $INPUT != "effect4" ]; then
  echo 'Please, select a valid argument: effect1, effect2, effect3 or effect4.'
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