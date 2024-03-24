#!/bin/bash
source ~/.bash_profile

source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
#setup dunesw v09_77_00d00 -q e20:prof
setup dunesw v09_82_01d00 -q e26:prof

#setup larwirecell v09_80_00rc2 -q e20:prof
#setup hdf5 v1_10_5 -q e19
#setup h5cpp v1_10_4_1
#path-prepend /dune/app/users/yuhw/larsoft/v09_18_00/srcs/dunetpc/dune/DUNEWireCell/ FHICL_FILE_PATH

path-prepend /exp/dune/app/users/yuhw/opt/lib64 LD_LIBRARY_PATH
path-prepend /exp/dune/app/users/yuhw/wct/cfg WIRECELL_PATH
path-prepend /exp/dune/app/users/yuhw/wire-cell-data WIRECELL_PATH
