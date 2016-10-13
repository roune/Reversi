##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Reversi
ConfigurationName      :=Debug
WorkspacePath          :=/home/miguel/Reversi
ProjectPath            :=/home/miguel/Reversi
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=miguel
Date                   :=02/10/16
CodeLitePath           :=/home/miguel/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Reversi.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/reversi.c$(ObjectSuffix) $(IntermediateDirectory)/bitboard.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/reversi.c$(ObjectSuffix): reversi.c $(IntermediateDirectory)/reversi.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/miguel/Reversi/reversi.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/reversi.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/reversi.c$(DependSuffix): reversi.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/reversi.c$(ObjectSuffix) -MF$(IntermediateDirectory)/reversi.c$(DependSuffix) -MM reversi.c

$(IntermediateDirectory)/reversi.c$(PreprocessSuffix): reversi.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/reversi.c$(PreprocessSuffix)reversi.c

$(IntermediateDirectory)/bitboard.c$(ObjectSuffix): bitboard.c $(IntermediateDirectory)/bitboard.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/miguel/Reversi/bitboard.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bitboard.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitboard.c$(DependSuffix): bitboard.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bitboard.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bitboard.c$(DependSuffix) -MM bitboard.c

$(IntermediateDirectory)/bitboard.c$(PreprocessSuffix): bitboard.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitboard.c$(PreprocessSuffix)bitboard.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


