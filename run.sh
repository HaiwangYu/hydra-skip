
time lar -n 1 -c prod_muminus_0.1-5.0GeV_isotropic_dune10kt_1x2x6.fcl -o gen.root
time lar -n 1 -c standard_g4_dune10kt_1x2x6.fcl -s gen.root -o g4.root
time lar -n 1 -c cfg/pgrapher/experiment/dune10kt-hd/wcls-sim-drift-simchannel-nf-sp.fcl -s g4.root -o tmp.root
