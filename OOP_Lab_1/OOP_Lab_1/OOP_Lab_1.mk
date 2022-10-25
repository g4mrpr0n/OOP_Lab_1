##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OOP_Lab_1
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/anan/Code/project2/OOP_Lab_1/OOP_Lab_1
ProjectPath            :=/home/anan/Code/project2/OOP_Lab_1/OOP_Lab_1/OOP_Lab_1
IntermediateDirectory  :=../build-$(ConfigurationName)/OOP_Lab_1
OutDir                 :=../build-$(ConfigurationName)/OOP_Lab_1
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Globa Georgeana
Date                   :=25/10/22
CodeLitePath           :=/home/anan/.codelite
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
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
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
Objects0=../build-$(ConfigurationName)/OOP_Lab_1/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/OOP_Lab_1/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/OOP_Lab_1"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/OOP_Lab_1"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/OOP_Lab_1/.d:
	@mkdir -p "../build-$(ConfigurationName)/OOP_Lab_1"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/OOP_Lab_1/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/OOP_Lab_1/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/anan/Code/project2/OOP_Lab_1/OOP_Lab_1/OOP_Lab_1/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/OOP_Lab_1/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/OOP_Lab_1/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/OOP_Lab_1/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/OOP_Lab_1/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/OOP_Lab_1/main.c$(PreprocessSuffix) main.c


-include ../build-$(ConfigurationName)/OOP_Lab_1//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


