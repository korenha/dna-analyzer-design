cmake_minimum_required(VERSION 3.15)
project(DNAAnalyzerProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(DNAAnalyzerProject Src/main.cpp Src/DNA/DnaSequence.cpp Src/Test/TestFileReader.cpp Src/Test/TestDnaSeq.cpp Src/Test/TestFileWriter.cpp Src/Reader/FileReader.cpp Src/Writer/FileWriter.cpp Src/Exception/MyException.cpp Src/GlobalFunction/globalFunctions.cpp Src/DNA/Status.cpp Src/DNA/Status.h Src/DNA/DNAMetaData.cpp Src/DNA/DNAMetaData.h Src/DNA/Nucleotide.cpp Src/DNA/Nucleotide.h Src/DNA/DNAHashTable.cpp Src/DNA/DNAHashTable.h Src/DNA/IDNAData.cpp Src/DNA/IDNAData.h Src/CML/ICommand.h Src/DNA/DNAHashTable.cpp Src/CML/ICreationCommand.h Src/CML/IParams.h Src/CML/NewCommandParsing.cpp Src/CML/NewCommandParsing.h Src/Reader/ReaderConstChar.cpp Src/Reader/ReaderConstChar.h Src/CML/NewCommand.cpp  Src/CML/NewCommand.h Src/Reader/StringReader.cpp Src/Reader/StringReader.h Src/DNA/string.cpp Src/DNA/string.h Src/DNA/DNADAta.cpp Src/DNA/DNADAta.h)