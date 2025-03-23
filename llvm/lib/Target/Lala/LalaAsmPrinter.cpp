#include "MCTargetDesc/LalaInstPrinter.h"
#include "Lala.h"
#include "LalaSubtarget.h"
#include "LalaTargetMachine.h"
#include "TargetInfo/LalaTargetInfo.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {

class LalaAsmPrinter : public AsmPrinter {
  const MCSubtargetInfo *STI;

public:
  explicit LalaAsmPrinter(TargetMachine &TM,
                         std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)), STI(TM.getMCSubtargetInfo()) {
    Lala_DUMP_GREEN
  }

  void emitInstruction(const MachineInstr *MI) override;

  StringRef getPassName() const override { return "Lala Assembly Printer"; }

  bool lowerPseudoInstExpansion(const MachineInstr *MI, MCInst &Inst);

  // Used in pseudo lowerings
  bool lowerOperand(const MachineOperand &MO, MCOperand &MCOp) const {
    return LowerLalaMachineOperandToMCOperand(MO, MCOp, *this);
  }
};

} // end anonymous namespace

// Lalaple pseudo-instructions have their lowering (with expansion to real
// instructions) auto-generated.
#include "LalaGenMCPseudoLowering.inc"

void LalaAsmPrinter::emitInstruction(const MachineInstr *MI) {
  Lala_DUMP_GREEN
  // Do any auto-generated pseudo lowerings.
  if (MCInst OutInst; lowerPseudoInstExpansion(MI, OutInst)) {
    EmitToStreamer(*OutStreamer, OutInst);
    return;
  }

  MCInst TmpInst;
  if (!lowerLalaMachineInstrToMCInst(MI, TmpInst, *this))
    EmitToStreamer(*OutStreamer, TmpInst);
}

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLalaAsmPrinter() {
  RegisterAsmPrinter<LalaAsmPrinter> X(getTheLalaTarget());
}
