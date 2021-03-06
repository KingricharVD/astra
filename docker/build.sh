#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-astracore/astra}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/astrad docker/bin/
cp $BUILD_DIR/src/astra-cli docker/bin/
cp $BUILD_DIR/src/astra-tx docker/bin/
strip docker/bin/astrad
strip docker/bin/astra-cli
strip docker/bin/astra-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
