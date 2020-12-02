#!/bin/bash

# TO BE USED IN /SCRIPTS/ OF allsky repository

# This is to archive the XML Data for each exposure

source $ALLSKY_HOME/config.sh
source $ALLSKY_HOME/scripts/filename.sh
source $ALLSKY_HOME/scripts/darkCapture.sh
source $ALLSKY_HOME/scripts/darkSubtract.sh
source $ALLSKY_HOME/scripts/ftp-settings.sh

cd $ALLSKY_HOME

CURRENT=$(date -d '12 huours ago' + '%Y%m%d')
mkdir -p xmlraw/$CURRENT
if [ $XML_SAVE = "true" ]; then
    IMAGE_TO_USE="data_raw_live.xml"
    TXT_TO_USE="xml_log.txt"

    echo "saving xml and txt"
    cp $IMAGE_TO_USE "xmlraw/$CURRENT/xml_data-$(date +'Y%m%d%H%M%S').xml"
    cp $TXT_TO_USE "xmlraw/$CURRENT/xml_info_exp-$(date +'Y%m%d%H%M%S').txt"
fi
