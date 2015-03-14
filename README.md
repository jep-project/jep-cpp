# jep-cpp
JEP C++ Library

Used Build Tool is the bake-toolkit aka bake.

Project structure
========================================================= 

    |-- Project.meta            # build configuration for the bake-tookit (see: https://rubygems.org/gems/bake-toolkit)
    |
    |-- include                 # include directory of the jep-cpp library
    |-- src                     # the c/cpp files for the jep library
    |
    |-- libs                    # contains the external libraries used in jep=cpp 
    |   |-- gmock
    |   `-- msgpack-c
    `-- test                    # contains all test related files
        |-- fixtures            # contains all test fixtures 
        |   |-- include
        |   `-- src
        |-- mocks               # contains all mocks jep-cpp related mocks
        |   |-- inlcude
        |   `-- src
        `-- tests               # contains the actual tests
            |-- include
            `-- src

