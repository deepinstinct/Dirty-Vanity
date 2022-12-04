#pragma once


#define  UNLOAD(x,cur,flag) {\
while (cur != NULL && cur != &pLdrData->InMemoryOrderModuleList && flag) \
{\
  thisEntry = CONTAINING_RECORD(cur, LDR_DATA_TABLE_ENTRYEX, InMemoryOrderLinks); \
  thisEntry->DdagNode->LoadCount = 1;\
  thisEntry->DdagNode->LoadWhileUnloadingCount = 0;\
  if (thisEntry->DllBase == [x])\
  {\
    thisEntry->DdagNode->LoadCount = 1;\
    thisEntry->DdagNode->LoadWhileUnloadingCount = 0;\
    thisEntry->ReferenceCount = 1;\
    thisEntry->DdagNode->IncomingDependencies.Tail = 0;\
    flag = FALSE;\
  }\
  cur = cur->Flink;\
}\
st = pLdrUnloadDll(x);\
}
