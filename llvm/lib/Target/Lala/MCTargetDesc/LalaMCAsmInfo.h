#ifndef LLVM_LIB_TARGET_Lala_MCTARGETDESC_LalaMCASMINFO_H
#define LLVM_LIB_TARGET_Lala_MCTARGETDESC_LalaMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class LalaELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit LalaELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_Lala_MCTARGETDESC_LalaMCASMINFO_H
