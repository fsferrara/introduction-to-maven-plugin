#! /bin/bash -x

SRC_DIR="./src"
DST_DIR="./out"

protoc -I=$SRC_DIR --java_out=$DST_DIR $SRC_DIR/addressbook.proto
