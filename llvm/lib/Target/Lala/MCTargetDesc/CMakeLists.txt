add_llvm_component_library(LLVMLalaDesc
  LalaMCTargetDesc.cpp
  LalaMCAsmInfo.cpp
  LalaInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  LalaInfo

  ADD_TO_COMPONENT
  Lala
)
