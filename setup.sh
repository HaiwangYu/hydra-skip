#!/bin/bash
source ~/.bash_profile

source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
#setup dunesw v09_77_00d00 -q e20:prof
setup dunesw v09_82_01d00 -q e26:prof
#setup dunesw v09_90_00d00 -q e26:prof

path-prepend /exp/dune/app/users/yuhw/opt/lib64 LD_LIBRARY_PATH
path-prepend /exp/dune/app/users/yuhw/wct/cfg WIRECELL_PATH
path-prepend /exp/dune/app/users/yuhw/wire-cell-data WIRECELL_PATH
path-prepend /exp/dune/app/users/yuhw/dunefd/hydra-skip/cfg WIRECELL_PATH
