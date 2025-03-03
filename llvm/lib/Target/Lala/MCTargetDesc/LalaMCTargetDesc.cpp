#include "LalaMCTargetDesc.h"

// We need to define this function for linking succeed
extern "C" void LLVMInitializeLalaTargetMC() {int x = 0;}
