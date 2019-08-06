#!/bin/bash -e
i=0 
totale=0
media=0

gawk 'BEGIN { FS=","; trend=0; i=0} { if ($1 != "Data")  { i++; media_cpu=($2+$3+$4+$5)/4; trend=(trend+media_cpu); print media_cpu, trend/i; } }'
