#include "LalaRegisterInfo.h"
#include "Lala.h"
#include "LalaFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "LalaGenRegisterInfo.inc"

LalaRegisterInfo::LalaRegisterInfo() : LalaGenRegisterInfo(Lala::R0) {
  Lala_DUMP_GREEN
}
const MCPhysReg *
LalaRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  Lala_DUMP_GREEN
  return CSR_Lala_SaveList;
}

BitVector LalaRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  Lala_DUMP_GREEN
  LalaFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Lala::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Lala::R2);
  }
  return Reserved;
}

bool LalaRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool LalaRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  Lala_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register LalaRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  Lala_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Lala::R2 : Lala::R1;
}

const uint32_t *
LalaRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  Lala_DUMP_GREEN
  return CSR_Lala_RegMask;
}
