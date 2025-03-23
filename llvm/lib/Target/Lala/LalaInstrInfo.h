#ifndef LLVM_LIB_TARGET_Lala_LalaINSTRINFO_H
#define LLVM_LIB_TARGET_Lala_LalaINSTRINFO_H

#include "LalaRegisterInfo.h"
#include "MCTargetDesc/LalaInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "LalaGenInstrInfo.inc"

namespace llvm {

class LalaSubtarget;

class LalaInstrInfo : public LalaGenInstrInfo {
public:
  LalaInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_Lala_LalaINSTRINFO_H
