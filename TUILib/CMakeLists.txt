# CMakeList.txt : TUILib の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#

cmake_minimum_required (VERSION 3.8)

# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable (TUILib "TUILib.cpp" "TUILib.h" "Tui.cpp" "Tui.hpp" "DiffPositions.hpp")
#target_compile_options("utf-8")

#add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
#add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
if(MSVC)
	#target_compile_options(TUILib PUBLIC "/source-charset:utf-8")
	target_compile_options(TUILib PUBLIC "/utf-8")
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TUILib PROPERTY CXX_STANDARD 20)
endif()

# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
