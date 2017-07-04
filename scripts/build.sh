#/bin/bash
cd build
cmake ../
cmake --build . --target all
EXIT_CODE=$?
cd ..
exit $EXIT_CODE
