#include "LalaInstrInfo.h"
#include "Lala.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "LalaGenInstrInfo.inc"

#define DEBUG_TYPE "Lala-inst-info"

LalaInstrInfo::LalaInstrInfo() : LalaGenInstrInfo() { Lala_DUMP_GREEN }
