#!/bin/bash

function usage() {
cat <<EOF
usage : $1 run_in
usage : $2 run_out
EOF
}

if [ $1_ = _ ] ; then
    usage $0
    exit
fi

dir_gate_gr="$PWD/steering/gate/gr"
dir_gate_las="$PWD/steering/gate/las"

dir_vdc_gr="$PWD/steering/vdc/gr"
dir_vdc_las="$PWD/steering/vdc/las"

#dir_dt2dl_gr="$PWD/prm/vdc_gr/dt2dl"
#dir_dt2dl_las="$PWD/prm/vdc_las/dt2dl"

dir_hist_phys="$PWD/hist/phys/run/"

cd $dir_gate_gr

if [ -e gate_gr_${1}.yaml ] ; then
echo "ln -sf gate_gr_$1.yaml gate_gr_$2.yaml"
if [ -e gate_gr_${2}.yaml ] ; then
    unlink gate_gr_$2.yaml
fi
    ln -s gate_gr_$1.yaml gate_gr_$2.yaml
else
    echo "gate_gr_$1.yaml not found."        
fi
   
cd $dir_gate_las
if [ -e gate_las_${1}.yaml ] ; then
echo "ln -sf gate_las_$1.yaml gate_las_$2.yaml"
if [ -e gate_las_${2}.yaml ] ; then
    unlink gate_las_$2.yaml
fi
    ln -sf gate_las_$1.yaml gate_las_$2.yaml
else
    echo "gate_las_$1.yaml not found."        
fi

cd $dir_vdc_gr
if [ -e vdc_gr_${1}.yaml ] ; then
echo "ln -sf vdc_gr_$1.yaml vdc_gr_$2.yaml"
if [ -e vdc_gr_${2}.yaml ] ; then
    unlink vdc_gr_$2.yaml
fi    
    ln -sf vdc_gr_$1.yaml vdc_gr_$2.yaml
else
    echo "vdc_gr_$1.yaml not found."
fi

cd $dir_vdc_las
if [ -e vdc_las_${1}.yaml ] ; then
echo "ln -sf vdc_las_$1.yaml vdc_las_$2.yaml"
if [ -e vdc_las_${2}.yaml ] ; then
    unlink vdc_las_$2.yaml
fi    
    ln -sf vdc_las_$1.yaml vdc_las_$2.yaml
else
    echo "vdc_las_$1.yaml not found."
fi    

cd $dir_hist_phys
if [ -e phys_${1}.hist.yaml ] ; then
echo "ln -sf phys_${1}.hist.yaml phys_${2}.hist.yaml"
if [ -e phys_${2}.hist.yaml ] ; then
    unlink phys_${2}.hist.yaml
fi
    ln -sf phys_${1}.hist.yaml phys_${2}.hist.yaml
else
    echo "phys_${1}.hist.yaml not found."
fi    
#cd $dir_hist_phys
#    unlink -f  gate_gr_$2.yaml
#    ln -sf gate_gr_$1.yaml gate_gr_$2.yaml    

    
