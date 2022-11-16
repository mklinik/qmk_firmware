#!/usr/bin/env bash

sleep 5; pmount sda1; cp crkbd_rev1_mkl_promicro_rp2040.uf2 /media/sda1; sync; pumount sda1
