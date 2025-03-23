include "llvm/Target/Target.td"
include "LalaRegisterInfo.td"
include "LalaInstrInfo.td"
include "LalaCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
: Processor<Name, NoItineraries, Features>;
def : Proc<"generic", []>;

def LalaInstrInfo : InstrInfo;
def Lala : Target {
  let InstructionSet = LalaInstrInfo;
}
