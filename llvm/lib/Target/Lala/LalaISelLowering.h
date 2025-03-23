#ifndef LLVM_LIB_TARGET_Lala_LalaISELLOWERING_H
#define LLVM_LIB_TARGET_Lala_LalaISELLOWERING_H

#include "Lala.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class LalaSubtarget;
class LalaTargetMachine;

// ISD - instr select dag
namespace LalaISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace LalaISD

class LalaTargetLowering : public TargetLowering {
public:
  explicit LalaTargetLowering(const TargetMachine &TM, const LalaSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  LalaSubtarget const &getSubtarget() const { return STI; }

private:
  const LalaSubtarget &STI;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_Lala_LalaISELLOWERING_H
