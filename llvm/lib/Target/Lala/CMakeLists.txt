add_llvm_component_group(Lala)

set(LLVM_TARGET_DEFINITIONS Lala.td)

# Generate C++ code from tablegen description
# to worl with registers
tablegen(LLVM LalaGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM LalaGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM LalaGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM LalaGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM LalaGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM LalaGenCallingConv.inc -gen-callingconv)
tablegen(LLVM LalaGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(LalaCommonTableGen)

add_llvm_target(LalaCodeGen
  LalaTargetMachine.cpp
  LalaRegisterInfo.cpp
  LalaInstrInfo.cpp
  LalaSubtarget.cpp
  LalaAsmPrinter.cpp
  LalaISelDagToDag.cpp
  LalaISelLowering.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  LalaInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Lala
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
