#! /usr/bin/env bash

# Input parameters
usage() {
   echo -e "\nusage: `basename $0` -p <problem1>\n";
   echo -e "Other options:";
   echo -e "\t -h \t help";
}

# Default parameters
PROBLEM="001"

# Retrieving options
while getopts :p:vdh opt; do
   case $opt in
      p)
         PROBLEM=${OPTARG}
         ;;
      h)
         usage;
         exit 0;
         ;;
      \?)
         usage;
         exit 1;
         ;;
   esac
done
PROBLEM_DIR=./problems/${PROBLEM}
echo -e ">> PROBLEM: ${PROBLEM_DIR}";

BASE_DIR=`dirname $0`
cd ${BASE_DIR}

TARGET_DIR=${PROBLEM_DIR}/target
echo -e ">> CLEANING: ${TARGET_DIR}"
rm -rf ${TARGET_DIR};
mkdir ${TARGET_DIR};

echo -e ">> BUILDING: ${PROBLEM_DIR}"
javac -d ${TARGET_DIR} -cp "${TARGET_DIR}:./lib/junit5.0.3/*" ${PROBLEM_DIR}/*.java

echo -e ">> RUNNING TESTS"
java -jar ./junit-platform-console-standalone-1.0.3.jar --scan-class-path --class-path "${TARGET_DIR}:./lib/junit5.0.3/*"

echo -e ">> DONE!";
cd -

exit 0
