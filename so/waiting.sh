#!/bin/bash

help()
{
    echo
    echo "This script checks for differences in websites over a period of time and opens them if any were detected."
    echo "Syntax: ./waiting.sh [OPTIONS] [URLS]"
    echo "Options:"
    echo "    -b	change the browser used [default: firefox]"
    echo "    -e	exit after the first change has been detected"
    echo "    -f	print information about change in a log file"
    echo "    -h	display the help page"
    echo "    -l	use a file of URLs instead of parameters"
    echo "    -p	print information about change on the screen"
    echo "    -t	change time interval between checks specified in seconds [default: 600]"
    echo
}

TIME=600
BROWSER="firefox"
EXIT=0
OUT=0
OUTFILE=""
INFILE=""
URLS=()

OPTIONS=b:efhl:pt:

if [[ $# -eq 0 ]]; then
    help
    exit 1
fi

! PARSED=$(getopt --options=$OPTIONS --name "$0" -- "$@")

eval set -- "$PARSED"

while true; do
    case "$1" in
	-b)
        BROWSER="$2"
        shift 2
        ;;
    -e)
        EXIT=1
        shift
        ;;
    -f)
        OUTFILE="waiting.log"
        shift
        ;;
    -h)
        help
        exit 1
        ;;
    -l)
        INFILE="$2"
        shift 2
        ;;
    -p)
        OUT=1
        shift
        ;;
    -t)
        TIME=$2
        shift 2
        ;;
    --)
        shift
        break
    esac
done


if [[ -n "$INFILE" ]]; then
    while read line; do
        URLS+=("$line")
    done < $INFILE
elif [[ $# -gt 0 ]]; then
    while [[ $# -ge 1 ]]; do
        URLS+=("$1")
        shift
    done
else
    echo "No URLs specified!"
    exit 1
fi

if [[ ! -d old ]]; then
    mkdir old
fi
if [[ ! -d new ]]; then
    mkdir new
fi
if [[ $OUTFILE ]]; then
    touch $OUTFILE
    > $OUTFILE
fi

while true; do
    AM=1
    for url in $URLS; do
        wget -q -O ./old/$AM $url
        AM+=1
    done
    AM=1
    sleep $TIME
    for url in $URLS; do
        wget -q -O ./new/$AM $url
        AM+=1
    done
    AM=1
    for url in $URLS; do
        DIFF=$(diff ./old/$AM ./new/$AM)
        if [[ $? -ne 0 ]]; then
            if [[ $OUT -eq 1 ]] || [[ -n "$OUTFILE" ]]; then
                if [[ -n "$OUTFILE" ]]; then
                    echo "$url - difference found" >> "$OUTFILE"
                fi
                if [[ $OUT -eq 1 ]]; then
                    echo "$url - difference found"
                fi
            else
                $($BROWSER $url &)
            fi
            if [[ $EXIT -ne 0 ]]; then
                exit
            fi
        fi
        AM+=1
    done   
done
