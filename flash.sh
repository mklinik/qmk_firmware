#!/usr/bin/env bash

DEVICE=$1

if [ -z $DEVICE ]
then
  echo "usage: $0 <device>"
  echo "<device> as what pmount expects, for example sda1"
  exit 1
fi

sleep 5
pmount $DEVICE
cp crkbd_rev1_mkl_promicro_rp2040.uf2 /media/$DEVICE
sync
pumount $DEVICE
