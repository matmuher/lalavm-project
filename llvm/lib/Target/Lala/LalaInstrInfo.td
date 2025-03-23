//===----------------------------------------------------------------------===//
// Lala profiles and nodes
//===----------------------------------------------------------------------===//

def Lala_ret      : SDNode<"LalaISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "LalaInstrFormats.td"

//===----------------------------------------------------------------------===//
// Lala Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class LalaAsmOperand<int width> : AsmOperandClass {
  let Name = "Lala" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def Lala16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = LalaAsmOperand<16>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeLalaOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_Lala16";
  let OperandNamespace = "LalaOp";
}

//===----------------------------------------------------------------------===//
// Lala Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1 in
def BR : LalaInst<0x0, (outs), (ins GPR:$rs1), "BR $rs1",
                  [(brind GPR:$rs1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : LalaPseudoInst<(outs), (ins), "# PseudoRET",
                [(Lala_ret)]>,
                PseudoInstExpansion<(BR R0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1 in
def MOVLI : LalaInst<0x0, (outs GPR:$rd), (ins Lala16:$imm),
                     "MOVli $rd $imm",
                     [(set GPR:$rd, Lala16:$imm)]>;
