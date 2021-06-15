---
layout: default
title: Auto Generated Component List
parent: Input Files
nav_order: 3
---

## Interface: ablate::parameters::Parameters
### ablate::parameters::FactoryParameters*
Creates a parameter list based upon a factory.  Should be default for factory parsing.


## Interface: ablate::mathFunctions::MathFunction
### ablate::mathFunctions::ParsedFunction*
a string based function to be parsed with muparser

- formula(string) - the formula that may accept x, y, z, t

## Interface: ablate::mathFunctions::FieldSolution
### ablate::mathFunctions::FieldSolution*
a field description that can be used for initialization or exact solution

- fieldName(string) - the field name
- solutionField(ablate::mathFunctions::MathFunction) - the math function used to describe the field
- timeDerivative(ablate::mathFunctions::MathFunction) - OPTIONAL: the math function used to describe the field time derivative

## Interface: ablate::eos::EOS
### ablate::eos::PerfectGas
perfect gas eos

- parameters(ablate::parameters::Parameters) - parameters for the perfect gas eos

## Interface: ablate::flow::fluxDifferencer::FluxDifferencer
### ablate::flow::fluxDifferencer::AusmFluxDifferencer
AUSM Flux Spliting: "A New Flux Splitting Scheme" Liou and Steffen, pg 26, Eqn (6), 1993


### ablate::flow::fluxDifferencer::AverageFluxDifferencer
Takes the average of the left/right faces.  Only useful for debugging.


### ablate::flow::fluxDifferencer::OffFluxDifferencer
Turns of convective flux through the face.


## Interface: ablate::flow::boundaryConditions::BoundaryCondition
### ablate::flow::boundaryConditions::Essential
essential (Dirichlet condition) for FE based problems

- fieldName(string) - the field to apply the boundary condition
- boundaryName(string) - the name for this boundary condition
- labelName(string) - the mesh label holding the boundary ids
- labelIds(std::__1::vector<int, std::__1::allocator<int> >) - the ids on the mesh to apply the boundary condition
- boundaryValue(ablate::mathFunctions::MathFunction) - the math function used to describe the boundary
- timeDerivativeValue(ablate::mathFunctions::MathFunction) - OPTIONAL: the math function used to describe the field time derivative

### ablate::flow::boundaryConditions::EssentialGhost
essential (Dirichlet condition) for ghost cell based boundaries

- fieldName(string) - the field to apply the boundary condition
- boundaryName(string) - the name for this boundary condition
- labelName(string) - the mesh label holding the boundary ids
- labelIds(std::__1::vector<int, std::__1::allocator<int> >) - the ids on the mesh to apply the boundary condition
- boundaryValue(ablate::mathFunctions::MathFunction) - the math function used to describe the boundary

## Interface: ablate::flow::Flow
### ablate::flow::LowMachFlow
incompressible FE flow

- name(string) - the name of the flow field
- mesh(ablate::mesh::Mesh) - the mesh
- parameters(ablate::parameters::Parameters) - the flow field parameters
- options(ablate::parameters::Parameters) - OPTIONAL: options for the flow passed directly to PETSc
- initialization(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - the solution used to initialize the flow field
- boundaryConditions(std::__1::vector<ablate::flow::boundaryConditions::BoundaryCondition, std::__1::allocator<ablate::flow::boundaryConditions::BoundaryCondition> >) - the boundary conditions for the flow field
- auxFields(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - enables and sets the update functions for the auxFields
- exactSolution(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - OPTIONAL: optional exact solutions that can be used for error calculations

### ablate::flow::IncompressibleFlow
incompressible FE flow

- name(string) - the name of the flow field
- mesh(ablate::mesh::Mesh) - the mesh
- parameters(ablate::parameters::Parameters) - the flow field parameters
- options(ablate::parameters::Parameters) - OPTIONAL: options for the flow passed directly to PETSc
- initialization(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - the solution used to initialize the flow field
- boundaryConditions(std::__1::vector<ablate::flow::boundaryConditions::BoundaryCondition, std::__1::allocator<ablate::flow::boundaryConditions::BoundaryCondition> >) - the boundary conditions for the flow field
- auxFields(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - OPTIONAL: enables and sets the update functions for the auxFields
- exactSolution(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - OPTIONAL: optional exact solutions that can be used for error calculations

### ablate::flow::CompressibleFlow
compressible finite volume flow

- name(string) - the name of the flow field
- mesh(ablate::mesh::Mesh) - the  mesh and discretization
- eos(ablate::eos::EOS) - the equation of state used to describe the flow
- parameters(ablate::parameters::Parameters) - the compressible flow parameters cfl, gamma, etc.
- fluxDifferencer(ablate::flow::fluxDifferencer::FluxDifferencer) - OPTIONAL: the flux differencer (defaults to AUSM)
- options(ablate::parameters::Parameters) - OPTIONAL: the options passed to PETSc
- initialization(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - OPTIONAL: the flow field initialization
- boundaryConditions(std::__1::vector<ablate::flow::boundaryConditions::BoundaryCondition, std::__1::allocator<ablate::flow::boundaryConditions::BoundaryCondition> >) - OPTIONAL: the boundary conditions for the flow field
- exactSolution(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - OPTIONAL: optional exact solutions that can be used for error calculations

## Interface: ablate::mesh::Mesh
### ablate::mesh::BoxMesh
simple uniform box mesh

- name(string) - the name of the domain/mesh object
- faces(std::__1::vector<int, std::__1::allocator<int> >) - the number of faces in each direction
- lower(std::__1::vector<double, std::__1::allocator<double> >) - the lower bound of the mesh
- upper(std::__1::vector<double, std::__1::allocator<double> >) - the upper bound of the mesh
- boundary(std::__1::vector<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, std::__1::allocator<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > > >) - OPTIONAL: custom boundary types (NONE, GHOSTED, MIRROR, PERIODIC)
- simplex(bool) - OPTIONAL: sets if the elements/cells are simplex
- options(ablate::parameters::Parameters) - OPTIONAL: any PETSc options

## Interface: ablate::solve::TimeStepper
### ablate::solve::TimeStepper*
the basic stepper

- name(string) - the time stepper name
- arguments(argument map) - arguments to be passed to petsc

## Interface: ablate::monitors::Monitor
### ablate::monitors::Hdf5Monitor
writes the viewable object to an hdf5

- interval(int) - how often to write the HDF5 file (default is every timestep)

### ablate::monitors::ErrorMonitor
Computes and reports the error every time step


### ablate::monitors::TimeStepMonitor
Reports the current step, time, and dt


## Interface: ablate::particles::initializers::Initializer
### ablate::particles::initializers::CellInitializer
simple cell initializer that puts particles in every element

- particlesPerCellPerDim(int) - particles per cell per dimension

### ablate::particles::initializers::BoxInitializer
simple box initializer that puts particles in a defined box

- lower(std::__1::vector<double, std::__1::allocator<double> >) - the lower bound of the box
- upper(std::__1::vector<double, std::__1::allocator<double> >) - the upper bound of the box
- particlesPerDim(int) - the particles per box dimension

## Interface: ablate::particles::Particles
### ablate::particles::Tracer
massless particles that advect with the flow

- name(string) - the name of the particle group
- ndims(int) - the number of dimensions for the particle
- initializer(ablate::particles::initializers::Initializer) - the initial particle setup methods
- exactSolution(ablate::mathFunctions::MathFunction) - OPTIONAL: the particle location exact solution
- options(ablate::parameters::Parameters) - options to be passed to petsc

### ablate::particles::Inertial
particles (with mass) that advect with the flow

- name(string) - the name of the particle group
- ndims(int) - the number of dimensions for the particle
- parameters(ablate::parameters::Parameters) - fluid parameters for the particles (fluidDensity, fluidViscosity, gravityField)
- initializer(ablate::particles::initializers::Initializer) - the initial particle setup methods
- fieldInitialization(std::__1::vector<ablate::mathFunctions::FieldSolution, std::__1::allocator<ablate::mathFunctions::FieldSolution> >) - the initial particle fields setup methods
- exactSolution(ablate::mathFunctions::MathFunction) - OPTIONAL: the particle location/velocity exact solution
- options(ablate::parameters::Parameters) - options to be passed to petsc
