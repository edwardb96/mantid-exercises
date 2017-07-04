./scripts/build.sh
if [ $? == 0 ]; then
    cd build
    ctest --output-on-failure
    cd ..
fi
