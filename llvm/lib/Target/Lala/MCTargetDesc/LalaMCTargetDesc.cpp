#include "MCTargetDesc/LalaInfo.h"
#include "Lala.h"
#include "LalaInstPrinter.h"
#include "LalaMCAsmInfo.h"
#include "TargetInfo/LalaTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "LalaGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "LalaGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "LalaGenSubtargetInfo.inc"

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

static MCSubtargetInfo *createLalaMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  Lala_DUMP_MAGENTA
  return createLalaMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createLalaMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  Lala_DUMP_MAGENTA
  MCAsmInfo *MAI = new LalaELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Lala::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createLalaMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  Lala_DUMP_MAGENTA
  return new LalaInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLalaTargetMC() {
  Lala_DUMP_MAGENTA
  Target &TheLalaTarget = getTheLalaTarget();
  RegisterMCAsmInfoFn X(TheLalaTarget, createLalaMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheLalaTarget, createLalaMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheLalaTarget, createLalaMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheLalaTarget,
                                          createLalaMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheLalaTarget, createLalaMCInstPrinter);
}
