#include "LalaISelLowering.h"
#include "Lala.h"
#include "LalaRegisterInfo.h"
#include "LalaSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "Lala-lower"

using namespace llvm;

LalaTargetLowering::LalaTargetLowering(const TargetMachine &TM,
                                     const LalaSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  Lala_DUMP_RED
  addRegisterClass(MVT::i32, &Lala::GPRRegClass);
}

const char *LalaTargetLowering::getTargetNodeName(unsigned Opcode) const {
  Lala_DUMP_RED
  switch (Opcode) {
  case LalaISD::CALL:
    return "LalaISD::CALL";
  case LalaISD::RET:
    return "LalaISD::RET";
  }
  return nullptr;
}
