#!/bin/zsh

OSINFO=$(uname -a)
PPROC=$(grep -c 'processor' /proc/cpuinfo)
VPROC=$(grep 'architecture' /proc/cpuinfo | uniq | awk '{print $3}')
TRAM=$(top -bn1 | grep 'MiB Mem' | awk '{print $4}')
URAM=$(top -bn1 | grep 'MiB Mem' | awk '{print $6}')
PRAM=$(top -bn1 | grep 'MiB Mem' | awk '{printf("%.2f"), $6/$4*100}')
TDISK=$(df | awk 'NR==4' | awk '{printf("%.2f"), $2/1000000}')
UDISK=$(df | awk 'NR==4' | awk '{printf("%.2f"), $3/1000000}')
PDISK=$(df | awk 'NR==4' | awk '{printf("%.2f"), $3/$2*100}') 
CPUL=$(top -bn1 | grep '%Cpu' | awk '{printf("%.2f"), 100-$8}')
LVMS=$(lsblk -o TYPE | grep -c 'lvm')
LVMB=$(if [ $LVMS -eq 0 ]; then echo no; else echo yes; fi)
TCP=$(grep 'TCP' /proc/net/sockstat | awk '{print $3}')
UDP=$(grep 'UDP:' /proc/net/sockstat | awk '{print $3}')
COT=$(($TCP+$UDP))
USERS=$(who | awk '{print $1}' | uniq | wc -l)
MAC=$(ip a | grep 'link/ether' | tail -n 1 | awk '{print $2}')
IP=$(ip a | grep 'inet ' | tail -n 1 | awk '{print $2}')
SUDO=$(journalctl _COMM=sudo | grep -c 'TTY=')

echo "	#Architecture: $OSINFO
	#PCPU: $PPROC
	#VCPU: $VPROC
	#RAM: $URAM/$TRAM Mb ($PRAM%)
	#DISK: $UDISK/$TDISK Gb ($PDISK%) 
	#CPU Load: $CPUL%
	#LVM: $LVMB
	#Connections: $COT
	#Users: $USERS
	#Network: IP=$IP MAC=$MAC
	#Sudo: $SUDO cmds "
