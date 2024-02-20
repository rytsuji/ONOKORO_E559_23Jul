#!/bin/bash

function usage() {
cat <<EOF
usage : $1 dc_name
usage : $2 setting_name
EOF
}

if [ $1_ = _ ] ; then
    usage $0
    exit
fi

prm_dir="$PWD/prm/mwdc/$1/dt2dl"
cd $prm_dir
if [ -d dummy ] ; then
    echo cp -r dummy $2
    cp -r dummy $2
else
    echo "$prm_dir/dummy not found."
fi
