# Set the compilers based upon the PETSc package
find_package(PkgConfig REQUIRED)
pkg_get_variable(PETSC_C_COMPILER PETSc ccompiler)
set(CMAKE_C_COMPILER ${PETSC_C_COMPILER})
pkg_get_variable(PETSC_CXX_COMPILER PETSc cxxcompiler)
set(CMAKE_CXX_COMPILER ${PETSC_CXX_COMPILER})
pkg_get_variable(PETSC_F_COMPILER PETSc fcompiler)
set(CMAKE_Fortran_COMPILER ${PETSC_F_COMPILER})

pkg_get_variable(PETSC_C_FLAGS PETSc cflags_extra)
pkg_get_variable(PETSC_CXX_FLAGS PETSc cxxflags_extra)
pkg_get_variable(PETSC_F_FLAGS PETSc fflags_extra)

foreach(OPT ${PETSC_C_FLAGS})
    set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} ${OPT}")
endforeach()
set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} ")
foreach(OPT ${PETSC_CXX_FLAGS})
    set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} ${OPT}")
endforeach()
foreach(OPT ${PETSC_F_FLAGS})
    set(CMAKE_Fortran_FLAGS_INIT "${CMAKE_Fortran_FLAGS_INIT} ${OPT}")
endforeach()