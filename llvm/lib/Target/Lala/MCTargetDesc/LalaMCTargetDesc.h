#ifndef LLVM_LIB_TARGET_Lala_MCTARGETDESC_LalaMCTARGETDESC_H
#define LLVM_LIB_TARGET_Lala_MCTARGETDESC_LalaMCTARGETDESC_H

// Defines symbolic names for Lala registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "LalaGenRegisterInfo.inc"

// Defines symbolic names for the Lala instructions.
#define GET_INSTRINFO_ENUM
#include "LalaGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_Lala_MCTARGETDESC_LalaMCTARGETDESC_H
