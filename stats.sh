#!/bin/sh -e
gawk '{ printf("Temperatura :  %6.3f°C\n",$1/1000) }'  /sys/class/thermal/thermal_zone0/temp  									# Stampa la temperatura della CPU
echo																															# Lascia una linea vuota 
echo "Frequenza di lavoro dei cores :"
cat /sys/devices/system/cpu/cpu?/cpufreq/scaling_cur_freq | gawk '{ printf("CPU #%i      :  %6.2f GHz\n",i++, $1/1000000) }'	# Stampa la frequenza di lavoro dei cores
echo																															# Lascia una linea vuota
echo "Lista processori presenti:"
cat /proc/cpuinfo |grep processor																								# Stampa il nome dei processori presenti
echo																															# Lascia una linea vuota
echo "Stato della memoria fisica :"
cat /proc/meminfo |grep Mem																										# Stampa lo stato della memoria fisica 
echo																															# Lascia una linea vuota
echo "Descrizione del sistema audio :"
cat /proc/asound/version																										# Stampa la versione del sistema audio
echo																															# Lascia una linea vuota
echo "Partizioni:"
cat /proc/partitions																											# Stampa lo stato delle partizioni sul disco
echo																															# Lascia una linea vuota
echo "Carico CPU :"																												# Stampa il carico di CPU a intervalli diversi
gawk '{ printf("Load average :\n   1 minuto  : %3.2f%%\n   5 minuti  : %3.2f%%\n  15 minuti  : %3.2f%%\n",$1*100/4, $2*100/4, $3*100/4) }'  /proc/loadavg
echo																															# Lascia una linea vuota
echo "Ultimo reboot, utenti collegati, carico medio :"
uptime																															# Stampa tempo dall'ultimo reboot, utenti collegati e carico medio
