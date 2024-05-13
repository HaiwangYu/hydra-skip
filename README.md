```bash
./js.sh all wct-sim-fans-hydra.jsonnet
wire-cell -l stdout -L debug -c wct-sim-fans-hydra.jsonnet
```

## dune10kt-vd
```bash
time lar -n 1 -c cfg/pgrapher/experiment/dune10kt-vd/wcls-sim-drift-simchannel-nf-sp.fcl -s g4.root -o tmp.root >& log
```


## dune10kt-hd

```bash
time lar -n 1 -c cfg/pgrapher/experiment/dune10kt-hd/wcls-sim-drift-simchannel-nf-sp.fcl -s g4.root -o tmp.root >& log
```