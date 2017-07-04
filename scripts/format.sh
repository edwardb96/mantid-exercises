#!/bin/bash
find . -not -path "*/build/*" -not -path "*/scripts/*" -name '*.cc' -o -name '*.hh' -o -name '*.tcc' | xargs clang-format -i