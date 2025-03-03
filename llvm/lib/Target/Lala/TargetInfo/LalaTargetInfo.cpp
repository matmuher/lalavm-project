#include "TargetInfo/LalaTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheLalaTarget() {
  static Target TheLalaTarget;
  return TheLalaTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLalaTargetInfo() {
  RegisterTarget<Triple::Lala> X(getTheLalaTarget(), "Lala", "Lala 32",
                                   "Lala");
}
