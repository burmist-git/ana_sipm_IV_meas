#!/bin/bash

# Me 08 Jun 2022 14:02:24 CEST
# Autor: Leonid Burmistrov

function printHelp {
    echo " --> ERROR in input arguments "
    echo " [0] -d                     : default"
    echo " [0] -h                     : print help"
}

if [ $# -eq 0 ] 
then    
    printHelp
else
    if [ "$1" = "-d" ]; then
	make clean; make;
	convertIVlog="convertIV.log"
	rm -rf $convertIVlog
	for input_dir in ../data/IrradiationTests/*/; do
	    echo "Converting --> $input_dir"
	    info_file=$input_dir"info"
	    outputRootFile=$input_dir"hist.root";
	    ./convertIV 0 $input_dir $info_file $outputRootFile | tee -a $convertIVlog
	    echo ""
	    echo ""
	    echo ""
	done
    elif [ "$1" = "-h" ]; then
        printHelp
    else
        printHelp
    fi
fi
