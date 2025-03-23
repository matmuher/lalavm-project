#ifndef LLVM_LIB_TARGET_Lala_LalaTARGETMACHINE_H
#define LLVM_LIB_TARGET_Lala_LalaTARGETMACHINE_H

#include "LalaSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheLalaTarget;

class LalaTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  LalaSubtarget Subtarget;

public:
  LalaTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const LalaSubtarget *getSubtargetImpl(const Function &) const override {
    Lala_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_Lala_LalaTARGETMACHINE_H
