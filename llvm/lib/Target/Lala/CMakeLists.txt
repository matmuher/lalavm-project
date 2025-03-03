add_llvm_component_group(Lala)

add_llvm_target(LalaCodeGen
  LalaTargetMachine.cpp

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
