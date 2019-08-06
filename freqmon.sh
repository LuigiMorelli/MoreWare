#!/bin/bash -e
# First  optional parameter : number of samples (default 5)
# Second optional parameter : seconds between samples (default 1)
# Third  optional parameter : name of the file where data is stored

start=1

# Testing first parameter
if [ -z $1 ] 
then
	values=5
else 
	values=$1
fi

# Testing second parameter
if [ -z $2 ] 
then
	step=1
else 
	step=$2
fi

# Testing third parameter
if [ -z $3 ] 
then
	outfile=tempmon.csv
else 
	outfile=$3
fi

# Write file header
echo "Data,Temp" > $outfile

# Execution loop
while [ $start -le $values ]
do
	date +%T > pippo 
	gawk '{ printf("%s ",$1) }' pippo >>$outfile
	sudo cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq | gawk '{ printf(", %6.2f", $1) }' >>$outfile
	sudo cat /sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq | gawk '{ printf(", %6.2f", $1) }' >>$outfile
	sudo cat /sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq | gawk '{ printf(", %6.2f", $1) }' >>$outfile
	sudo cat /sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq | gawk '{ printf(", %6.2f", $1) }' >>$outfile
	gawk '{ printf(", %6.3f\n",$1/1000) }' /sys/class/thermal/thermal_zone0/temp >>$outfile
	start=$(( start+1 ))
	sleep $step
done
rm pippo
