#!/usr/bin/env bash
cmake .. -DPYTHON_LIBRARY_DIR="/Users/bernardocohen/opt/anaconda3/lib/python3.8/site-packages" -DPYTHON_EXECUTABLE="/Users/bernardocohen/opt/anaconda3/bin/python3"
make
make install
