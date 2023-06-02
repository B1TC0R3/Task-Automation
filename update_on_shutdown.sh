#!/bin/bash

flag_directory=/opt/flags
error_flag=/opt/flags/update_error.flag

if [ ! -d $flag_directory ]; then
    notify-send --urgency=critical --action="Abort shutdown" "Error while running update script!" "Directory '$flag_directory' does not exist\nUnable to flag potential update issues."
    exit
fi

if [ -f $error_flag ]; then
    rm $error_flag
fi

sudo paru -Syyu || touch $error_flag
shutdown -P now
