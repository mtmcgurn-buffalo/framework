#include "ghost.hpp"
#include <petsc.h>
#include <utilities/petscError.hpp>

ablate::flow::boundaryConditions::Ghost::Ghost(std::string fieldName, std::string boundaryName, std::string labelName, std::vector<int> labelIds,
                                               ablate::flow::boundaryConditions::Ghost::UpdateFunction updateFunction, void *updateContext)
    : BoundaryCondition(boundaryName, fieldName), labelName(labelName), labelIds(labelIds), updateFunction(updateFunction), updateContext(updateContext) {}

ablate::flow::boundaryConditions::Ghost::Ghost(std::string fieldName, std::string boundaryName, std::string labelName, int labelId,
                                               ablate::flow::boundaryConditions::Ghost::UpdateFunction updateFunction, void *updateContext)
    : Ghost(fieldName, boundaryName, labelName, std::vector<int>{labelId}, updateFunction, updateContext) {}

void ablate::flow::boundaryConditions::Ghost::SetupBoundary(PetscDS problem, PetscInt fieldId) {
    //    PetscErrorCode PetscDSAddBoundaryByName(PetscDS ds, DMBoundaryConditionType type, const char name[], const char lname[], PetscInt Nv, const PetscInt values[], PetscInt field, PetscInt Nc,
    //    const PetscInt comps[], void (*bcFunc)(void), void (*bcFunc_t)(void), void *ctx, PetscInt *bd)
    PetscDSAddBoundaryByName(problem,
                             DM_BC_NATURAL_RIEMANN,
                             GetBoundaryName().c_str(),
                             labelName.c_str(),
                             labelIds.size(),
                             &labelIds[0],
                             fieldId,
                             0,
                             NULL,
                             (void (*)(void))updateFunction,
                             NULL,
                             (void *)updateContext,
                             NULL) >>
        checkError;

    // extract some information about the flowField
    PetscDSGetFieldSize(problem, fieldId, &fieldSize) >> checkError;
    PetscDSGetCoordinateDimension(problem, &dim) >> checkError;
}
