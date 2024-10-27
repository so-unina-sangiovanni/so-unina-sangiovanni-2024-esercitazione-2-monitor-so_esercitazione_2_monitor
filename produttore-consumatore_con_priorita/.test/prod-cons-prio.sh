#!/bin/bash

source $(dirname "$0")/../../.test/test.sh

BINARY=start
OUTPUT=/tmp/output.txt
TIMEOUT=60
SKIPPED=0


init_feedback "Esercizio produttore-consumatore con priorità, con processi"

compile_and_run $BINARY $OUTPUT $TIMEOUT


perl -n -e 'BEGIN{$counter=0; $coda1=0; $coda2=0; %prod1=(); %prod2=(); %cons=(); @produced=(); @consumed=(); } if(/Produttore\s(\d)\sentrato\snel\smonitor/) { if($1==1) {$coda1++;} else {$coda2++;} } if(/Produttore\s(\d)\scon\spid\s\d+\sha\sprodotto\s(\d+)/) { push @produced,$2; if($1==1) {$coda1--;} else { if($coda1>0) { exit(1); } $coda2--;} } if(/Consumatore\scon\spid\s\d+\sha\sconsumato\svalore\s(\d+)/) { push @consumed,$1; } if($counter>3 || $counter<0) { exit(1); } END { if($#produced!=$#consumed) { exit(1); }  for $i(0..$#produced) { if($produced[$i]!=$consumed[$i]){ exit(1); } } }' $OUTPUT

if [ $? -ne 0 ]
then
    failure "L'esecuzione non rispetta l'ordine corretto delle produzioni e delle consumazioni"
fi


static_analysis


success


