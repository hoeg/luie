#!/bin/bash

BASE_DIR=$(dirname "$(readlink -f $0)")
BASE_NAME=$(basename "${BASE_DIR}")

BUILD_DIR=${BASE_DIR}/build/

mkdir -p ${BUILD_DIR} || exit $?
pushd ${BUILD_DIR}

cmake -DCMAKE_BUILD_TYPE=Debug ${BASE_DIR} || exit $?
make || exit $?
