#!/bin/sh

./build.sh && ./stress-test $(nproc) 10000000
