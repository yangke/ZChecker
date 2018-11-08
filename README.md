# ZChecker
Find missing check for attacker controlled implicit data flow.

1.Follow the instruction here[http://clang-analyzer.llvm.org/checker_dev_manual.html] to build the environment for Clang Static Analyzer.

2.Copy ZChecker.cpp to
```
llvm/tools/clang/lib/StaticAnalyzer/Checkers/
```
3.Add the following code to Checkers.td
```
def ZChecker : Checker<"ZChecker">,
  HelpText<"Find missing check of attacker controllable implicit data flow!">,
  DescFile<"ZChecker.cpp">;
```
4.Let CMake know that we add the source code `ZChecker.cpp`
```
add_clang_library(clangStaticAnalyzerCheckers
+  ZChecker.cpp
  AllocationDiagnostics.cpp
```
5.Build ZChecker.cpp into clang
```
cd llvm/build
cmake ..
make #If this is the first time to run make, it will cause you about 2 hours. Recommend you make at `llvm/build/tools/clang/` to only obtain clang executable(Will generate at `llvm/build/bin`).
```
6.Copy test directory in this repository to `llvm/build/bin` change the directory to that position then run `run_analysis.sh`.
```
cd llvm/build/bin
cp -R ZChecker/test .
cd test
./run_analysis.sh
```
If you wanna run at other directory and on different target, change the PATH specification of clang (`../clang` in ./run_analysis.sh), and substitude scan-build(`../scan-build` ./run_analysis.sh) respectively.
