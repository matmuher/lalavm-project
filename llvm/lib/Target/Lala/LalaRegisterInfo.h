#ifndef LLVM_LIB_TARGET_Lala_LalaREGISTERINFO_H
#define LLVM_LIB_TARGET_Lala_LalaREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "LalaGenRegisterInfo.inc"

namespace llvm {

struct LalaRegisterInfo : public LalaGenRegisterInfo {
public:
  LalaRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_Lala_LalaREGISTERINFO_H
