#include "LalaSubtarget.h"
#include "Lala.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "Lala-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "LalaGenSubtargetInfo.inc"

LalaSubtarget::LalaSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : LalaGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  Lala_DUMP_CYAN
}
