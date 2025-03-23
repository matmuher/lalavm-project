#ifndef LLVM_LIB_TARGET_Lala_MCTARGETDESC_LalaINFO_H
#define LLVM_LIB_TARGET_Lala_MCTARGETDESC_LalaINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace LalaOp {
enum OperandType : unsigned {
  OPERAND_Lala16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace LalaOp

} // end namespace llvm

#endif
