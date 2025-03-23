#include "MCTargetDesc/LalaInfo.h"
#include "Lala.h"
#include "TargetInfo/LalaTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "LalaGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "LalaGenInstrInfo.inc"

static MCRegisterInfo *createLalaMCRegisterInfo(const Triple &TT) {
  Lala_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitLalaMCRegisterInfo(X, Lala::R0);
  return X;
}

static MCInstrInfo *createLalaMCInstrInfo() {
  Lala_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitLalaMCInstrInfo(X);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLalaTargetMC() {
  Lala_DUMP_MAGENTA
  Target &TheLalaTarget = getTheLalaTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheLalaTarget, createLalaMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheLalaTarget, createLalaMCInstrInfo);
}
