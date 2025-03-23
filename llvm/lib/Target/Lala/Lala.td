include "llvm/Target/Target.td"
include "LalaRegisterInfo.td"
include "LalaInstrInfo.td"

def LalaInstrInfo : InstrInfo;
def Lala : Target {
  let InstructionSet = LalaInstrInfo;
}
