#!/bin/sh

./build.sh && ./stress-test $(grep -c ^processor /proc/cpuinfo) 10000000
