add_llvm_component_group(Lala)

# set(LLVM_TARGET_DEFINITIONS Lala.td)

# Generate C++ code from tablegen description
# to worl with registers
# tablegen(LLVM LalaGenRegisterInfo.inc -gen-register-info)
# add_public_tablegen_target(LalaCommonTableGen)

add_llvm_target(LalaCodeGen
  LalaTargetMachine.cpp
  # SimRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  LalaInfo

  ADD_TO_COMPONENT
  Lala
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
