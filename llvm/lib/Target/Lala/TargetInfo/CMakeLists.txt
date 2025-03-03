add_llvm_component_library(LLVMLalaInfo
  LalaTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Lala
  )
