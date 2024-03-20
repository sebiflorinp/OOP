cmake_minimum_required(VERSION 3.27)
project(lab2_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2_4 main.c
        ui/ui.c
        ui/ui.h
        domain/models.h
        domain/models.c
        domain/models.c
        domain/validators.c
        domain/validators.h
        repos/repos.c
        repos/repos.h
        controllers/controllers.c
        controllers/controllers.h
        utils/utils.c
        utils/utils.h
        tests/repoTests.c
        tests/repoTests.h
        tests/tests.c
        tests/tests.h
        tests/validatorsTest.c
        tests/validatorsTest.h
        tests/controllerTests.c
        tests/controllerTests.h
        tests/utilsTests.c
        tests/utilsTests.h)
