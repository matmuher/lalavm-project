#include "TargetInfo/LalaTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "Lala.h"
using namespace llvm;

Target &llvm::getTheLalaTarget() {
  Lala_DUMP_YELLOW
  static Target TheLalaTarget;
  return TheLalaTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLalaTargetInfo() {
  Lala_DUMP_YELLOW
  RegisterTarget<Triple::Lala> X(getTheLalaTarget(), "Lala", "Lala (edu-target), 32",
                                   "Lala");
}
