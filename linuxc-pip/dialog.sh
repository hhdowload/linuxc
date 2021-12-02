#!/bin/bash


[ -e /tmp/tmp_choice ] || touch /tmp/tmp_choice
exec 2>/tmp/tmp_choice
dialog --title "service log  " --menu "loglog" 10 30 2 1  "eureka "  2 "date"
CHOICE=`cat /tmp/tmp_choice`

if [ $CHOICE -eq 1 ];then
	dialog  --tailbox log/date.log 500 500
	dialog	--title "注意" --yesno "你要退出吗" 20 20
	[ $? -eq 0 ] && clear && exit 
elif [[ $CHOICE == "2" ]];then
	dialog --msgbox "ni hao a" 17 17
fi

clear

read line
echo "WO MEN JIXU"
