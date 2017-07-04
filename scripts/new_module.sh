#!/bin/bash
PROJECT_NAME="cpp-template"
MODULE_NAME="$1"
mkdir $MODULE_NAME
cd $MODULE_NAME
mkdir -p "include/$PROJECT_NAME/$MODULE_NAME"
mkdir "lib"
mkdir "src"
mkdir "test"
touch CMakeLists.txt
