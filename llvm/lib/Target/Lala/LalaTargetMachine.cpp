#include "LalaTargetMachine.h"
#include "Lala.h"
#include "TargetInfo/LalaTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLalaTarget() {
  // Register the target.
  SIM_DUMP_CYAN
  RegisterTargetMachine<LalaTargetMachine> A(getTheLalaTarget());
}

LalaTargetMachine::LalaTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  SIM_DUMP_CYAN
}
