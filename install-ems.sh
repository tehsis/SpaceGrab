#!/bin/bash

set -e

mkdir -p configure-temp
cd configure-temp

if [[ ! -d  ./emsdk-portable ]] 
then
curl https://s3.amazonaws.com/mozilla-games/emscripten/releases/emsdk-portable.tar.gz -o emsdk-portable.tar.gz
tar xvf emsdk-portable.tar.gz
./emsdk-portable/emsdk update
./emsdk-portable/emsdk install latest
./emsdk-portable/emsdk activate latest
fi

source ./emsdk-portable/emsdk_env.sh
