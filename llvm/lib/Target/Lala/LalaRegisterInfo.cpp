#include "LalaRegisterInfo.h"
#include "Lala.h"
#include "LalaFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "LalaGenRegisterInfo.inc"

LalaRegisterInfo::LalaRegisterInfo() : LalaGenRegisterInfo(Lala::R0) {
  Lala_DUMP_GREEN
}
